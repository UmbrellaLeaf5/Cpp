#pragma once

// #include "checker.h"
#include <Graph_lib/Simple_window.h>
using Graph_lib::Point;

struct Checker;

struct Cell : Graph_lib::Button
{
    enum Type
    {
        black,
        white
    };

    Cell(Point xy, Graph_lib::Callback cb, Type t);

    Point center () const { return Point{loc.x + width / 2, loc.y + height / 2}; }

    void attach (Graph_lib::Window& win) override;

    void activate ()
    {
        if (pw)
            pw->color(FL_SELECTION_COLOR);
    }

    void attach_checker (Checker& ch);

    void deactivate () { reset_color(); }

    bool is_black () const { return type == black; }

    bool has_checker () const { return checker != nullptr; }

    Checker& detach_checker ();

    const Checker& ger_checker () const { return *checker; }

    static constexpr int size = 95;

  private:
    Type type;
    Checker* checker{nullptr};

    void reset_color ();
};
