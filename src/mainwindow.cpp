#include <gtkmm.h>
#include <glibmm/ustring.h>
#include <gtkmm/enums.h>
#include <string>
#include "mainwindow.h"
#include "sigc++/adaptors/bind.h"
#include "sigc++/functors/mem_fun.h"

MainWindow::MainWindow() : 
  m_main_box(Gtk::Orientation::VERTICAL),
  m_top_box(Gtk::Orientation::HORIZONTAL),
  m_bottom_box(Gtk::Orientation::VERTICAL),
  m_top_box_entry(),
  m_bottom_box_numpad()
{
  const Glib::ustring APPNAME = "Calculator";
  const int width = 600;
  const int height = 400;

  const Glib::ustring ENTRY_TEXT = "0";

  set_title(APPNAME);
  set_default_size(width, height);

  m_top_box_entry.set_placeholder_text(ENTRY_TEXT);
  m_top_box_entry.set_hexpand(true);
  m_top_box_entry.set_vexpand(false);

  for (int row = 0; row < 4; ++row) {
    Gtk::Box* button_row = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL);
    for (int col = 0; col < 3; ++col) {
      int button_number = 9 - (row * 3 + col);

      if (button_number >= 0) {
        auto button = Gtk::make_managed<Gtk::Button>();
        button->set_label(std::to_string(button_number));
        button->signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &MainWindow::on_numpad_clicked), button_number));
        button_row->append(*button);
      }
    }
    m_bottom_box.append(*button_row);
  }

  m_top_box.append(m_top_box_entry);
  m_top_box.set_margin(10);

  m_bottom_box.set_margin_start(10);
  m_bottom_box.set_margin_end(10);

  m_main_box.append(m_top_box);
  m_main_box.append(m_bottom_box);

  set_child(m_main_box);

}

MainWindow::~MainWindow() {}

void MainWindow::on_numpad_clicked(int value)
{
  Glib::ustring current_value = m_top_box_entry.get_text();
  if (!current_value.empty()) {
    current_value += std::to_string(value);
  } else {
    current_value = std::to_string(value);
  }
  m_top_box_entry.set_text(current_value);
}
