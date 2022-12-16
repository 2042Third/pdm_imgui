//
// Created by Yi Yang on 12/16/2022.
//

#ifndef PDM_PLATFORMS_UI_PDM_MENUS_HPP
#define PDM_PLATFORMS_UI_PDM_MENUS_HPP

#include "empp.h"
#include "pdm.h"
#include "pdm_database.h"
#include "pdm_platforms_ui/pdm/lib/nativefiledialog-extended/src/include/nfd.h"
#include "imgui.h"

namespace PDM {

  bool file_menu(Runtime* rt){
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

  bool debug_menu(Runtime* rt){
    if (ImGui::BeginMenu("Debug"))
    {
      if(ImGui::BeginMenu("Network")){
        if(ImGui::MenuItem("Toggle Network Debug", "")){
          rt->ui->net_debug_open = ! rt->ui->net_debug_open;
        }
        ImGui::EndMenu(); // network
      }
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
        ImGui::EndMenu();// Database menu
      }
      ImGui::EndMenu();// debug menu
    }
    return true;
  }
}

#endif //PDM_PLATFORMS_UI_PDM_MENUS_HPP
