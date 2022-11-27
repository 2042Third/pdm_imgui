//
// Created by 18604 on 11/26/2022.
//

#ifndef PDM_PLATFORMS_UI_PDM_STATUS_H
#define PDM_PLATFORMS_UI_PDM_STATUS_H

#include <string>

namespace PDM {

  class Status {
    struct State {
      int open = 0;
      int loading = 0;
      int error = 0;
      std::string open_stat = "no";
      std::string loading_stat = "no";
      std::string error_stat = "no";
    };
  public:
    // Fake enum
    static const int NONE     = 1;
    static const int LOADING  = 2;
    static const int OPEN     = 3;
    static const int CLOSED   = 4;
    static const int ERROR    = 5;

    int current_status = 0;

    /**
     * Change status
     * */
    void change(int status) {
      current_status = status;
      if (status == NONE) {
        state.open = 0;
        state.loading = 0;
        state.error = 0;
      } else if (status == LOADING) {
        state.loading = 1;
      } else if (status == OPEN) {
        state.open = 1;
        state.loading = 0;
      } else if (status == CLOSED) {
        state.open = 0;
        state.loading = 0;
      } else {
        state.error = 1;
      }
    }

    State state;
  };
}// namespace PDM
#endif //PDM_PLATFORMS_UI_PDM_STATUS_H
