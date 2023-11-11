#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include <Graph_lib/Graph.h>
#include <Graph_lib/Simple_window.h>

#include "least_squares.h"

using namespace Graph_lib;

int main ()
try
{
    // константы
    constexpr int xmax = 600;  // window size
    constexpr int ymax = 450;

    constexpr int xoffset = 40;  // отступы
    constexpr int yoffset = 40;

    constexpr int xlength = xmax - 2 * xoffset;  // длины осей
    constexpr int ylength = ymax - 2 * yoffset;

    constexpr int xrange = 10;  // количество точек на оси
    constexpr int yrange = 10;

    constexpr int data_range = 10;

    // создание окна
    Point lt{100, 100};  // left top window corner
    Simple_window win{lt, xmax, ymax, "Least Squares"};
    win.color(Color::white);

    // рисование осей
    Point orig{xoffset, ymax - yoffset};
    Axis x{Axis::x, orig, xlength, xrange, "x"};
    Axis y{Axis::y, orig, ylength, yrange, "y"};
    win.attach(x);
    win.attach(y);

    // рисование графика и отображение точек
    std::vector<lsm::Point> data = {{1.0, 2.5}, {2.6, 2.0}, {3.88888, 4.0}, {10, 10}};
    // функция переводит из точки с действит. коорд. в экранные точки с пикселями
    auto to_axis_space = [&] (lsm::Point p) -> Point
    {
        p.x *= xlength / xrange;
        p.y *= -ylength / yrange;
        p.x += orig.x;
        p.y += orig.y;
        return {(int)p.x, (int)p.y};
    };
    Marks scatter("o");
    for (auto& p : data)
        scatter.add(to_axis_space(p));
    win.attach(scatter);
    // переход к графику
    // вызываем функцию, которая считает коэф. наклона и сдвига
    auto coeffs = lsm::least_squares(data);
    double incline = coeffs.a;
    double shift = coeffs.b;
    Function line{[&incline, &shift] (double x) { return (incline * x + shift); },
                  0,
                  data_range,
                  orig,
                  1000,
                  xlength / data_range,
                  ylength / data_range};
    win.attach(line);

    win.wait_for_button();
}
catch (std::exception& e)
{
    std::cerr << "error: " << e.what() << std::endl;
    return 1;
}
