#pragma once

#include "cell.h"
#include <Graph_lib/Graph.h>
#include <Graph_lib/Simple_window.h>

using Graph_lib::Address;
using Graph_lib::Point;

// наш класс с кнопкой quit
class MyWindow : public Simple_window
{
  public:
    MyWindow(Point xy, int w, int h, const std::string& title);

  private:
    Graph_lib::Button quit_button;
    // кнопка quit написанная через аналог указателям
    static void cb_quit (Address, Address widget);

    void quit () { hide(); }
};

// класс с полем 8*8 (как в шахматах)
class ChessBoard : public MyWindow
{
  public:
    ChessBoard(Point xy);
    static constexpr int N = 4;
    static constexpr int N_max = 8;
    static_assert(N <= N_max, "do not allow board larger than N*N_max");

  private:
    static constexpr int margin = 30;
    static constexpr int width = N * Cell::size + 2 * margin + 70;
    static constexpr int height = N * Cell::size + 2 * margin;
    Graph_lib::Vector_ref<Cell> cells;

    // функция (для всех кнопок) для клика
    static void cb_clicked (Address, Address widget);

    void clicked (Cell& c);

    Graph_lib::Marks x_labels;
    Graph_lib::Marks y_labels;
    Cell* selected{nullptr};
};