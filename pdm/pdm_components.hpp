//
// Created by Mike Yang on 11/21/2022.
//

#include "imgui.h"
#include <nfd.h>
#include "pdm_database.h"
#include "pdm.h"
#include "empp.h"

// STATIC
namespace PDM::Components {
  bool file_menu(PDM::Runtime* rt){
    if (ImGui::BeginMenu("Files"))
    {
      if(ImGui::MenuItem("Open", "")){
        NFD_Init();

        nfdchar_t *outPath;
        nfdfilteritem_t filterItem[1] = {  };
        nfdresult_t result = NFD_OpenDialog(&outPath, filterItem, 0, NULL);
        if (result == NFD_OKAY)
        {
          puts("Success!");
          puts(outPath);
          NFD_FreePath(outPath);
        }
        else if (result == NFD_CANCEL)
        {
          puts("User pressed cancel.");
        }
        else
        {
          printf("Error: %s\n", NFD_GetError());
        }

        NFD_Quit();
      } // Open Button
      ImGui::EndMenu();
    }
    return true;
  }

  bool debug_menu(PDM::Runtime* rt){
    if (ImGui::BeginMenu("Debug"))
    {
      if(ImGui::BeginMenu("Database")){
        if(ImGui::MenuItem("Open \".sqlite\" File", "")){
          NFD_Init();

          nfdchar_t *outPath;
          nfdfilteritem_t filterItem[1] = {  };
          nfdresult_t result = NFD_OpenDialog(&outPath, filterItem, 0, NULL);
          if (result == NFD_OKAY)
          {
            puts(outPath);
            rt->ui->database_current_file_path = "file:///";
            rt->ui->database_current_file_path += outPath;
//            rt->db->open_db(rt->ui->database_current_file_path.data());
            NFD_FreePath(outPath);
          }
          else if (result == NFD_CANCEL)
          {
            puts("User pressed cancel.");
          }
          else
          {
            printf("Error: %s\n", NFD_GetError());
          }
          NFD_Quit();
        } // open .sqlite file Button
        ImGui::EndMenu();
      } // Database menu
      ImGui::EndMenu();
    } // debug menu
    return true;
  }

