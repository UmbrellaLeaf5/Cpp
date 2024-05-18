#include "cell.h"
#include <Graph_lib/Graph.h>
#include <Graph_lib/Simple_window.h>
using namespace Graph_lib;

/*
о том, почему используем static
Cell:
__________
|        | + type + (size)
__________
   Button

() - если size не static
size - классовая переменная, доступная всем его экземплярам
*/

Cell::Cell(Point xy, Callback cb, Type t)
    : Button{xy, size, size, "", cb}, type{t} {}

void Cell::reset_color() {
  if (!pw)
    Graph_lib::error("Cell is not attached to a window");
  if (is_black())
    pw->color(Color::black);
  else
    pw->color(Color::white);
}

void Cell::attach(Graph_lib::Window& win) {
  Button::attach(win);
  reset_color();
}
