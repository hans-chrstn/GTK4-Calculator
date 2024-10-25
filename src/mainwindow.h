#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "glibmm/ustring.h"
#include <gtkmm.h>

class MainWindow : public Gtk::Window
{
public:
  MainWindow();
  ~MainWindow() override;
protected:
  Gtk::Box m_main_box;
  Gtk::Box m_top_box;
  Gtk::Box m_bottom_box;
  Gtk::Entry m_top_entry;

  const Glib::ustring APPNAME, ENTRY_TEXT;
  const int WIDTH;
  const int HEIGHT;


  void on_numpad_clicked(int value);
};

#endif
