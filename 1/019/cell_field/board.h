#pragma once

#include <Graph_lib/Graph.h>
#include <Graph_lib/Simple_window.h>

using Graph_lib::Address;
using Graph_lib::Point;

class MyWindow : public Simple_window
{
  public:
    MyWindow(Point xy, int w, int h, const std::string& title);

  private:
    Graph_lib::Button quit_button;
    static void cb_quit (Address, Address widget);

    void quit () { hide(); }
};