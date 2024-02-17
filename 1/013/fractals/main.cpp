#include <iostream>
#include <sstream>
#include <stdexcept>

#include <Graph_lib/Graph.h>
#include <Graph_lib/Simple_window.h>
#include <Vector_lib/poly.h>
#include <Vector_lib/vec2d.h>
using namespace Graph_lib;
// using Graph_lib::pi;

double max_edge_length(const std::list<Vec2d>& curve);

void koch_fractal_step(std::list<Vec2d>& curve) {
  // assert (!curve.empty());
  auto prev = --curve.end();
  for (auto curr = curve.begin(); curr != curve.end(); ++curr) {
    auto p = lerp(*prev, *curr, 1. / 3);
    auto q = lerp(*prev, *curr, 2. / 3);
    auto m = rotated(pi / 3, p, q);
    curve.insert(curr, p);
    curve.insert(curr, m);
    curve.insert(curr, q);
    prev = curr;
  }
}

void draw_koch_snowflake(int w, int n) {
  Simple_window win{Point{100, 100}, w, w, "snowflake"};
  Vec2d c{w / 2., w / 2.};  // window center
  double r{0.85 * w / 2.};  // радиус описанной окружности
  auto ngon = regular_polygon(n, c, r, -pi / 2.);

  Text n_steps{as_point(c), "0"};
  n_steps.set_color(Color::blue);
  win.attach(n_steps);

  for (bool is_fine = false; !is_fine;) {
    Closed_polyline curve;
    append(curve, ngon);
    curve.set_color(Color::blue);
    koch_fractal_step(ngon);
    is_fine = max_edge_length(ngon) < 1.0;
    // std::cout << max_edge_length(ngon) << std::endl;
    if (is_fine)
      n_steps.set_color(Color::red);
    win.attach(curve);
    win.wait_for_button();
    win.detach(curve);
    n_steps.set_label(std::to_string(std::stoi(n_steps.label()) + 1));
  }
}

double max_edge_length(const std::list<Vec2d>& curve) {
  double m = 0;
  auto p = --curve.end();
  for (auto c = curve.begin(); c != curve.end(); ++c) {
    double d = length(*c - *p);
    // std::cout << "length d: " << d << std::endl;
    if (m < d)
      m = d;
  }
  return m;
}

int main() try { draw_koch_snowflake(400, 3); } catch (std::exception& e) {
  std::cerr << e.what() << std::endl;
  return 1;
} catch (...) {
  std::cerr << "Oops, something went wrong..." << std::endl;
  return 2;
}