//
// Created by Mike Yang on 11/20/2022.
//

#include "pdm_database.h"
#include "pdm_status.h"
#include "pdm_ui_control.hpp"
#include "pdm_net.h"

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
      Runtime();
      ~Runtime();
    pdm_database * db;
  };



}