  bool tree_view() {
    static ImGuiTableFlags flags =
        ImGuiTableFlags_BordersV | ImGuiTableFlags_BordersOuterH | ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg |
        ImGuiTableFlags_NoBordersInBody;

    if (ImGui::BeginTable("3ways", 3, flags)) {
// The first column will use the default _WidthStretch when ScrollX is Off and _WidthFixed when ScrollX is On
      ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_NoHide);
      float TEXT_BASE_WIDTH = 1;
      ImGui::TableSetupColumn("Size", ImGuiTableColumnFlags_WidthFixed, TEXT_BASE_WIDTH = 1 * 12.0f);
      ImGui::TableSetupColumn("Type", ImGuiTableColumnFlags_WidthFixed, TEXT_BASE_WIDTH = 1 * 18.0f);
      ImGui::TableHeadersRow();

// Simple storage to output a dummy file-system.
      struct MyTreeNode {
        const char *Name;
        const char *Type;
        int Size;
        int ChildIdx;
        int ChildCount;

        static void DisplayNode(const MyTreeNode *node, const MyTreeNode *all_nodes) {
          ImGui::TableNextRow();
          ImGui::TableNextColumn();
          const bool is_folder = (node->ChildCount > 0);
          if (is_folder) {
            bool open = ImGui::TreeNodeEx(node->Name, ImGuiTreeNodeFlags_SpanFullWidth);
            ImGui::TableNextColumn();
            ImGui::TextDisabled("--");
            ImGui::TableNextColumn();
            ImGui::TextUnformatted(node->Type);
            if (open) {
              for (int child_n = 0; child_n < node->ChildCount; child_n++)
                DisplayNode(&all_nodes[node->ChildIdx + child_n], all_nodes);
              ImGui::TreePop();
            }
          } else {
            ImGui::TreeNodeEx(node->Name, ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_Bullet |
                                          ImGuiTreeNodeFlags_NoTreePushOnOpen | ImGuiTreeNodeFlags_SpanFullWidth);
            ImGui::TableNextColumn();
            ImGui::Text("%d", node->Size);
            ImGui::TableNextColumn();
            ImGui::TextUnformatted(node->Type);
          }
        }
      };
      static const MyTreeNode nodes[] =
          {
              {"Root",                          "Folder",      -1,     1,  3}, // 0
              {"Music",                         "Folder",      -1,     4,  2}, // 1
              {"Textures",                      "Folder",      -1,     6,  3}, // 2
              {"desktop.ini",                   "System file", 1024,   -1, -1}, // 3
              {"File1_a.wav",                   "Audio file",  123000, -1, -1}, // 4
              {"File1_b.wav",                   "Audio file",  456000, -1, -1}, // 5
              {"Image001.png",                  "Image file",  203128, -1, -1}, // 6
              {"Copy of Image001.png",          "Image file",  203256, -1, -1}, // 7
              {"Copy of Image001 (Final2).png", "Image file",  203512, -1, -1}, // 8
          };

      MyTreeNode::DisplayNode(&nodes[0], nodes);

      ImGui::EndTable();
    }
//    ImGui::TreePop();
    return true;
  }

  bool database_viewer (PDM::Runtime* rt) {
    static ImGuiTableFlags flags = ImGuiTableFlags_ScrollX |ImGuiTableFlags_ScrollY |
        ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersV |
        ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable;
    static int freeze_cols = 1;
    static int freeze_rows = 1;
    static int table_width = rt->db->current_display_table.argc;
    static size_t table_size = rt->db->current_display_table.argv.size();
    ImVec2 outer_size = ImVec2(0.0f, ImGui::GetTextLineHeightWithSpacing() * 8);
    if (ImGui::BeginTable("table_scrollx", rt->db->current_display_table.argc, flags, outer_size))
    {
      ImGui::TableSetupScrollFreeze(freeze_cols, freeze_rows);
      for (int i=0;i<table_width;i++){
        ImGui::TableSetupColumn(rt->db->current_display_table.col_name[i].c_str());
      }
//      ImGui::TableSetupColumn("Line #", ImGuiTableColumnFlags_NoHide); // Make the first column not hideable to match our use of TableSetupScrollFreeze()
      ImGui::TableHeadersRow();
      for (int row = 0; row < table_size; row++)
      {
        ImGui::TableNextRow();
        for (int column = 0; column < table_width; column++)
        {
          // Both TableNextColumn() and TableSetColumnIndex() return true when a column is visible or performing width measurement.
          // Because here we know that:
          // - A) all our columns are contributing the same to row height
          // - B) column 0 is always visible,
          // We only always submit this one column and can skip others.
          // More advanced per-column clipping behaviors may benefit from polling the status flags via TableGetColumnFlags().
          if (!ImGui::TableSetColumnIndex(column) && column > 0)
            continue;
          ImGui::Text("%s", rt->db->current_display_table.argv[row][column].c_str());
        }
      }
      ImGui::EndTable();
    }

    return true;
  }

  bool database_view ( PDM::Runtime* rt){

    static char buf1[2048] = "pdm";
    static char input[2048] = "", pas[2048]="1234";
    ImGui::Begin("Database debug");
    ImGui::Text("Database status: ");
    ImGui::SameLine();
    ImGui::Text(rt->db->text_status());
    ImGui::Text("Database opened: ");
    ImGui::SameLine();
    ImGui::Text(rt->ui->database_current_file_path.data());

    ImGui::InputText("Database Name", buf1, 2048, ImGuiInputTextFlags_CharsNoBlank);
    ImGui::InputText("Password",    pas, 2048, 0);
    if (ImGui::Button("Open Database")) {
      rt->db->open_db(buf1,pas, strlen(pas));
      rt->ui->database_current_file_path = buf1;
    }
    ImGui::SameLine();
    if (ImGui::Button("Close Database")) {
      rt->db->close_db(buf1);
    }

    if (ImGui::TreeNode("Other Options")) {

      if (ImGui::Button("Open Database Viewer")) {
        rt->toggle_database_debug_window();
      }
      ImGui::TreePop();
    }
    if(ImGui::IsWindowFocused())
      ImGui::Text("Has focus");
    else
      ImGui::Text("No focus");

    // Execute
    static int enter_count = 0;
    ImGui::Text("Length: %d",strlen(input));
    ImGui::InputText("Command",    input, 2048, 0);
    if (ImGui::IsWindowFocused()&&ImGui::IsKeyReleased(ImGuiKey_Enter) ) {
      if (strlen(input)!=0)
        rt->db->execute(input);
      enter_count++;
    }
    // Keyboard actions
    ImGui::Text("Executed #%d: \"%s\"",enter_count,rt->db->last_command.data());

    if(ImGui::Button("Execute SQL Command")){
      rt->db->execute(input);
    }
    ImGui::SameLine();
    if(ImGui::Button("Clear")){
      input[0] = '\0';
    }

    // Errors
    if (rt->db->zErrMsg) {
      ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "Error: ");
      ImGui::PushTextWrapPos();
      ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), rt->db->zErrMsg);
      ImGui::PopTextWrapPos();
    }


    ImGui::End();

    // Children windows
    if (rt->ui->has_database_debug_window){
      ImGui::Begin("Database viewer");
      database_viewer(rt);
      ImGui::End();
    }

    return true;
  }


  bool crypto_test(PDM::Runtime* rt){
    std::string input, ps;
    static std::string  s_ps, enc, dec;

    const int max_input = 4096;
    static char input_buf[max_input+1], ps_buf[max_input+1];

    ImGui::Text("Input: ");
    ImGui::SameLine(150);
    ImGui::Text(input_buf);
    ImGui::Text("Password: ");
    ImGui::SameLine(150);
    ImGui::Text(ps_buf);
    ImGui::Text("Password Scrypt: ");
    ImGui::SameLine(150);
    ImGui::Text(s_ps.c_str());
    ImGui::Text("Output: ");
    ImGui::SameLine(150);
    ImGui::Text(enc.c_str());
    ImGui::Text("Output Decrypted: ");
    ImGui::SameLine(150);
    ImGui::Text(dec.c_str());

    ImGui::InputText("Input",    input_buf, max_input, 0);
    ImGui::InputText("Password",    ps_buf, max_input, 0);

    if(ImGui::Button("Done") || (ImGui::IsWindowFocused()&&ImGui::IsKeyReleased(ImGuiKey_Enter) )){
      ps = ps_buf;
      input = input_buf;
      s_ps = scrypt(ps);
      enc = checker_in(s_ps, input);
      dec = checker_out(s_ps, enc);
    }
    return true;
  }

} // PDM::Components