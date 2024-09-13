#include "gtkmm/enums.h"
#include <gtkmm.h>

class MyWindow : public Gtk::Window
{
public:
  MyWindow();
private:
  Gtk::Box m_box{Gtk::Orientation::VERTICAL};
  Gtk::Button m_Button1{"Button 1"};
  Gtk::Button m_Button2{"Button 2"};
  Gtk::Frame m_frame;
};

MyWindow::MyWindow()
{
  set_title("Basic application");
  set_default_size(200, 200);

  m_box.append(m_Button1);
  m_box.append(m_Button2);
  m_frame.set_child(m_box);

  set_child(m_frame);
}

int main(int argc, char* argv[])
{
  auto app = Gtk::Application::create("org.gtkmm.examples.base");

  return app->make_window_and_run<MyWindow>(argc, argv);
}

