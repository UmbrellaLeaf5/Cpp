#include <cmath>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

#include "board.h"
#include "cell.h"
#include <Graph_lib/Graph.h>
#include <Graph_lib/Simple_window.h>
using namespace Graph_lib;
using namespace std;

MyWindow win({100, 100}, 400, 800, "window");

int main ()
try
{
    win.wait_for_button();
}
catch (std::exception& e)
{
    std::cerr << e.what() << std::endl;
    return 1;
}
catch (...)
{
    std::cerr << "Oops, something went wrong..." << std::endl;
    return 2;
}