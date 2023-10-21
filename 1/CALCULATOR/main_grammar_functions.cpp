#include "std_lib_facilities.h"
#include <cmath>

#include "Token.h"
#include "const_kinds.h"
#include "main_grammar_functions.h"
#include "calculator_globals.h"

double primary() 
{
	Token received_token = ts.get();
	switch (received_token.kind) 
	{
		// кейс для выражение в скобках
		case '(':
		{	
			double received_expression = expression(); // вызываем чтение выражения
			received_token = ts.get();
			if (received_token.kind != ')')
			{
				ts.unget(received_token);
				error("')' expected");
			}
			return received_expression;
		}
		case '{':
		{	
			double received_expression = expression(); // вызываем чтение выражения
			received_token = ts.get();
			if (received_token.kind != '}') 
			{
				ts.unget(received_token);
				error("'}' expected");
			}
			return received_expression;
		}
		// кейс для отрицательного первичного выражения
		case '-': 
			return -primary();
		// кейс, если пользователь решит начать перв. выраж. с плюса
		case '+':
			return primary();
		// кейс для числа
		case number:
			return received_token.value;
		// кейс для уже существующей переменной
		case name: 
		{
			if(!nm.is_declared(received_token.name)) // проверяем существование переменной в списке имён
				error(received_token.name + ": is not declared");
			Token received_token_2 = ts.get(); // вспомогательный токен для получения значения после левой части
			// проверяем, что мы вводим после имени перменной
			if(received_token_2.kind == '='){ 
				double var_value = expression();
				return nm.set_value(received_token.name, var_value);
			}
			else{
				ts.unget(received_token_2); // возвращаем вспомогательный токен в поток
				return nm.get_value(received_token.name);
			}
		}
		// кейс для квадратного корня
		case square_root:
		{
			received_token = ts.get();
			if (received_token.kind == '(') 
			{
				double received_expression = expression();
				received_token = ts.get();
				if (received_token.kind != ')')
					error("'(' expected");
				if (received_expression >= 0) // проверка на то, что берем корень неотрицательного числа
					return sqrt(received_expression);
				else
					error("square root of a negative number");
			}
		else
			error("'(' expected");
		}
		// кейс для возведения в степень
		case power:
		{
			received_token = ts.get();
			if (received_token.kind == '(') 
			{
				double base_number = expression(); // переменная - основание
				received_token = ts.get();
				if (received_token.kind != comma) // за первым аргументом должна следовать запятая
				{
					ts.unget(received_token.kind);
					error("',' expected");
				}
				// переменная - показатель
				int power_number = narrow_cast<int>(expression()); // "сужение" значения с потерей информации и генерацией исключения в противном случае
				received_token = ts.get();
				if (received_token.kind != ')')
				{
					ts.unget(received_token.kind);
					error("')' expected");
				}
				return pow(base_number, power_number);
			}
			else
			{
				ts.unget(received_token.kind);
				error("'(' expected");
			}
		}
		// кейс, если мы не получили, чего хотели
		default:
			ts.unget(received_token);
			error("primary expected");
	}
}


double term() 
{
	double left_part = primary();
	for(;;) {
		Token received_token = ts.get();
		switch (received_token.kind) 
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
				double received_right_part = primary(); // считывание первичного выражения справа
				if (received_right_part == 0) // ошибка, связанная с делением на ноль
					error("/: divide by zero");
				left_part /= received_right_part;
				break;
			}
			// кейс для остатка от деления
			case '%':
			{
				double received_right_part = primary(); // считывание первичного выражения справа
				if (received_right_part == 0) // ошибка, связанная с делением на ноль
					error("%: divided by zero");
				left_part = fmod(left_part, received_right_part); // фукция из cmath, вычисляющая остаток с плавающей запятой
				break;
			}
			// кейс, когда терм закончился
			default:
			{
				ts.unget(received_token); // возвращаем токен в поток
				return left_part;
			}
		}
	}
}

double expression() 
{
	double left_part = 0;
	Token received_token = ts.get();
	if (received_token.kind == name) {
		Token received_token_2 = ts.get(); // дополнительный токен для корректного получения значения переменной
		// если получаем на вход '=' это присваивание
		if (received_token_2.kind == '=') {
			double var_value = expression();
			left_part = nm.set_value(received_token.name, var_value);
		}
		// если получаем на вход операции терма, то... не вышло исправить баг, связанный с этим :(
		else if (received_token_2.kind == '*' || received_token_2.kind == '/' || received_token_2.kind == '%')
		{
			ts.unget(received_token_2);
			ts.unget(received_token);
			left_part = term();
		}
		else {
			ts.unget(received_token_2);
			left_part = nm.get_value(received_token.name);
		}
	}
	else {
		ts.unget(received_token);
		left_part = term();
	}
	for(;;) {
		received_token = ts.get();
		switch (received_token.kind) {
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
				ts.unget(received_token); // возвращаем токен в поток
				return left_part;
		}
	}
}

double declaration(bool is_const)  
{
	Token received_token = ts.get();
	if (received_token.kind != name){ // полученное при вводе не соотв. заданным правилам для имени переменной
		ts.unget(received_token); // возвращаем токен в поток
		error("name expected in declaration");
	}
	string var_name = received_token.name; // присваиваем строке имя полученного из потока токена
	Token received_token_2 = ts.get(); // используем второй токен, чтобы проверить присваивание значения для переменной
	if (received_token_2.kind != '='){
		ts.unget(received_token_2);
		error("=: missing in declaration of ", var_name);
	}
	double received_var_value = expression(); // получаем значение переменной - выражение
	nm.define_name(var_name, received_var_value, is_const); // при успехе - запоминаем переменную в программу
	return received_var_value;
}

double statement() 
{
	Token received_token = ts.get();
	switch (received_token.kind) 
	{
		// кейс для объявления
		case let: 
			return declaration(false);
		// кейс для констант
		case cnst:
			return declaration(true);
		// кейс для выражения
		default:
			ts.unget(received_token);
			return expression();
	}
}
