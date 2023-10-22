#include "std_lib_facilities.h"
#include <cmath>

#include "Token.h"
#include "const_kinds.h"
#include "main_grammar_functions.h"
#include "calculator_globals.h"

double primary() 
{
	Token rec_t = ts.get();
	switch (rec_t.kind) 
	{
		// кейс для выражение в скобках
		case '(':
		{	
			double rec_expr = expression(); // вызываем чтение выражения
			rec_t = ts.get();
			if (rec_t.kind != ')'){
				ts.unget(rec_t);
				error("')' expected");
			}
			return rec_expr;
		}
		case '{':
		{	
			double rec_expr = expression(); // вызываем чтение выражения
			rec_t = ts.get();
			if (rec_t.kind != '}'){
				ts.unget(rec_t);
				error("'}' expected");
			}
			return rec_expr;
		}
		// кейс для отрицательного первичного выражения
		case '-': 
			return -primary();
		// кейс, если пользователь решит начать перв. выраж. с плюса
		case '+':
			return primary();
		// кейс для числа
		case number:
			return rec_t.value;
		// кейс для уже существующей переменной
		case name: 
		{
			Token rec_t_2 = ts.get(); // вспомогательный токен для получения значения после левой части
			// проверяем, что мы вводим после имени перменной
			if(rec_t_2.kind == '='){ 
				double var_value = expression();
				return nm.set_value(rec_t.name, var_value);
			}
			else{
				ts.unget(rec_t_2); // возвращаем вспомогательный токен в поток
				return nm.get_value(rec_t.name);
			}
		}
		// кейс для квадратного корня
		case square_root:
		{
			rec_t = ts.get();
			if (rec_t.kind == '(') 
			{
				double rec_expr = expression();
				rec_t = ts.get();
				if (rec_t.kind != ')'){
					ts.unget(rec_t);
					error("'(' expected");
				}
				if (rec_expr >= 0) // проверка на то, что берем корень неотрицательного числа
					return sqrt(rec_expr);
				else{
					ts.unget(rec_t);
					error("square root of a negative number");
				}
			}
			else{
				ts.unget(rec_t);
				error("'(' expected");
			}
		}
		// кейс для возведения в степень
		case power:
		{
			rec_t = ts.get();
			if (rec_t.kind == '(') 
			{
				double base_number = expression(); // переменная - основание
				rec_t = ts.get();
				if (rec_t.kind != comma){ // за первым аргументом должна следовать запятая
					ts.unget(rec_t);
					error("',' expected");
				}
				// переменная - показатель
				int power_number = narrow_cast<int>(expression()); // "сужение" значения с потерей информации и генерацией исключения в противном случае
				rec_t = ts.get();
				if (rec_t.kind != ')'){
					ts.unget(rec_t);
					error("')' expected");
				}
				return pow(base_number, power_number);
			}
			else{
				ts.unget(rec_t);
				error("'(' expected");
			}
		}
		// кейс, если мы не получили, чего хотели
		default:
		{
			ts.unget(rec_t);
			error("primary expected");
		}
	}
}


double term() 
{
	double left_part = primary();
	for(;;) {
		Token rec_t = ts.get();
		switch (rec_t.kind) 
		{
			// кейс для умножения
			case '*':
			{
				left_part *= primary(); // не объявляю правое первичное выражение за отдельную переменную, но имею это в виду
				break;
			}
			// кейс для деления
			case '/':
			{
				double right_part = primary(); // считывание первичного выражения справа
				if (right_part == 0){ // ошибка, связанная с делением на ноль
					ts.unget(rec_t);
					error("/: divide by zero");
				}
				left_part /= right_part;
				break;
			}
			// кейс для остатка от деления
			case '%':
			{
				double right_part = primary(); // считывание первичного выражения справа
				if (right_part == 0){ // ошибка, связанная с делением на ноль
					ts.unget(rec_t);
					error("%: divided by zero");
				}
				left_part = fmod(left_part, right_part); // фукция из cmath, вычисляющая остаток с плавающей запятой
				break;
			}
			// кейс, когда терм закончился
			default:
			{
				ts.unget(rec_t); // возвращаем токен в поток
				return left_part;
			}
		}
	}
}

double expression() 
{
	double left_part = 0;
	Token rec_t = ts.get();
	if (rec_t.kind == name) 
	{
		if(!nm.is_declared(rec_t.name)) // проверяем существование переменной в списке имён
			error(rec_t.name + ": is not declared");
		Token rec_t_2 = ts.get(); // дополнительный токен для корректного получения значения переменной
		// если получаем на вход '=' это присваивание
		if (rec_t_2.kind == '=') {
			double var_value = expression();
			left_part = nm.set_value(rec_t.name, var_value);
		}
		else if (rec_t_2.kind == '*' || rec_t_2.kind == '%' || rec_t_2.kind == '/')
		{
			ts.unget(rec_t_2);
			ts.unget(rec_t);
			left_part = primary();
		}
		else {
			ts.unget(rec_t_2);
			left_part = nm.get_value(rec_t.name);
		}
	}
	else {
		ts.unget(rec_t);
		left_part = term();
	}
	for(;;) {
		rec_t = ts.get();
		switch (rec_t.kind) {
			// кейс для сложения
			case '+':
				left_part += term(); // не объявляю правый терм за отдельную переменную
				break;
			// кейс для вычитания
			case '-':
				left_part -= term();
				break;
			// кейс, когда выражение закончилось
			default: 
				ts.unget(rec_t); // возвращаем токен в поток
				return left_part;
		}
	}
}

double declaration(bool is_const)  
{
	Token rec_t = ts.get();
	if (rec_t.kind != name){ // полученное при вводе не соотв. заданным правилам для имени переменной
		ts.unget(rec_t); // возвращаем токен в поток
		error("name expected in declaration");
	}
	string var_name = rec_t.name; // присваиваем строке имя полученного из потока токена
	Token rec_t_2 = ts.get(); // используем второй токен, чтобы проверить присваивание значения для переменной
	if (rec_t_2.kind != '='){
		ts.unget(rec_t_2);
		error("=: missing in declaration of ", var_name);
	}
	double var_value = expression(); // получаем значение переменной - выражение
	nm.define_name(var_name, var_value, is_const); // при успехе - запоминаем переменную в программу
	return var_value;
}

double statement() 
{
	Token rec_t = ts.get();
	switch (rec_t.kind) 
	{
		// кейс для объявления
		case let: 
			return declaration(false);
		// кейс для констант
		case cnst:
			return declaration(true);
		// кейс для выражения
		default:
			ts.unget(rec_t);
			return expression();
	}
}
