#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "./binary_infix_operator.hpp"

// ============================================
// 1. Dot product function
// ============================================

template <typename T>
T dot_func(const std::vector<T>& a, const std::vector<T>& b) {
  if (a.size() != b.size())
    throw std::runtime_error("Dot product: vectors must have same size");

  T result = 0;

  for (size_t i = 0; i < a.size(); ++i) result += a[i] * b[i];

  return result;
}

// ============================================
// 2. Cross product function
// ============================================

template <typename T>
std::vector<T> cross_func(const std::vector<T>& a, const std::vector<T>& b) {
  if (a.size() != 3 || b.size() != 3)
    throw std::runtime_error(
        "Cross product: both vectors must be 3-dimensional");

  return {a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2],
          a[0] * b[1] - a[1] * b[0]};
}

// ============================================
// 3. Additional: useful functions
// ============================================

// Vector norm
template <typename T>
T norm_func(const std::vector<T>& v) {
  return std::sqrt(dot_func(v, v));
}

// Angle between vectors (in radians)
template <typename T>
double angle_func(const std::vector<T>& a, const std::vector<T>& b) {
  T dot = dot_func(a, b);
  T norm_a = norm_func(a);
  T norm_b = norm_func(b);

  if (norm_a == 0 || norm_b == 0)
    throw std::runtime_error("Angle: zero vector detected");

  return std::acos(dot / (norm_a * norm_b));
}

// Orthogonality check
template <typename T>
bool is_orthogonal_func(const std::vector<T>& a, const std::vector<T>& b,
                        T epsilon = 1e-9) {
  return std::abs(dot_func(a, b)) < epsilon;
}

// ============================================
// 4. Create operators using the macro
// ============================================

// Create operators
DEFINE_BINARY_INFIX_OPERATOR(dot, dot_func)
DEFINE_BINARY_INFIX_OPERATOR(cross, cross_func)
DEFINE_BINARY_INFIX_OPERATOR(angle, angle_func)
DEFINE_BINARY_INFIX_OPERATOR(orthogonal, is_orthogonal_func)

// ============================================
// 5. Utilities for pretty printing
// ============================================

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
  os << "[";

  for (size_t i = 0; i < v.size(); ++i) {
    os << v[i];
    if (i < v.size() - 1) os << ", ";
  }

  os << "]";

  return os;
}

// ============================================
// 6. Usage example
// ============================================

int main() {
  try {
    // Prepare data
    std::vector<double> a = {1.0, 2.0, 3.0};
    std::vector<double> b = {4.0, 5.0, 6.0};
    std::vector<double> c = {7.0, 8.0, 9.0};
    std::vector<double> d = {1.0, 2.0, 3.0};  // same vector as a

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << std::endl;

    // ===== Dot product =====

    std::cout << "a /dot/ b = " << a / dot / b << std::endl;
    std::cout << "a /dot/ c = " << a / dot / c << std::endl;
    std::cout << "a /dot/ d = " << a / dot / d << std::endl;
    std::cout << std::endl;

    // ===== Cross product =====

    std::cout << "a /cross/ b = " << a / cross / b << std::endl;
    std::cout << "b /cross/ c = " << b / cross / c << std::endl;
    std::cout << "a /cross/ d = " << a / cross / d << std::endl;
    std::cout << std::endl;

    // ===== Vector norm =====
    double norm_a = norm_func(a);
    std::cout << "||a|| = " << norm_a << std::endl;
    std::cout << std::endl;

    // ===== Angle between vectors =====

    std::cout << "a /angle/ b = " << a / angle / b << " rad" << std::endl;
    std::cout << "a /angle/ d = " << a / angle / d << " rad" << std::endl;
    std::cout << std::endl;

    // ===== Orthogonality check =====

    std::cout << "a /orthogonal/ b = " << std::boolalpha << a / orthogonal / b
              << std::endl;
    std::cout << "a /orthogonal/ c = " << std::boolalpha << a / orthogonal / c
              << std::endl;
    std::cout << "a /orthogonal/ d = " << std::boolalpha << a / orthogonal / d
              << std::endl;
    std::cout << std::endl;

    // ===== Cross product properties =====
    // (a × b) · a = 0 (orthogonality)
    double check1 = (a / cross / b) / dot / a;
    double check2 = (a / cross / b) / dot / b;

    std::cout << "Property verification:" << std::endl;
    std::cout << "(a × b) · a = " << check1 << " (should be 0)" << std::endl;
    std::cout << "(a × b) · b = " << check2 << " (should be 0)" << std::endl;
    std::cout << std::endl;

    // ===== Triple product =====
    // (a × b) · c = a · (b × c)
    double triple1 = (a / cross / b) / dot / c;
    double triple2 = a / dot / (b / cross / c);

    std::cout << "Triple product:" << std::endl;
    std::cout << "(a × b) · c = " << triple1 << std::endl;
    std::cout << "a · (b × c) = " << triple2 << std::endl;
    std::cout << "Are they equal? " << (std::abs(triple1 - triple2) < 1e-9)
              << std::endl;

  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
