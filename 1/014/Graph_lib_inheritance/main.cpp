#include <iostream>
#include <sstream>
#include <stdexcept>

#include <Graph_lib/Graph.h>
#include <Graph_lib/Simple_window.h>
using namespace Graph_lib;

// пробный класс, показывающий, как работает переопределение
class MyConvas: public Shape
{
    protected:
        void draw_lines() const override
        {
            fl_line(0, 0, 200, 200);
            fl_pie(0, 200, 100, 50, 0, 360);
        }
};

class MyArc: public Ellipse
{
    public:
        MyArc(Point p, int ww, int hh, int alpha, int beta): Ellipse(p, ww, hh), phi1(alpha), phi2(beta) {}
    private:
        int phi1, phi2;
    protected:
        void draw_lines() const override 
        {
            int w = major(), h = minor();
            if(fill_color().visibility()) // проверяем видимость заливки
            {
                fl_color(fill_color().as_int());
                fl_pie(point(0).x, point(0).y, 2*w-1, 2*h-1, phi1, phi2);
            }
            fl_color(color().as_int());
            if(color().visibility()) // проверяем видимость границы
            {
                fl_arc(point(0).x, point(0).y, 2*w, 2*h, phi1, phi2);
                //fl_line(point(0).x, point(0).y, w, h);
            }
        }
};

int main ()
try
{
    Simple_window win({100, 100}, 400, 400, "window");
    MyArc arc({200,200}, 100, 50, 0, 180);
    arc.set_fill_color(Color::green);
    arc.set_color(Color::black);
    win.attach(arc);
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