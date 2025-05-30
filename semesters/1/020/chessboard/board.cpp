#include <iostream>

#include "board.h"

using namespace Graph_lib;

Cell::Type type_of_cell(int i, int j) {
  if (i % 2 == 0)
    return (j % 2 == 0) ? Cell::black : Cell::white;
  else
    return (j % 2 == 0) ? Cell::white : Cell::black;
}

std::string letters() {
  std::string s(Chessboard::N_max, '\0');

  for (int i = 0; i < Chessboard::N_max; ++i)
    s[i] = 'a' + i;

  return s;
}

std::string digits() {
  std::string s(Chessboard::N_max, '\0');

  for (int i = 0; i < Chessboard::N_max; ++i)
    s[i] = '1' + i;

  return s;
}

Chessboard::Chessboard(Point xy)
    : My_window{xy, width, height, "Checkerboard"},
      x_labels{letters()},
      y_labels{digits()} {
  size_range(width, height, width, height);  // fixed window size

  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j) {
      cells.push_back(new Cell{
          Point{margin + j * Cell::size, margin + (N - 1 - i) * Cell::size},
          cb_clicked, type_of_cell(i, j)});
      attach(cells[cells.size() - 1]);
    }

  for (int i = 0; i < N; ++i) {
    // board corners: left top
    constexpr Point lt{margin + Cell::size / 2, margin + N * Cell::size + 10};
    // and right bottom
    constexpr Point rb{margin - 10, margin + N * Cell::size - Cell::size / 2};

    x_labels.add(Point{lt.x + i * Cell::size, lt.y});
    y_labels.add(Point{rb.x, rb.y - i * Cell::size});
  }
  attach(x_labels);
  attach(y_labels);
}

void Chessboard::clicked(Cell& c) {
  if (!c.is_black())
    return;

  if (!selected) {
    selected = &c;
    c.activate();
  } else {
    if (selected->has_checker()) {
      Cell& c1 = *selected;
      c.attach_checker(c1.detach_checker());
    }

    selected->deactivate();

    if (selected == &c)  // reset selection
    {
      selected = nullptr;
    } else  // choose another cell
    {
      selected = &c;
      c.activate();
    }
  }

  Fl::redraw();
}

Cell& Chessboard::at(char c, int i) {
  i--;
  int j = c - 'a';
  return cells[i * N + j];
}
