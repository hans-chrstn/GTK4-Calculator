#include <gtkmm.h>
#include <string>
#include <sigc++/sigc++.h>

#include "mainwindow.h"

MainWindow::MainWindow() : 
  m_main_box(Gtk::Orientation::VERTICAL),
  m_top_box(Gtk::Orientation::HORIZONTAL),
  m_bottom_box(Gtk::Orientation::VERTICAL),
  APPNAME("Calculator"), ENTRY_TEXT("0"), WIDTH(200), HEIGHT(200)
{
  set_title(APPNAME);
  set_default_size(WIDTH, HEIGHT);

  m_top_entry.set_placeholder_text(ENTRY_TEXT);
  m_top_entry.set_hexpand(false);
  m_top_entry.set_vexpand(false);

  Glib::ustring last_row_buttons[3] = { ".", "0", "+-" };
  for (int row = 0; row < 4; ++row) {
    Gtk::Box* button_row = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL);
    for (int col = 0; col < 3; ++col) {
      if (row < 3) {
        int button_number = 9 - (row * 3 + col);
        auto button = Gtk::make_managed<Gtk::Button>();
        button->set_label(std::to_string(button_number));
        button->signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &MainWindow::on_numpad_clicked), button_number));
        button->set_margin(5);
        button_row->append(*button);
      } else {
        auto button = Gtk::make_managed<Gtk::Button>(last_row_buttons[col]);
        if (col == 0 || col == 2) {
          button->signal_clicked().connect([this, col, last_row_buttons]() {
            m_top_entry.set_text(last_row_buttons[col]);
          });
        } else {
          button->signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &MainWindow::on_numpad_clicked), 0));
        }
        button->set_margin(5);
        button_row->append(*button);
      }
    }
    m_bottom_box.append(*button_row);
  }

  m_top_box.append(m_top_entry);
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
  Glib::ustring current_value = m_top_entry.get_text();
  m_top_entry.set_text(current_value.empty() ? Glib::ustring::compose("%1", value) : current_value + Glib::ustring::compose("%1", value));
}
