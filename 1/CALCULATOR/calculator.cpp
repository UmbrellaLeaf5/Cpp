/*
	Грамматика:

	Инструкция:
		Выражение
		Вывод
		Выход
	Вывод:
		;
	Выход:
		quit
	Выражение:
		Терм
		Выражение + Терм
		Выражение - Терм
	Терм:
		Первичное_выражение
		Терм * Первичное_выражение
		Терм / Первичное_выражение
		Переменная Терм % Первичное_выражение
	Первичное_выражение:
		Число
		( Выражение )
		- Первичное_выражение
		Переменная + Первичное_выражение
	Число:
		Литерал_с_плавающей_точкой
*/

#include "std_lib_facilities.h"
#include <cmath>

// структура токена (у него есть тип, значение и (возможно) имя переменной)
struct Token { 
	char kind;
	double value;
	string name;
	//использование конструкторов для разных вариантов использования токена (числового значения, ключевого слова, имени переменной и т.п.)
	Token(char received_char) : kind(received_char), value(0) { }
	Token(char received_char, double val) : kind(received_char), value(val) { }
	Token(char received_char, string n) : kind(received_char), value(0), name(n) { }
};

// поток с буфером для чтения токенов
class Token_stream { 
	bool is_full; // переменная, отвечающая за переполнение потока токенов
	Token buffer; // "буферный" считываемый токен
public:
	Token_stream() : is_full(0), buffer(0) { }

	// функция, отвечающая за получение следующего токена из потока
	Token get(); 
	// функция, отвечающая за возврат токена в поток токенов
	void unget(Token t) { buffer = t; is_full = true; } 

	// функция, отвечающая за игнорирование ввода токенов до появления символа, переданного как аргумент
	void ignore(char last_ignore_char); 
};

// константы, обозначающие типы получаемых токенов (в самой структуре токенов используеются именно они)
const char let = 'L';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';

Token Token_stream::get()
{
	// если в буфере есть токен, забираем его оттуда
	if (is_full) { 
		is_full = false; 
		return buffer; 
	} 
	char received_char; 
	cin >> received_char;
	switch (received_char) 
	{
		// кейсы для операторов
		case '(': case ')': case '+': case '-':
		case '*': case '/': case '%': 
		case ';': case '=':
			return Token(received_char);
		// кейсы для чисел
		case '0': case '1': case '2': case '3': case '4': 
		case '5': case '6': case '7': case '8': case '9': 
		{
			cin.unget(); // возвращаем предыдущий символ в стандартный поток ввода
			double received_value;
			cin >> received_value;
			return Token(number, received_value);
		}
		// кейс для переменных или служебных слов типа 'let', 'quit'
		default: 
		{
			if (isalpha(received_char)) 
			{
				string input_string;
				input_string += received_char;
				while (cin.get(received_char) && (isalpha(received_char) || isdigit(received_char))) 
					// читаем посимвольно слово (из букв и цифр)
					input_string += received_char; 
				cin.unget();
				// если получены служебные слова, организуем соотв. действия в токене
				if (input_string == "let") 
					return Token(let); 
				if (input_string == "quit") 
					return Token(quit);
				return Token(name, input_string); // а было получено не служебное слово, то это была переменная
			}
			error("Bad token");
		}
	}
}

// функция, отвечающая за игнорирование ввода до появления символа до которого игнорируем включительно
void Token_stream::ignore(char last_ignore_char)
{
	// если символ этот в буфере, то останавливаемся, очищая буфер
	if (is_full && last_ignore_char == buffer.kind) { 
		is_full = false;
		return;
	}
	is_full = false;

	char received_char;
	while (cin >> received_char)
		if (received_char == last_ignore_char) 
			return; // останавливаемся, когда найдём этот символ
}

// структура, хранящая переменные в памяти (у них есть имя и значение)
struct Variable { 
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

// ветор вводимых пользователем переменных
vector<Variable> names; 

// функция, отвечающая за получение значения переменной по имени, которое ей дал пользователь
double get_value(string prob_name) 
{
	for (int i = 0; i < names.size(); ++i) {
		if (names[i].name == prob_name) 
			return names[i].value;
	}
	error("get: undefined name ", prob_name); // переменной не оказалось в нашем списке
}

// функция, отвечающая за передачу значения переменной по имени
void set_value(string received_name, double received_value) 
{
	for (int i = 0; i <= names.size(); ++i)
	{
		if (names[i].name == received_name) {
			names[i].value = received_value;
			return;
		}
	}
	error("set: undefined name ", received_name); // переменной не оказалось в нашем списке
}

// функция, отвечающая за проверку существования переменной 
bool is_declared(string prob_name) 
{
	for (int i = 0; i < names.size(); ++i) {
		if (names[i].name == prob_name) 
			return true;
	}
	return false;
}

// поток ввода токенов, используемый во всей программе
Token_stream ts; 

// функция, считывающая выражение 
double expression();

// функция, считывающая первичное выражение
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
				error("'(' expected");
			return received_expression;
		}
		// кейс для отрицательного первичного выражения
		case '-': 
			return -primary();
		// кейс для числа
		case number:
			return received_token.value;
		// кейс для уже существующей переменной
		case name: 
			return get_value(received_token.name);
		// кейс, если мы не получили, чего хотели
		default:
			error("primary expected");
	}
}

