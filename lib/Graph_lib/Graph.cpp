#include <algorithm>
#include <fstream>
#include <map>
#include <random>
#include <stdexcept>

#include "Graph.h"

namespace Graph_lib {

[[noreturn]] void error(const std::string& msg) {
  throw std::runtime_error{msg};
}

[[noreturn]] void error(const std::string& msg, const std::string& msg2) {
  error(msg + msg2);
}

int randint(int min, int max) {
  static std::default_random_engine ran;
  return std::uniform_int_distribution<>{min, max}(ran);
}

int randint(int max) {
  return randint(0, max);
}

Shape::Shape(std::initializer_list<Point> lst) {
  for (Point p : lst)
    add(p);
}

void Shape::draw_lines() const {
  if (color().visibility() && 1 < points.size())  // draw sole pixel?
    for (unsigned int i = 1; i < points.size(); ++i)
      fl_line(points[i - 1].x, points[i - 1].y, points[i].x, points[i].y);
}

void Shape::draw() const {
  Fl_Color oldc =
      fl_color();  // there is no good portable way of retrieving the current style
  fl_color(lcolor.as_int());
  fl_line_style(ls.style(), ls.width());
  draw_lines();
  fl_color(oldc);  // reset color (to pevious) and style (to default)
  fl_line_style(0);
}

inline std::pair<double, double> line_intersect(Point p1, Point p2, Point p3,
                                                Point p4, bool& parallel)
// does two lines (p1,p2) and (p3,p4) intersect?
// if yes return the distance of the intersect point as distances from p1
{
  double x1 = p1.x;
  double x2 = p2.x;
  double x3 = p3.x;
  double x4 = p4.x;
  double y1 = p1.y;
  double y2 = p2.y;
  double y3 = p3.y;
  double y4 = p4.y;

  double denom = (y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1);
  if (denom == 0) {
    parallel = true;
    return std::make_pair(0., 0.);
  }
  parallel = false;
  return std::make_pair(
      ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / denom,
      ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / denom);
}

bool line_segment_intersect(Point p1, Point p2, Point p3, Point p4,
                            Point& intersection)
// intersection between two line segments
// Returns true if the two segments intersect,
// in which case intersection is set to the point of intersection
{
  bool parallel;
  std::pair<double, double> u = line_intersect(p1, p2, p3, p4, parallel);

  if (parallel || u.first < 0 || u.first > 1 || u.second < 0 || u.second > 1)
    return false;

  intersection.x = p1.x + u.first * (p2.x - p1.x);
  intersection.y = p1.y + u.first * (p2.y - p1.y);
  return true;
}

void Polygon::add(Point p) {
  int np = number_of_points();

  // check that the new line isn't parallel to the previous one
  if (1 < np) {
    if (p == point(np - 1))
      error("polygon point equal to previous point");

    bool parallel;
    line_intersect(point(np - 1), p, point(np - 2), point(np - 1), parallel);

    if (parallel)
      error("two polygon points lie in a straight line");
  }

  // check that new segment doesn't interset and old point
  for (int i = 1; i < np - 1; ++i) {
    Point ignore{0, 0};
    if (line_segment_intersect(point(np - 1), p, point(i - 1), point(i),
                               ignore))
      error("intersect in polygon");
  }

  Closed_polyline::add(p);
}

void Polygon::draw_lines() const {
  if (number_of_points() < 3)
    error("less than 3 points in a Polygon");
  Closed_polyline::draw_lines();
}

void Open_polyline::draw_lines() const {
  if (fill_color().visibility()) {
    fl_color(fill_color().as_int());
    fl_begin_complex_polygon();
    for (int i = 0; i < number_of_points(); ++i) {
      fl_vertex(point(i).x, point(i).y);
    }
    fl_end_complex_polygon();
    fl_color(color().as_int());  // reset color
  }

  if (color().visibility())
    Shape::draw_lines();
}

void Closed_polyline::draw_lines() const {
  Open_polyline::draw_lines();

  if (color().visibility())  // draw closing line
    fl_line(point(number_of_points() - 1).x, point(number_of_points() - 1).y,
            point(0).x, point(0).y);
}

void Shape::move(int dx, int dy) {
  for (unsigned int i = 0; i < points.size(); ++i) {
    points[i].x += dx;
    points[i].y += dy;
  }
}

Shape::~Shape() { /* all done */
}

void Lines::draw_lines() const {
  if (color().visibility())
    for (int i = 1; i < number_of_points(); i += 2)
      fl_line(point(i - 1).x, point(i - 1).y, point(i).x, point(i).y);
}

void Text::draw_lines() const {
  int ofnt = fl_font();
  int osz = fl_size();
  fl_font(fnt.as_int(), fnt_sz);
  fl_draw(lab.c_str(), point(0).x, point(0).y);
  fl_font(ofnt, osz);
}

Function::Function(Fct f, double r1, double r2, Point xy, int count,
                   double xscale, double yscale)
// graph f(x) for x in [r1:r2) using count line segments with (0,0) displayed at xy
// x coordinates are scaled by xscale and y coordinates scaled by yscale
{
  if (r2 - r1 <= 0)
    error("bad graphing range");
  if (count <= 0)
    error("non-positive graphing count");
  double dist = (r2 - r1) / count;
  double r = r1;
  for (int i = 0; i < count; ++i) {
    add(Point{xy.x + int(r * xscale), xy.y - int(f(r) * yscale)});
    r += dist;
  }
}

void Rectangle::draw_lines() const {
  if (fill_color().visibility())  // fill
  {
    fl_color(fill_color().as_int());
    fl_rectf(point(0).x, point(0).y, w, h);
    fl_color(color().as_int());  // reset color
  }

  if (color().visibility())  // edge on top of fill
    fl_rect(point(0).x, point(0).y, w, h);
}

Axis::Axis(Orientation d, Point xy, int length, int n, const std::string& lab)
    : label{Point{0, 0}, lab} {
  if (length < 0)
    error("bad axis length");

  switch (d) {
    case Axis::x: {
      Shape::add(xy);                          // axis line
      Shape::add(Point{xy.x + length, xy.y});  // axis line
      if (1 < n) {
        int dist = length / n;
        int x = xy.x + dist;
        for (int i = 0; i < n; ++i) {
          notches.add(Point{x, xy.y}, Point{x, xy.y - 5});
          x += dist;
        }
      }
      // label under the line
      label.move(length / 3, xy.y + 20);
      break;
    }
    case Axis::y: {
      Shape::add(xy);  // an y-axis goes up
      Shape::add(Point{xy.x, xy.y - length});
      if (1 < n) {
        int dist = length / n;
        int y = xy.y - dist;
        for (int i = 0; i < n; ++i) {
          notches.add(Point{xy.x, y}, Point{xy.x + 5, y});
          y -= dist;
        }
      }
      // label at top
      label.move(xy.x - 10, xy.y - length - 10);
      break;
    }
    case Axis::z:
      error("z axis not implemented");
  }
}

void Axis::draw_lines() const {
  Shape::draw_lines();  // the line
  notches.draw();       // the notches may have a different color from the line
  label.draw();         // the label may have a different color from the line
}

void Axis::set_color(Color c) {
  Shape::set_color(c);
  notches.set_color(c);
  label.set_color(c);
}

void Axis::move(int dx, int dy) {
  Shape::move(dx, dy);
  notches.move(dx, dy);
  label.move(dx, dy);
}

void Circle::draw_lines() const {
  if (fill_color().visibility())  // fill
  {
    fl_color(fill_color().as_int());
    fl_pie(point(0).x, point(0).y, r + r - 1, r + r - 1, 0, 360);
    fl_color(color().as_int());  // reset color
  }

  if (color().visibility())
    fl_arc(point(0).x, point(0).y, r + r, r + r, 0, 360);
}

void Ellipse::draw_lines() const {
  if (fill_color().visibility())  // fill
  {
    fl_color(fill_color().as_int());
    fl_pie(point(0).x, point(0).y, w + w - 1, h + h - 1, 0, 360);
    fl_color(color().as_int());  // reset color
  }

  if (color().visibility())
    fl_arc(point(0).x, point(0).y, w + w, h + h, 0, 360);
}

Point Ellipse::focus1() const {
  double d = std::round(std::sqrt(double(w * w - h * h)));
  return {center().x + int(d), center().y};
}

Point Ellipse::focus2() const {
  double d = std::round(std::sqrt(double(w * w - h * h)));
  return {center().x - int(d), center().y};
}

void Ellipse::set_major(int ww) {
  // maintain the center
  set_point(0, Point{center().x - ww, center().y - h});
  w = ww;
}

void Ellipse::set_minor(int hh) {
  // maintain the center
  set_point(0, Point{center().x - w, center().y - hh});
  h = hh;
}

void draw_mark(Point xy, char c) {
  static const int dx = 4;
  static const int dy = 4;
  std::string m{c};
  fl_draw(m.c_str(), xy.x - dx, xy.y + dy);
}

Marked_polyline::Marked_polyline(const std::string& m,
                                 std::initializer_list<Point> lst)
    : Open_polyline{lst}, mark{m} {
  if (m == "")
    mark = "*";
}

void Marked_polyline::draw_lines() const {
  Open_polyline::draw_lines();
  for (int i = 0; i < number_of_points(); ++i)
    draw_mark(point(i), mark[i % mark.size()]);
}

std::map<std::string, Suffix::Encoding> suffix_map;

int init_suffix_map() {
  suffix_map["png"] = Suffix::png;
  suffix_map["PNG"] = Suffix::png;
  suffix_map["jpg"] = Suffix::jpg;
  suffix_map["JPG"] = Suffix::jpg;
  suffix_map["jpeg"] = Suffix::jpg;
  suffix_map["JPEG"] = Suffix::jpg;
  suffix_map["gif"] = Suffix::gif;
  suffix_map["GIF"] = Suffix::gif;
  suffix_map["bmp"] = Suffix::bmp;
  suffix_map["BMP"] = Suffix::bmp;
  return 0;
}

Suffix::Encoding get_encoding(const std::string& s)
// try to deduce type from file name using a lookup table
{
  [[maybe_unused]] static int x = init_suffix_map();

  std::string::const_iterator p = std::find(s.begin(), s.end(), '.');
  if (p == s.end())
    return Suffix::none;  // no suffix

  std::string suf{p + 1, s.end()};
  return suffix_map[suf];
}

bool can_open(const std::string& s)
// check if a file named s exists and can be opened for reading
{
  return static_cast<bool>(std::ifstream{s});
}

Image::Image(Point xy, const std::string& s, Suffix::Encoding e)
    : w{0},
      h{0},
      fn{xy, ""}  // somewhat overelaborate constructor
// because errors related to image files can be such a pain to debug
{
  add(xy);

  if (!can_open(s)) {
    fn.set_label("cannot open \"" + s + '\"');
    p = new Bad_image{30, 20};  // the "error image"
    return;
  }

  if (e == Suffix::none)
    e = get_encoding(s);

  switch (e) {
    case Suffix::png:
      p = new Fl_PNG_Image{s.c_str()};
      break;
    case Suffix::jpg:
      p = new Fl_JPEG_Image{s.c_str()};
      break;
    case Suffix::gif:
      p = new Fl_GIF_Image{s.c_str()};
      break;
    default:  // Unsupported image encoding
      fn.set_label("unsupported file type \"" + s + '\"');
      p = new Bad_image{30, 20};  // the "error image"
  }
}

void Image::draw_lines() const {
  if (fn.label() != "")
    fn.draw_lines();

  if (w && h)
    p->draw(point(0).x, point(0).y, w, h, cx, cy);
  else
    p->draw(point(0).x, point(0).y);
}

}  // namespace Graph_lib
