//
// Created by Yi Yang on 12/21/2022.
//

#ifndef PDM_PLATFORMS_UI_TYPES_H
#define PDM_PLATFORMS_UI_TYPES_H

#include <string>

namespace PDM {
  struct UserInfo {
    std::string msg="";
    std::string username="";
    std::string msgh="";
    std::string email="";
    std::string val="";
    std::string typestring="";
    std::string h ="";
    std::string senderstring="";
    std::string sess = "";
    std::string status = "fail";
    std::string statusInfo = "None";
    std::string receiverstring="";
    std::string authdata="";
    uint32_t time=-1;
    uint32_t update_time=-1;
    std::string utime="";
    std::string pdmSecurityVersion="";
    std::string checker= "";
    std::string ctime="";
    std::string netStatus = "none";
  };
}
#endif //PDM_PLATFORMS_UI_TYPES_H
