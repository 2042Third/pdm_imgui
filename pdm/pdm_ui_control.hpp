
#ifndef PDM_PLATFORMS_UI_CONTROL_HPP
#define PDM_PLATFORMS_UI_CONTROL_HPP
#include <string>

namespace PDM {

  class UI {
    struct Id {
      int has_database_debug_window = 0;
      bool open_file = false;
    };
  public:
    int toggle_database_debug_window(){ui.has_database_debug_window=!ui.has_database_debug_window;return 1;}
    Id ui;
  };


}// namespace PDM

#endif //PDM_PLATFORMS_UI_CONTROL_HPP
