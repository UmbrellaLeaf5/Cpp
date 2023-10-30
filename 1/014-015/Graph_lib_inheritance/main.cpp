#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <cmath>

#include <Vector_lib/vec2d.h>
#include <Vector_lib/poly.h>
#include <Graph_lib/Graph.h>
#include <Graph_lib/Simple_window.h>
using namespace Graph_lib;
using namespace std;

Simple_window win({100, 100}, 400, 800, "window");

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

// класс арки, созданный нами из эллипса
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
            if(fill_color().visibility()){ // проверяем видимость заливки
                fl_color(fill_color().as_int());
                fl_pie(point(0).x, point(0).y, 2*w-1, 2*h-1, phi1, phi2);
            }
            fl_color(color().as_int());
            if(color().visibility()) // проверяем видимость границы
                fl_arc(point(0).x, point(0).y, 2*w, 2*h, phi1, phi2);
        }
};

// структура, помогающая реализовать правильный шестиугольник
class Regular_hexagon: public Shape
{
    public:
        int rad;
        Point cntr;
        Regular_hexagon(Point c, int r)
        {
            this->add({c.x - r,c.y});
            this->add({c.x - r + r*cos(Graph_lib::pi/3.0),c.y + r*sin(Graph_lib::pi/3.0)});
            this->add({c.x + r*cos(Graph_lib::pi/3.0), c.y + r*sin(Graph_lib::pi/3.0)});
            this->add({c.x + r,c.y});
            this->add({c.x + r*cos(Graph_lib::pi/3.0), c.y - r*sin(Graph_lib::pi/3.0)});
            this->add({c.x - r*cos(Graph_lib::pi/3.0), c.y - r*sin(Graph_lib::pi/3.0)});
            rad = r;
            cntr = c;
        }
        Point center () const {return cntr;}
        int width () const {return 2*rad;}
        int height() const {return 2*rad*sin(Graph_lib::pi/3);}
        int edge () const {return rad;}
    protected:
        void draw_lines() const override
        {
            for(int i = 0; i < 5; i++)
                fl_line(point(i).x, point(i).y, point(i+1).x, point(i+1).y);
            fl_line(point(5).x, point(5).y, point(0).x, point(0).y);
        }
};

//класс группы шестиугольников (для выполнения задания с мозаикой)
/*class Hexagon_tile : public Rectangle
{
    public:
        Hexagon_tile (Point p, int ww, int hh, int rr)
        {
            // первый шестиугольник
            this->add({c.x - r,c.y});
            this->add({c.x - r + r*cos(Graph_lib::pi/3.0),c.y + r*sin(Graph_lib::pi/3.0)});
            this->add({c.x + r*cos(Graph_lib::pi/3.0), c.y + r*sin(Graph_lib::pi/3.0)});
            this->add({c.x + r,c.y});
            this->add({c.x + r*cos(Graph_lib::pi/3.0), c.y - r*sin(Graph_lib::pi/3.0)});
            this->add({c.x - r*cos(Graph_lib::pi/3.0), c.y - r*sin(Graph_lib::pi/3.0)});
            rad = r;
            cntr = c;
            int temp_x = 0;
            int i = 0;
            for (int curr_x = c.x - r; curr_x < ww; curr_x -= temp_x)
            {
                if (i % 2 == 0)
                    temp_x = r;
                else
                    temp_x = 2*r; 
            }
        }
        void move(int dx, int dy);
        void draw_lines() const override;
        {

        }
    private:
        Vector_ref <Regular_hexagon> tile;

};
*/

//вспомогательная функция, считающая числа Фибоначчи
int fibn(int n){
    if(n == 1 || n == 2)
        return 1;
    vector<int> ans;
    ans.push_back(1);
    ans.push_back(1);
    for(int i = 2; i < n; i++)
        ans.push_back(ans[i-1]+ans[i-2]);
    return ans.back();
}

void Fibonacci_spiral()
{
    vector<MyArc*> arcs;

    constexpr int scale = 10;
    constexpr int center = 250;
    constexpr int count = 8;

    MyArc arcb1{{center,center},scale,scale,180,270};
    MyArc arcb2{{center,center},scale,scale,270,360};

    arcb1.set_color(Color::black);
    arcb2.set_color(Color::black);

    win.attach(arcb1);
    win.attach(arcb2);

    int prev_x = center;
    int prev_y = center;
    int prev_angle = 270;

    int curr_x;
    int curr_y;
    int curr_size;
    int curr_angle;

    for(int i = 1; i <= count; i++)
    {
        if(i % 4 == 1)
            curr_x = prev_x - fibn(i)*scale;
        else if (i % 4 == 3)
            curr_x = prev_x + fibn(i)*scale;
        else if(i % 4 == 0)
            curr_y = prev_y - fibn(i)*scale;
        else if (i % 4 == 2)
            curr_y = prev_y + fibn(i)*scale;

        if (i % 2 == 1)
            curr_y = prev_y;
        else
            curr_x = prev_x;

        curr_size = fibn(i+2)*scale;
        curr_angle = (prev_angle+90)%360;

        arcs.push_back(new MyArc{{curr_x,curr_y},curr_size,curr_size,curr_angle,curr_angle+90});
        arcs.back()->set_color(Color::black);
        win.attach(*arcs.back());

        prev_x = curr_x;
        prev_y = curr_y;
        prev_angle = curr_angle;

    }
}

int main ()
try
{
    
    //vector <MyArc> arcs;
    //arcs.push_back(arc); - так как в Shape явно запрещено копирование, этот метод не работает для vector
    //Fibonacci_spiral();
    Regular_hexagon hexic({200,200},100);
    hexic.set_color(Color::black);
    win.attach(hexic);
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