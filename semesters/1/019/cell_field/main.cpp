#include <cmath>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

#include <Graph_lib/Graph.h>
#include <Graph_lib/Simple_window.h>
#include "board.h"
#include "cell.h"

using namespace Graph_lib;
using namespace std;

MyWindow win({100, 100}, 400, 800, "window");
CellField cellwin({100, 100});

int main() try {
  Cell cell({80, 80}, nullptr, Cell::black);
  win.attach(cell);
  win.wait_for_button();
  cellwin.wait_for_button();
} catch (std::exception& e) {
  std::cerr << e.what() << std::endl;
  return 1;
} catch (...) {
  std::cerr << "Oops, something went wrong..." << std::endl;
  return 2;
}