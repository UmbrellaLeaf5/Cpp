/*
	Грамматика:

	Вычисление:
		Инструкция
		Вывод
		Выход
		Вычисление Инструкция
	Инструкция:
		Объявление
		Выражение
	Объявление:
		# Имя_переменной = Выражение
		$ Имя_константы = Выражение
	Вывод:
		;
	Выход:
		exit
	Выражение:
		Терм
		Выражение + Терм
		Выражение - Терм
		Имя_переменной = Выражение
	Терм:
		Первичное_выражение
		Терм * Первичное_выражение
		Терм / Первичное_выражение
		Терм % Первичное_выражение
	Первичное_выражение:
		Число
		(Выражение)
		-Первичное_выражение
		+Первичное_выражение
		Имя_переменной
		Корень квадратный (Выражение)
		Возвести в степень (Выражение, Выражение)
		Имя_переменной = Выражение
		Имя_константы = Выражение
	Число:
		Литерал_с_плавающей_точкой
	Имя_константы/Имя_переменной:
		Комбинация_символов
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
	private:
		bool is_full; // переменная, отвечающая за переполнение потока токенов
		Token buffer; // "буферный" считываемый токен
	public:
		Token_stream() : is_full(0), buffer(0) { }

		// функция, отвечающая за получение следующего токена из потока
		Token get(); 
		// функция, отвечающая за возврат токена в поток токенов
		void unget(Token receive_token) { buffer = receive_token; is_full = true; } 

		// функция, отвечающая за игнорирование ввода токенов до появления символа, переданного как аргумент
		void ignore(char last_ignore_char); 
};

// константы, обозначающие типы получаемых токенов (в самой структуре токенов используеются именно они)
const char let = '#';
const char cnst = '$';
const char quit = 'q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char square_root = 'r';
const char power = 'p';
const char comma = ',';

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
		case '(': case ')': case '{': case '}':
		case '+': case '-': case '*': case '/': case '%':
		case ';': case '=': case ',': case '#': case '$':
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
				if (input_string == "exit") 
					return Token(quit);
				if (input_string == "sqrt") 
					return Token(square_root);
				if (input_string == "pow") 
					return Token(power);
				return Token(name, input_string); // а было получено не служебное слово, то это была переменная
			}
			error("bad token");
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
	bool is_const;
	Variable(string n, double val) :name(n), value(val), is_const(false) { }
	Variable(string n, double val, bool is_constanta): name(n), value(val), is_const(is_constanta) { }
};

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

double Names::get_value(string prob_name) 
{
	for (int i = 0; i < names.size(); ++i) {
		if (names[i].name == prob_name) 
			return names[i].value;
	}
	error("get_value: undefined name ", prob_name); // переменной не оказалось в нашем списке
}


double Names::set_value(string received_name, double received_value) 
{
	for (int i = 0; i <= names.size(); ++i)
	{
		if (names[i].name == received_name) 
		{
			if(!names[i].is_const){
				names[i].value = received_value;
				return names[i].value;
			}
			error("set: " + received_name + " is const");
		}
	}
	error("set: undefined name ", received_name); // переменной не оказалось в нашем списке
}


bool Names::is_declared(string prob_name) 
{
	for (int i = 0; i < names.size(); ++i) {
		if (names[i].name == prob_name) 
			return true;
	}
	return false;
}

double Names::define_name(string received_var, double value, bool is_const) { 
	if (is_declared(received_var)) // проверяем, не существует ли уже переменная с таким именем
		error(received_var, ": declared twice");
	names.push_back(Variable(received_var, value, is_const)); // иначе добавляем её в вектор
	return value;
}

// поток ввода токенов, используемый во всей программе
Token_stream ts; 

// таблица символов, используемая во всей программе
Names nm;

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
				error("')' expected");
			return received_expression;
		}
		case '{':
		{	
			double received_expression = expression(); // вызываем чтение выражения
			received_token = ts.get();
			if (received_token.kind != '}') 
				error("'}' expected");
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
			Token received_token_2 = ts.get(); // вспомогательный токен для получения значения перемнной
			if(received_token_2.kind == '=') {
				double var_value = expression();
				return nm.set_value(received_token.name, var_value);
			}
			else {
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
					error("',' expected");
				// переменная - показатель
				int power_number = narrow_cast<int>(expression()); // "сужение" значения с потерей информации и генерацией исключения в противном случае
				received_token = ts.get();
				if (received_token.kind != ')')
					error("')' expected");
				return pow(base_number, power_number);
			}
			else
				error("'(' expected");
		}
		// кейс, если мы не получили, чего хотели
		default:
			error("primary expected");
	}
}

// функция, считывающая терм
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
		if (received_token_2.kind == '=') {
			double var_value = expression();
			left_part = nm.set_value(received_token.name, var_value);
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

// функция, отвечающая за объявление переменной ('let имя_переменной = выражение')
double declaration(bool is_const)  {
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

// функция, читающая вводимые инструкции (объявление или выражение)
double statement() {
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
		nm.define_name("pi", 3.1415926535, true);
		nm.define_name("e", 2.7182818284, true);

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