//
// Created by Mike Yang on 11/21/2022.
//

#include "imgui.h"
#include "pdm_platforms_ui/pdm/lib/nativefiledialog-extended/src/include/nfd.h"
#include "pdm_platforms_ui/pdm/handler/pdm_database.h"
#include "pdm.h"

#include "empp.h"
#include "cc20_multi.h"
#include "misc/base64.h"
#include "themes/pdm_colors.h"

// STATIC
namespace PDM::Components {

  bool files_tree_view() {
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

  bool database_viewer(PDM::Runtime *rt) {
    static ImGuiTableFlags flags = ImGuiTableFlags_ScrollX | ImGuiTableFlags_ScrollY |
                                   ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersV |
                                   ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable;
    static int freeze_cols = 1;
    static int freeze_rows = 1;
    static int table_width = 0;
    table_width = rt->db->current_display_table.argc;
    if (table_width <= 0) {
      ImGui::Text("No data available");
      return true;
    }
    static size_t table_size = 0;
    table_size = rt->db->current_display_table.argv.size();
    static int head_loc = -1;
    if (ImGui::BeginTable("table_scrollx", rt->db->current_display_table.argc, flags)) {
      ImGui::TableSetupScrollFreeze(freeze_cols, freeze_rows);
      for (int i = 0; i < table_width; i++) {
        if (i == 0)
          ImGui::TableSetupColumn(rt->db->current_display_table.col_name[i].c_str(), ImGuiTableColumnFlags_NoHide);
        else
          ImGui::TableSetupColumn(rt->db->current_display_table.col_name[i].c_str());
        if (!strcmp(rt->db->current_display_table.col_name[i].c_str(), "head")) {
          head_loc = i;
        }
      }
      ImGui::TableHeadersRow();
      for (int row = 0; row < table_size; row++) {
        ImGui::TableNextRow();
        for (int column = 0; column < table_width; column++) {
          if (!ImGui::TableSetColumnIndex(column) && column > 0)
            continue;
          char cell_name[32];
          sprintf(cell_name, "##Database Viewer %d %d", row, column);
          ImGui::PushItemWidth(-1);
          // push color on odd number
          if (row % 2)
            ImGui::PushStyleColor(ImGuiCol_FrameBg, ImGui::ColorConvertU32ToFloat4(PDM::THEME::COLOR::Dark::GRAY200));
          ImGui::InputText(cell_name, (char *) rt->db->current_display_table.argv[row][column].c_str(),
                           rt->db->current_display_table.argv[row][column].size());
          if (row % 2)ImGui::PopStyleColor(); // pop color
          ImGui::PopItemWidth();
        }
      }
      ImGui::EndTable();
    }
    return true;
  }

  bool database_view(PDM::Runtime *rt) {

    static char buf1[2048] = "pdm";
    static char input[2048] = "", pas[2048] = "1234", back_ground_q[30] = "select * from sqlite_schema;";
    ImGui::Begin("Database debug", &rt->ui->has_database_debug_window);
    ImGui::Text("Database status: ");
    ImGui::SameLine();
    ImGui::Text(rt->db->text_status());
    ImGui::Text("Database opened: ");
    ImGui::SameLine();
    ImGui::Text(rt->ui->database_current_file_path.data());

    ImGui::InputText("Database Name", buf1, 2048, ImGuiInputTextFlags_CharsNoBlank);
    ImGui::InputText("Password", pas, 2048, 0);
    ImGui::Text("Password length: %d", strlen(pas));
    if (ImGui::Button("Open Database")) {
      rt->db->open_db(buf1, pas, strlen(pas));
      rt->ui->database_current_file_path = buf1;
    }
    ImGui::SameLine();
    if (ImGui::Button("Close Database")) {
      rt->db->close_db(buf1);
    }
    ImGui::SameLine();

    if (ImGui::Button("Open Database Viewer")) {
      rt->toggle_database_debug_window();
    }

    if (ImGui::Button("Get All Tables")) {
      rt->db->execute(back_ground_q);
    }

    if (ImGui::IsWindowFocused())
      ImGui::Text("Has focus");
    else
      ImGui::Text("No focus");

    // Execute
    static int enter_count = 0;
    ImGui::Text("Length: %d", strlen(input));
    ImGui::InputText("Command", input, 2048, 0);
    if (ImGui::IsWindowFocused() && ImGui::IsKeyReleased(ImGuiKey_Enter)) {
      if (strlen(input) != 0)
        rt->db->execute(input);
      enter_count++;
    }
    // Keyboard actions
    ImGui::Text("Executed #%d: \"%s\"", enter_count, rt->db->last_command.data());

    if (ImGui::Button("Execute SQL Command")) {
      rt->db->execute(input);
    }
    ImGui::SameLine();
    if (ImGui::Button("Clear")) {
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
    if (rt->ui->has_database_debug_window) {
      ImGui::Begin("Database viewer", &rt->ui->database_viewer_closable);
      database_viewer(rt);
      ImGui::End();
    }

    return true;
  }


  // Signin pop up
  bool signin_popup(PDM::Runtime *rt) {
    if (ImGui::Button("Stacked modals.."))
      ImGui::OpenPopup("Stacked 1");
    if (ImGui::BeginPopupModal("Stacked 1", NULL, ImGuiWindowFlags_MenuBar)) {
      if (ImGui::BeginMenuBar()) {
        if (ImGui::BeginMenu("File")) {
          if (ImGui::MenuItem("Some menu item")) {}
          ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
      }
      ImGui::Text("Hello from Stacked The First\nUsing style.Colors[ImGuiCol_ModalWindowDimBg] behind it.");

      // Testing behavior of widgets stacking their own regular popups over the modal.
      static int item = 1;
      static float color[4] = {0.4f, 0.7f, 0.0f, 0.5f};
      ImGui::Combo("Combo", &item, "aaaa\0bbbb\0cccc\0dddd\0eeee\0\0");
      ImGui::ColorEdit4("color", color);

      if (ImGui::Button("Add another modal.."))
        ImGui::OpenPopup("Stacked 2");

      // Also demonstrate passing a bool* to BeginPopupModal(), this will create a regular close button which
      // will close the popup. Note that the visibility state of popups is owned by imgui, so the input value
      // of the bool actually doesn't matter here.
      bool unused_open = true;
      if (ImGui::BeginPopupModal("Stacked 2", &unused_open)) {
        ImGui::Text("Hello from Stacked The Second!");
        if (ImGui::Button("Close"))
          ImGui::CloseCurrentPopup();
        ImGui::EndPopup();
      }

      if (ImGui::Button("Close"))
        ImGui::CloseCurrentPopup();
      ImGui::EndPopup();
    }
    return true;
  }

  bool crypto_test(PDM::Runtime *rt) {
    std::string input, ps;
    {
      ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_None;
      if (ImGui::BeginTabBar("EncryptionTabBar", tab_bar_flags)) {
        if (ImGui::BeginTabItem("Basic Encryption")) {
          static std::string s_ps, enc, dec;
          const int max_input = 4096;
          static char input_buf[max_input + 1], ps_buf[max_input + 1];
          ImGui::Text("Input: ");
          ImGui::SameLine(150);
          ImGui::SingleLineSelectableText("##Outputinput_buf", input_buf, strlen(input_buf));

          ImGui::Text("Password: ");
          ImGui::SameLine(150);
          ImGui::SingleLineSelectableText("##OutputPassword", ps_buf, strlen(ps_buf));

          ImGui::Text("Password Scrypt: ");
          ImGui::SameLine(150);
          ImGui::SingleLineSelectableText("##OutputScrypt", (char *) s_ps.c_str(), s_ps.size());

          ImGui::Text("Output: ");
          ImGui::SameLine(150);
          ImGui::SingleLineSelectableText("##Outputenc", (char *) enc.c_str(), enc.size());

          ImGui::Text("Output Decrypted: ");
          ImGui::SameLine(150);
          ImGui::SingleLineSelectableText("##Outputdec", (char *) dec.c_str(), dec.size());


          ImGui::InputText("Input", input_buf, max_input, 0);
          ImGui::InputText("Password", ps_buf, max_input, 0);
          if (ImGui::Button("Done") || (ImGui::IsWindowFocused() && ImGui::IsKeyReleased(ImGuiKey_Enter))) {
            ps = ps_buf;
            input = input_buf;
            s_ps = scrypt(ps);
            enc = checker_in(s_ps, input);
            dec = checker_out(s_ps, enc);
          }
          ImGui::EndTabItem();
          // End Basic Encryption
        }
        if (ImGui::BeginTabItem("Hash & Scrypt")) {
          static std::string s_ps, hash, d_hash, i_buf;
          const int max_input = 4096;
          static char input_buf[max_input + 1], ps_buf[max_input + 1];

          ImGui::Text("Scrypt: ");
          ImGui::SameLine(150);
          ImGui::SingleLineSelectableText("##OutputScrypt", (char *) s_ps.c_str(), s_ps.size());

          ImGui::Text("SHA3-hash: ");
          ImGui::SameLine(150);
          ImGui::SingleLineSelectableText("##OutputHash", (char *) hash.c_str(), hash.size());

          ImGui::Text("Double SHA3-hash: ");
          ImGui::SameLine(150);
          ImGui::SingleLineSelectableText("##OutputDHash", (char *) d_hash.c_str(), d_hash.size());

          ImGui::InputText("Input", input_buf, max_input, 0);
          if (ImGui::Button("Done") || (ImGui::IsWindowFocused() && ImGui::IsKeyReleased(ImGuiKey_Enter))) {
            i_buf = input_buf;
            s_ps = scrypt(i_buf);
            hash = get_hash(i_buf);
            d_hash = get_hash(i_buf + i_buf);
          }
          ImGui::EndTabItem();
          // End Hash & Scrypt
        }
        if (ImGui::BeginTabItem("Encryption Embedded")) {
          static std::string s_ps, enc, dec;
          const int max_input = 4096;
          static char input_buf[max_input + 1], ps_buf[max_input + 1];
          ImGui::Text("Input: ");
          ImGui::SameLine(150);
          ImGui::SingleLineSelectableText("##Outputinput_buf", input_buf, strlen(input_buf));

          ImGui::Text("Password: ");
          ImGui::SameLine(150);
          ImGui::SingleLineSelectableText("##OutputPassword", ps_buf, strlen(ps_buf));

          ImGui::Text("Password Scrypt: ");
          ImGui::SameLine(150);
          ImGui::SingleLineSelectableText("##OutputScrypt", (char *) s_ps.c_str(), s_ps.size());

          ImGui::Text("Output: ");
          ImGui::SameLine(150);
          ImGui::SingleLineSelectableText("##Outputenc", (char *) enc.c_str(), enc.size());

          ImGui::Text("Output Decrypted: ");
          ImGui::SameLine(150);
          ImGui::SingleLineSelectableText("##Outputdec", (char *) dec.c_str(), dec.size());


          ImGui::InputText("Input", input_buf, max_input, 0);
          ImGui::InputText("Password", ps_buf, max_input, 0);
          if (ImGui::Button("Done") || (ImGui::IsWindowFocused() && ImGui::IsKeyReleased(ImGuiKey_Enter))) {
            ps = ps_buf;
            input = input_buf;
            s_ps = ps_buf;
            enc = loader_check(s_ps, input);
            dec = loader_out(s_ps, enc);
          }
          ImGui::EndTabItem();
          // Encryption Embedded
        }
        if (ImGui::BeginTabItem("Decrypt Only Embedded")) {
          static std::string s_ps, dec;
          const int max_input = 4096;
          static char input_buf[max_input + 1], ps_buf[max_input + 1];
          ImGui::Text("Input: ");
          ImGui::SameLine(150);
          ImGui::SingleLineSelectableText("##Outputinput_buf", input_buf, strlen(input_buf));

          ImGui::Text("Password: ");
          ImGui::SameLine(150);
          ImGui::SingleLineSelectableText("##OutputPassword", ps_buf, strlen(ps_buf));

          ImGui::Text("Output Decrypted: ");
          ImGui::SameLine(150);
          ImGui::SingleLineSelectableText("##Outputdec", (char *) dec.c_str(), dec.size());


          ImGui::InputText("Encrypted Input", input_buf, max_input, 0);
          ImGui::InputText("Password", ps_buf, max_input, 0);
          if (ImGui::Button("Done") || (ImGui::IsWindowFocused() && ImGui::IsKeyReleased(ImGuiKey_Enter))) {
            input = input_buf;
            s_ps = ps_buf;
            dec = loader_out(s_ps, input);
          }
          ImGui::EndTabItem();
          // Decrypt Only Embedded
        }
        if (ImGui::BeginTabItem("Hash & Encodes")) {
          static std::string input;
          const int max_input = 4096;
          static char input_buf[max_input + 1];

          static std::string base64, base64url, hax, sha3;


          ImGui::Text("Input: ");
          ImGui::SameLine(150);
          ImGui::SingleLineSelectableText("##inputbbuf", input_buf, strlen(input_buf));

          ImGui::Text("Base64: ");
          ImGui::SameLine(150);
          ImGui::SingleLineSelectableText("##base64buf", base64.data(), base64.size());

          ImGui::Text("Base64 (url): ");
          ImGui::SameLine(150);
          ImGui::SingleLineSelectableText("##base64bufurl", base64url.data(), base64url.size());

          ImGui::Text("Hax: ");
          ImGui::SameLine(150);
          ImGui::SingleLineSelectableText("##haxbuff", hax.data(), hax.size());

          ImGui::Text("Sha3: ");
          ImGui::SameLine(150);
          ImGui::SingleLineSelectableText("##sha3buff", sha3.data(), sha3.size());


          ImGui::InputText("Input", input_buf, max_input, 0);
          if (ImGui::Button("Done") || (ImGui::IsWindowFocused() && ImGui::IsKeyReleased(ImGuiKey_Enter))) {
            input = input_buf;
            base64 = base64_encode(input);
            base64url = base64_encode(input, true);
            hax = stoh(input);
            sha3 = get_hash(input);
          }
          ImGui::EndTabItem(); // hash and encodes
        }
        ImGui::EndTabBar();
      }
      ImGui::Separator();
    }
    return true;
  }

} // PDM::Components