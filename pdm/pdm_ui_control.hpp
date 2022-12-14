
#ifndef PDM_PLATFORMS_UI_CONTROL_HPP
#define PDM_PLATFORMS_UI_CONTROL_HPP
#include <string>

namespace PDM {

  class UI {
    struct Id {
      bool has_database_debug_window = true; // default database view to true
      bool has_database_debug_viewer = true; // default database viewer to true
      bool open_file = false;
      bool net_debug_open = true;
      std::string database_current_file_path;
    };
  public:
    UI(){ui = new Id();}
    ~UI(){delete ui;}
    int toggle_database_debug_window(){ui->has_database_debug_window=!ui->has_database_debug_window;return 1;}
    Id *ui;
  };


}// namespace PDM

#endif //PDM_PLATFORMS_UI_CONTROL_HPP
