#pragma once

#include <type_traits>
#include <utility>

/*
 * DEFINE_BINARY_INFIX_OPERATOR(op, func)
 *
 * Создаёт бинарный инфиксный оператор вида:
 *   left /op/ right
 *
 * Параметры:
 *   op   - имя оператора (будет создан тег и глобальная константа)
 *   func - функция, реализующая операцию (left, right) -> result
 *
 * Пример:
 *   DEFINE_BINARY_INFIX_OPERATOR(dot, dot_func)
 *   ...
 *   double result = a /dot/ b;
 *
 * Зависимости:
 *   - C++11 или новее (используется auto, decltype, std::decay_t)
 *   - <type_traits> для std::decay_t
 *   - <utility> для std::forward (опционально, но рекомендуется)
 */
#define DEFINE_BINARY_INFIX_OPERATOR(op, func)                                 \
  /* 1. Тег-маркер */                                                          \
  struct op##Tag {};                                                           \
  const op##Tag op;                                                            \
                                                                               \
  /* 2. Универсальный helper для любого левого типа */                         \
  template <typename LeftType>                                                 \
  struct op##Helper {                                                          \
    LeftType left;                                                             \
                                                                               \
    /* Конструктор для копирования */                                          \
    explicit op##Helper(const LeftType& l) : left(l) {}                        \
                                                                               \
    /* Конструктор для перемещения (оптимизация) */                            \
    explicit op##Helper(LeftType&& l) : left(std::move(l)) {}                  \
  };                                                                           \
                                                                               \
  /* 3. Перегрузка operator/ для (левый / тег) */                              \
  template <typename LeftType>                                                 \
  auto operator/(const LeftType& left, const op##Tag&) {                       \
    return op##Helper<LeftType>(left);                                         \
  }                                                                            \
                                                                               \
  /* 4. Перегрузка operator/ для rvalue (левая часть - временный объект) */    \
  template <typename LeftType>                                                 \
  auto operator/(LeftType&& left, const op##Tag&) {                            \
    return op##Helper<std::decay_t<LeftType>>(std::forward<LeftType>(left));   \
  }                                                                            \
                                                                               \
  /* 5. Основная перегрузка: helper / right */                                 \
  template <typename LeftType, typename RightType>                             \
  auto operator/(const op##Helper<LeftType>& helper, const RightType& right) { \
    return func(helper.left, right);                                           \
  }                                                                            \
                                                                               \
  /* 6. Перегрузка для rvalue right (для полноты) */                           \
  template <typename LeftType, typename RightType>                             \
  auto operator/(const op##Helper<LeftType>& helper, RightType&& right) {      \
    return func(helper.left, std::forward<RightType>(right));                  \
  }
