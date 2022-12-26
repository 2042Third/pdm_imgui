//
// Created by Mike Yang on 11/20/2022.
//

#include "pdm_platforms_ui/pdm/handler/pdm_database.h"
#include "pdm_platforms_ui/pdm/handler/pdm_status.h"
#include "pdm_ui_control.hpp"
#include "pdm_platforms_ui/pdm/handler/pdm_net.h"
#include "ui/imgui_custom_ui.h"

#pragma once

//#include <iostream>

#define PDM_DOCK_MAIN "pdm docking space"
namespace PDM {
  /**
   * PDM runtime object that handles all runtime actions
   * and states of the application
   * */
  class Runtime:
      public Status,
      public UI,
      public network
  {
  public:
    pdm_database * db; // debug
    pdm_database * user_conf; // User config
    pdm_database * user_data; // User data
    Runtime();
    ~Runtime();

    std::string conf_loc;
    std::string data_loc;

    int signin_action(const std::string&a, NetWriter* wt_in,const char* password);

    int get_user_loc(const std::string &file_names);
  };



}