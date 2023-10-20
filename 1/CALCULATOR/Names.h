#include "Variable.h"
#pragma once


class Names{ // класс, описывающий список переменных и методы работы с ним
	private:
		// ветор вводимых пользователем переменных
		vector<Variable> names; 
	public: 
		// функция, отвечающая за получение значения переменной по имени, которое ей дал пользователь
		double get_value(string prob_name);
		// функция, отвечающая за передачу значения переменной по имени
		double set_value(string received_name, double received_value); 
		// функция, отвечающая за проверку существования переменной 
		bool is_declared(string prob_name);
		// функция, добавляющая новую переменную в ветор переменных, если пользователь ввёд её корректно 
		double define_name(string received_var, double val, bool is_const);
};

