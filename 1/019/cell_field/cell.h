#pragma once

#include <Graph_lib/GUI.h>
#include <Graph_lib/Simple_window.h>
using Graph_lib::Point;

class Cell : public Graph_lib::Button
{
  public:
    static constexpr int size = 100;

    enum Type
    {
        black,
        white
    };

    Cell(Point xy, Graph_lib::Callback cb, Type t);

    bool is_black () const { return type == black; }

    // перезаписываем, так как возникала ошибка из-за логики Страуструпа: до этого аттачили ничего
    // не
    // зная о цвете
    void attach (Graph_lib::Window& win) override;

    void activate ()
    {
        if (pw)
            pw->color(FL_SELECTION_COLOR);
    }

    void deactivate () { reset_color(); }

  private:
    Type type;
    // функция, меняющая цвет при клике (будто выбрали)
    void reset_color ();
};