#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gtkmm/button.h"
#include <gtkmm/entry.h>
#include <gtkmm/box.h>
#include <gtkmm/window.h>

class MainWindow : public Gtk::Window
{
public:
  MainWindow();
  ~MainWindow() override;
protected:
  Gtk::Box m_main_box;
  Gtk::Box m_top_box;
  Gtk::Box m_bottom_box;
  Gtk::Entry m_top_box_entry;
  Gtk::Button m_bottom_box_numpad;

  void on_numpad_clicked();
};

#endif
