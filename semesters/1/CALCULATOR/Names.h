#pragma once

#include "Variable.h"

class Names
{  // класс, описывающий список переменных и методы работы с ним
  private:
    // ветор вводимых пользователем переменных
    vector<Variable> names;

  public:
    // функция, отвечающая за получение значения переменной по имени, которое ей дал пользователь
    double get_value (const string& prob_name) const;
    // функция, отвечающая за передачу значения переменной по имени
    double set_value (string rec_name, double rec_value);
    // функция, отвечающая за проверку существования переменной
    bool is_declared (const string& prob_name) const;
    // функция, добавляющая новую переменную в ветор переменных, если пользователь ввёд её корректно
    double define_name (string var_name, double value, bool is_const);
};
