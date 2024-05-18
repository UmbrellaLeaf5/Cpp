/*
Структура:

struct Point
{
    double x, y;
}
...
int main()
{
    Point p = {1.0, 2.0};
    p.x = 1.0;
    p.y = 2;
    std::vector <Point> points;
    points.push_back({1.0, 2.0});
}

Считывание из файла:
std::ifstream file("input.txt")
*/

#include <iostream>
#include <vector>
using namespace std;

// Создание новой структуры данных для точек (x, y)
struct Point {
  double x, y;
};

// Перегрузка операции ввода для более удобного записывания данных в vector<Point>
istream& operator>>(std::istream& is, Point& rhs) {
  return is >> rhs.x >> rhs.y;
}

// Реализация функций _x и _y
double vec__x(vector<Point> a) {
  double result = 0;
  for (unsigned long long i = 0; i < a.size(); i++) {
    result += a[i].x;
  }
  return result / a.size();
}

double vec__y(vector<Point> a) {
  double result = 0;
  for (unsigned long long i = 0; i < a.size(); i++) {
    result += a[i].y;
  }
  return result / a.size();
}

// Реализация функции, которая считает _(xy)
double vec__xy(vector<Point> a) {
  double result = 0;
  for (unsigned long long i = 0; i < a.size(); i++) {
    result += a[i].x * a[i].y;
  }
  return result / a.size();
}

// Реализация функции, которая считает _(x^2)
double vec__x_sqr(vector<Point> a) {
  double result = 0;
  for (unsigned long long i = 0; i < a.size(); i++) {
    result += a[i].x * a[i].x;
  }
  return result / a.size();
}

// Реализация главной функции
int main() {
  // Вектор с нашими значениями и считывание данных в него
  vector<Point> values;
  cout << "Enter x and y values." << endl;
  for (Point temp; cin >> temp;) {
    values.push_back(temp);
  }

  // Высчитывание коэф. a и b и их вывод
  double a, b;
  b = (vec__xy(values) - vec__x(values) * vec__y(values)) /
      (vec__x_sqr(values) - vec__x(values) * vec__x(values));
  a = vec__y(values) - b * vec__x(values);
  cout << "a = " << a << endl << "b = " << b << endl;
  system("pause");
}