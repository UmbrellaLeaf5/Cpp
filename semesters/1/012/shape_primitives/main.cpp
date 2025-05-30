#include <iostream>
#include <sstream>
#include <stdexcept>

#include <Graph_lib/Graph.h>
#include <Graph_lib/Simple_window.h>

using namespace Graph_lib;

int main() try {
  Point t1{100, 100};

  Simple_window win{t1, 600, 400, "Canvas"};
  win.wait_for_button();

  Axis xa{Axis::x, Point{20, 300}, 280, 10, "x axis"};
  win.attach(xa);
  win.set_label("Canvas #2");
  win.wait_for_button();

  Axis ya{Axis::y, Point{20, 300}, 280, 10, "y axis"};
  ya.set_color(Color::cyan);
  ya.label.set_color(Color::dark_red);
  win.attach(ya);
  win.set_label("Canvas #3");
  win.wait_for_button();

  Function sine{sin, 0, 100, Point{20, 150}, 1000, 50, 50};
  win.attach(sine);
  win.set_label("Canvas #4");
  win.wait_for_button();

  sine.set_color(Color::blue);

  Graph_lib::Polygon poly;
  poly.add(Point{300, 200});
  poly.add(Point{350, 100});
  poly.add(Point{400, 200});

  poly.set_color(Color::red);
  poly.set_style(Line_style::dash);
  win.attach(poly);
  win.set_label("Canvas #5");
  win.wait_for_button();

  Graph_lib::Rectangle r{Point{200, 200}, 100, 50};
  win.attach(r);
  win.set_label("Canvas #6");
  win.wait_for_button();

  Closed_polyline poly_rect;
  poly_rect.add(Point{100, 50});
  poly_rect.add(Point{200, 50});
  poly_rect.add(Point{200, 100});
  poly_rect.add(Point{100, 100});
  win.attach(poly_rect);
  win.set_label("Canvas #6.1");
  win.wait_for_button();

  poly_rect.add(Point{50, 75});
  win.set_label("Canvas #6.2");
  win.wait_for_button();

  r.set_fill_color(Color::yellow);
  poly.set_style(Line_style{Line_style::dash, 4});
  poly_rect.set_style(Line_style{Line_style::dash, 2});
  poly_rect.set_fill_color(Color::green);
  win.set_label("Canvas #7");
  win.wait_for_button();

  Text t{Point{150, 150}, "Hello, graphical world!"};
  win.attach(t);
  win.set_label("Canvas #8");
  win.wait_for_button();

  t.set_font(Graph_lib::Font::times_bold);
  t.set_font_size(20);
  win.set_label("Canvas #9");
  win.wait_for_button();

  Image ii{Point{100, 50}, "around_Dhaulagiri.jpg"};
  win.attach(ii);
  win.set_label("Canvas #10");
  win.wait_for_button();

  ii.move(100, 200);
  win.set_label("Canvas #11");
  win.wait_for_button();

  Graph_lib::Circle c{Point{100, 200}, 50};
  Graph_lib::Ellipse e{Point{100, 200}, 75, 25};
  e.set_color(Color::dark_red);
  Mark m{Point{100, 200}, 'x'};

  std::ostringstream oss;
  oss << "screen size: " << x_max() << "*" << y_max()
      << "; window size: " << win.x_max() << "*" << win.y_max();
  Text sizes{Point{100, 20}, oss.str()};

  Image cal{Point{225, 225}, "rafting_Adygeya.jpg"};
  cal.set_mask(Point{100, 300}, 200, 150);

  win.attach(c);
  win.attach(m);
  win.attach(e);

  win.attach(sizes);
  win.attach(cal);
  win.set_label("Canvas #12");
  win.wait_for_button();
} catch (std::exception& e) {
  std::cerr << e.what() << std::endl;
  return 1;
} catch (...) {
  std::cerr << "Oops, something went wrong..." << std::endl;
  return 2;
}
