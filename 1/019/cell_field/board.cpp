#include "board.h"
#include <Graph_lib/Graph.h>
#include <Graph_lib/Simple_window.h>

using namespace std;
using Graph_lib::Address;
using Graph_lib::Point;

string letters() {
  string s(CellField::N_max, '\0');
  for (size_t i = 0; i < s.size(); ++i)
    s[i] = 'a' + i;  // так как ASCII
  return s;
}

string digits() {
  string s(CellField::N_max, '\0');
  for (size_t i = 0; i < s.size(); ++i)
    s[i] = '1' + i;
  return s;
}

// конструктор класса окна с кнопкой quit (её инициализация происходит по аналогии с next из
// Simple_window)
MyWindow::MyWindow(Point xy, int w, int h, const std::string& title)
    : Simple_window::Simple_window{xy, w, h, title},
      quit_button{Point{x_max() - 70, 20}, 70, 20, "Quit", cb_quit} {
  attach(quit_button);
}

void MyWindow::cb_quit(Address, Address widget) {
  auto& btn = Graph_lib::reference_to<Graph_lib::Button>(widget);
  dynamic_cast<MyWindow&>(btn.window()).quit();
}

// функция, определяющая цвет текущей клетки
Cell::Type type_of_cell(int i, int j) {
  return (i + j) % 2 ? Cell::black : Cell::white;
}

CellField::CellField(Point xy)
    : MyWindow::MyWindow{xy, width, height, "Cell field"},
      x_labels{letters()},
      y_labels{digits()} {
  size_range(width, height, width, height);  // фиксируем размеры окна
  // само поле рисуем в цикле циклов, так как это 64 клетки
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cells.push_back(new Cell{
          Point{margin + j * Cell::size, margin + (N - 1 - i) * Cell::size},
          cb_clicked, type_of_cell(i, j)});
      attach(cells[cells.size() - 1]);
    }
  }
  // добавляем подписи
  for (int i = 0; i < N; ++i) {
    // board corners : left bottom
    constexpr Point lb{margin + Cell::size / 2, margin + N * Cell::size + 10};
    // board corners : right bottom
    constexpr Point rb{margin - 10, margin + N * Cell::size - Cell::size / 2};
    x_labels.add(Point{lb.x + i * Cell::size, lb.y});
    y_labels.add(Point{rb.x, rb.y - i * Cell::size});
  }
  attach(x_labels);
  attach(y_labels);
}

void CellField::cb_clicked(Address, Address widget) {
  auto& btn = Graph_lib::reference_to<Cell>(widget);
  dynamic_cast<CellField&>(btn.window()).clicked(btn);
}

void CellField::clicked(Cell& c) {
  if (!c.is_black())
    return;
  if (!selected) {
    selected = &c;
    c.activate();
  } else {
    selected->deactivate();
    if (selected == &c) {
      selected = nullptr;
    } else {
      selected = &c;
      c.activate();
    }
  }
  Fl::redraw();
}