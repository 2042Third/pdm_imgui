//
// Created by Mike Yang on 11/20/2022.
//

#include "pdm_database.h"
#include "pdm_status.h"

#pragma once

//#include <iostream>

#define PDM_DOCK_MAIN "pdm docking space"
namespace PDM {


  class Runtime{
    public:
      Runtime();
      ~Runtime();
      pdm_database * db;
  };



}