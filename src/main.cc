#include "gtkmm/enums.h"
#include "gtkmm/object.h"
#include "sigc++/functors/mem_fun.h"
#include <gtkmm.h>
#include <iostream>
#include <string>

class MyWindow : public Gtk::Window
{
public:
  MyWindow();
private:
  Gtk::Box m_main_box{Gtk::Orientation::VERTICAL};
  Gtk::Box m_top_box{Gtk::Orientation::HORIZONTAL};
  Gtk::Box m_bottom_box{Gtk::Orientation::HORIZONTAL};
  Gtk::Box m_bottom_box_vertical{Gtk::Orientation::VERTICAL};
  Gtk::Entry m_entry;
  Gtk::Button m_button{"Submit"};
  
  void on_button_clicked(int button_number);

};

MyWindow::MyWindow()
{
  set_default_size(300, 100);

  for (int row = 0; row < 4; ++row) {
    Gtk::Box* button_row = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL);
    for (int col = 0; col < 3; ++col) {
      int button_number = 9 - (row * 3 + col);

      if (button_number >= 0) {
        auto button = Gtk::make_managed<Gtk::Button>();
        button->set_label(std::to_string(button_number));
        button_row->append(*button);
      }
    }
    m_bottom_box_vertical.append(*button_row);
  }

  m_entry.set_placeholder_text("0");
  m_entry.set_hexpand(true);

  m_top_box.append(m_entry);

  m_bottom_box.append(m_bottom_box_vertical);
  m_bottom_box.append(m_button);

  m_main_box.append(m_top_box);
  m_main_box.append(m_bottom_box);

  set_child(m_main_box);
}
int main(int argc, char* argv[])
{
  auto app = Gtk::Application::create("org.gtkmm.examples.base");

  return app->make_window_and_run<MyWindow>(argc, argv);
}

