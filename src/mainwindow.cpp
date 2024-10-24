#include <gtkmm.h>
#include <glibmm/ustring.h>
#include <gtkmm/enums.h>
#include "mainwindow.h"
#include "sigc++/functors/mem_fun.h"

MainWindow::MainWindow() : m_main_box(Gtk::Orientation::VERTICAL), m_top_box(), m_bottom_box(), m_top_box_entry(), m_bottom_box_numpad()
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

  m_bottom_box_numpad.signal_clicked().connect(sigc::mem_fun(*this,
    &MainWindow::on_numpad_clicked));

  m_top_box.append(m_top_box_entry);
  m_top_box.set_margin(10);

  m_bottom_box.append(m_bottom_box_numpad);
  m_bottom_box.set_margin_start(10);
  m_bottom_box.set_margin_end(10);

  m_main_box.append(m_top_box);
  m_main_box.append(m_bottom_box);

  set_child(m_main_box);

}

MainWindow::~MainWindow() {}

void MainWindow::on_numpad_clicked()
{

}