// функция, считывающая терм
double term() 
{
	double left_part = primary(); // левая часть терма - всегда первичное выражение
	while (true) {
		Token received_token = ts.get();
		switch (received_token.kind) 
		{
			// кейс для умножения
			case '*':
			{
				left_part *= primary(); // // не объявляю правое первичное выражение за отдельную переменную, но имею это в виду
				break;
			}
			// кейс для деления
			case '/':
			{
				double received_right_primary = primary(); // считывание первичного выражения справа
				if (received_right_primary == 0) // ошибка, связанная с делением на ноль
					error("divide by zero");
				left_part /= received_right_primary;
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
	double left_part = term(); // левая часть выражения - всегда терм
	while (true) {
		Token received_token = ts.get();
		switch (received_token.kind) {
			// кейс для сложения
			case '+':
				left_part += term(); // не объявляю правый терм за отдельную переменную, но имею это в виду
				break;
			// кейс для вычитания
			case '-':
				left_part -= term();
				break;
			default: // кейс, когда выражение закончилось
				ts.unget(received_token); // возвращаем токен в поток
				return left_part;
		}
	}
}

// функция, добавляющая новую переменную в ветор переменных, если пользователь ввёд её корректно
double define_name(string received_var, double val) { 
	if (is_declared(received_var)) // проверяем, не существует ли уже переменная с таким именем
		error(received_var, " declared twice");
	names.push_back(Variable(received_var, val)); // иначе добавляем её в вектор
	return val;
}

// функция, отвечающая за объявление переменной ('let имя = выражение')
double declaration()  {
	Token received_token = ts.get();
	if (received_token.kind != name) // полученное при вводе не соотв. заданным правилам для имени переменной
		error("name expected in declaration");
	string var_name = received_token.name; // присваиваем строке имя полученного из потока токена
	Token received_token_2 = ts.get(); // используем второй токен, чтобы проверить присваивание значения для переменной
	if (received_token_2.kind != '=') 
		error("= missing in declaration of ", var_name);
	double received_var_value = expression();
	define_name(var_name, received_var_value); // при успехе - запоминаем переменную в программу
	return received_var_value;
}

// функция, читающая вводимые инструкции (объявление или выражение)
double statement() {
	Token received_token = ts.get();
	switch (received_token.kind) 
	{
		// кейс для объявления
		case let: 
			return declaration();
		// кейс для выражения
		default:
			ts.unget(received_token);
			return expression();
	}
}

// функция, очищающая потока ввода (игнорирование буфера до символа вывода результата включительно)
void clean_up_mess() 
{
	ts.ignore(print);
}

const string input_letter = "> "; // символ, предлагающий пользователю ввод
const string result_letter = "= "; // символ, показывающий начало вывода результата

// функция, обрабатывающая вычисления: инструкция, вывод, выход, вычисление, инструкция
void calculate() 
{
	for (;cin;) // бесконечный цикл работы, так как завершаемся мы только при получении соотв. команды или сломанном вводе
	{
		try 
		{
			cout << input_letter; // начинается ввод
			Token received_token = ts.get();
			while (received_token.kind == print) // пропускаем несколько символов вывода подряд
				received_token = ts.get(); 
			if (received_token.kind == quit) // выход из программы если на ввод было получено соотв. слово
				return; 
			ts.unget(received_token); 
			// если нечего выводить на экран, но и не происходит выход из программы, то возвращаем токен в поток ввода и обрабатываем инструкцию, выводя результат
			cout << result_letter << statement() << endl;
		}
		catch (runtime_error& exc) // в случае ошибки выводим сообщение и очищаем поток токенов, но не завершаем программу
		{ 
			cerr << exc.what() << endl;
			clean_up_mess();
		}
	}
}

int main()
{
	try 
	{
		// объявляем известные константы как переменные
		define_name("pi", 3.1415926535);
		define_name("e", 2.7182818284);

		calculate(); // вызываем весь основной алгоритм калькулятора
		return 0;
	}
	// все остальные ошибки, не обработанные в процессе выполнения других функций
	catch (exception& exc) 
	{ 
		cerr << "exception: " << exc.what() << endl;
		return 1;
	}
	catch (...) 
	{
		cerr << "exception" << endl;
		return 2;
	}
}
