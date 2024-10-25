#include <gtkmm/application.h>
#include "mainwindow.h"

int main (int argc, char *argv[]) {
  auto app = Gtk::Application::create("mishima.calculator");
  return app->make_window_and_run<MainWindow>(argc, argv);
}
