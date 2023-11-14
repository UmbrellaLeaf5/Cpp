#pragma once

#include "board.h"
#include <Graph_lib/Graph.h>
#include <Graph_lib/Simple_window.h>

using Graph_lib::Address;
using Graph_lib::Point;

MyWindow::MyWindow(Point xy, int w, int h, const std::string& title)
    : Simple_window::Simple_window{xy, w, h, title},
      quit_button{Point{x_max() - 70, 20}, 70, 20, "Quit", cb_quit}
{
    attach(quit_button);
}

void MyWindow::cb_quit(Address, Address widget)
{
    auto& btn = Graph_lib::reference_to<Graph_lib::Button>(widget);
    dynamic_cast<MyWindow&>(btn.window()).quit();
}