#include "glibmm/ustring.h"
#include "gtkmm/application.h"
#include <gtkmm.h>

class MainApp : public Gtk::Window
{
public:
  MainApp()
  {
    initWindow();
  }
private:
  const Glib::ustring WINDOW_NAME = "Calculator";
  const int width = 600;
  const int height = 400;

  void initWindow() {
    set_title(WINDOW_NAME);
    set_default_size(width, height);
  }
};

int main (int argc, char *argv[]) {
  auto app = Gtk::Application::create("mishima.calculator");
  return app->make_window_and_run<MainApp>(argc, argv);
}
