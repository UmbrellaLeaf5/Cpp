#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>

#define INFIX_OPERATOR(op) / op /

#define DOT INFIX_OPERATOR(dot)
#define CROSS INFIX_OPERATOR(cross)

// ============================================
// 1. Tag types for our "pseudo-operators"
// ============================================

struct DotProductTag {};
struct CrossProductTag {};

// Global constants for use in expressions
const DotProductTag dot;
const CrossProductTag cross;

// ============================================
// 2. Helper classes that store the left operand
// ============================================

template <typename T>
struct DotProductHelper {
  const std::vector<T>& left;
};

template <typename T>
struct CrossProductHelper {
  const std::vector<T>& left;
};

// ============================================
// 3. operator/ overload for (vector / tag)
// ============================================

// For dot product
template <typename T>
DotProductHelper<T> operator/(const std::vector<T>& left,
                              const DotProductTag&) {
  return DotProductHelper<T>{left};
}

// For cross product
template <typename T>
CrossProductHelper<T> operator/(const std::vector<T>& left,
                                const CrossProductTag&) {
  return CrossProductHelper<T>{left};
}

// ============================================
// 4. operator/ overload for (helper / vector)
// ============================================

// Dot product: returns T
template <typename T>
T operator/(const DotProductHelper<T>& helper, const std::vector<T>& right) {
  if (helper.left.size() != right.size())
    throw std::runtime_error("Dot product: vectors must have same size");

  auto size = right.size();

  T result = 0;

  for (size_t i = 0; i < size; ++i) result += helper.left[i] * right[i];

  return result;
}

// Cross product: returns std::vector<T> (3D only)
template <typename T>
std::vector<T> operator/(const CrossProductHelper<T>& helper,
                         const std::vector<T>& right) {
  if (helper.left.size() != 3 || right.size() != 3)
    throw std::runtime_error(
        "Cross product: both vectors must be 3-dimensional");

  return {helper.left[1] * right[2] - helper.left[2] * right[1],
          helper.left[2] * right[0] - helper.left[0] * right[2],
          helper.left[0] * right[1] - helper.left[1] * right[0]};
}

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
// 6. Additional: vector norm via dot product
// ============================================

template <typename T>
T norm(const std::vector<T>& v) {
  return std::sqrt(v DOT v);
}

// ============================================
// 7. Usage example
// ============================================

int main() {
  try {
    // Prepare data

    std::vector<double> a = {1.0, 2.0, 3.0};
    std::vector<double> b = {4.0, 5.0, 6.0};
    std::vector<double> c = {7.0, 8.0, 9.0};

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << std::endl;

    // ===== Dot product =====

    std::cout << "a /dot/ b = " << a DOT b << std::endl;
    std::cout << "a /dot/ c = " << a DOT c << std::endl;
    std::cout << std::endl;

    // ===== Cross product =====
    auto cross_ab = a CROSS b;
    auto cross_bc = b CROSS c;

    std::cout << "a /cross/ b = " << cross_ab << std::endl;
    std::cout << "b /cross/ c = " << cross_bc << std::endl;
    std::cout << std::endl;

    // ===== Property verification =====
    // Cross product is orthogonal to the original vectors
    std::cout << "Orthogonality check:" << std::endl;
    std::cout << "a · (a × b) = " << (a DOT cross_ab) << " (should be 0)"
              << std::endl;
    std::cout << "b · (a × b) = " << (b DOT cross_ab) << " (should be 0)"
              << std::endl;
    std::cout << std::endl;

    // ===== Vector norm =====
    std::cout << "||a|| = " << norm(a) << std::endl;
    std::cout << "||b|| = " << norm(b) << std::endl;

    // ===== Error handling =====
    std::vector<double> d = {1.0, 2.0};  // 2D vector

    try {
      auto bad = d CROSS a;  // Error: dimensions don't match

    } catch (const std::exception& e) {
      std::cout << "\nError (expected): " << e.what() << std::endl;
    }

  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
