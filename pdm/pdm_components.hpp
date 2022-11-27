//
// Created by Mike Yang on 11/21/2022.
//

#include "imgui.h"
#include <nfd.h>
#include "pdm_database.h"
#include "pdm.h"

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
      }
      ImGui::EndMenu();
    }
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

  bool database_view ( PDM::Runtime* rt){

    static char buf1[2048] = "pdm";
    static char input[2048] = "";
    ImGui::Begin("Database debug");
    ImGui::Text("Database status: ");
    ImGui::SameLine();
    ImGui::Text(rt->db->text_status());

    if(ImGui::Button("Open Database")){
      rt->db->open_db(buf1);
    }
    ImGui::SameLine();
    if(ImGui::Button("Close Database")){
      rt->db->close_db(buf1);
    }
    ImGui::InputText("Database Name",    buf1, 2048, ImGuiInputTextFlags_CharsNoBlank);

    if(ImGui::Button("Open Database Viewer")){
      rt->toggle_database_debug_window();
    }

    // Execute
    ImGui::InputText("Command",    input, 2048, 0);
    if(ImGui::Button("Execute SQL Command")){
      rt->db->execute(input);
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
    if (rt->ui.has_database_debug_window){
      ImGui::Begin("Database viewer");
      ImGui::End();
    }

    return true;
  }

} // PDM::Components