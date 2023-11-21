#pragma once

// #include "cell.h"
#include <Graph_lib/Simple_window.h>

struct Cell;

constexpr int wc_color_code = 17;
constexpr int bc_color_code = 30;

struct Checker : Graph_lib::Circle
{
    enum Type
    {
        black,
        white
    };

    Checker(Graph_lib::Window& win) : Circle{Graph_lib::Point{0, 0}, r}
    {
        win.attach(*this);
        // add(Point(p.x, p.y));
    }

    void draw_lines () const override { Circle::draw_lines(); }

    void detach ();

    void attach (const Cell& c);

    virtual bool is_black () const = 0;

  private:
    const Cell* cell{nullptr};
    static constexpr int r = 0.9 * 100 / 2;
};

struct WhiteChecker : Checker
{
    WhiteChecker(Graph_lib::Window& win) : Checker(win)
    {
        set_fill_color(Graph_lib::Color{wc_color_code});
    }

    bool is_black () const override { return false; }
};

struct BlackChecker : Checker
{
    BlackChecker(Graph_lib::Window& win) : Checker(win)
    {
        set_fill_color(Graph_lib::Color{bc_color_code});
    }

    bool is_black () const override { return true; }
};
