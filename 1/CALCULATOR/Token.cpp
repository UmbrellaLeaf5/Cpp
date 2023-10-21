#include "std_lib_facilities.h"

#include "Token.h"
#include "const_kinds.h"


Token Token_stream::get()
{
	// если в буфере есть токен, забираем его оттуда
	if (is_full) { 
		is_full = false; 
		return buffer; 
	} 
	char received_char; 
	cin.get(received_char);
	while (isspace(received_char)) { // пропускаем все пробельные символы
		if (received_char == '\n') // конец строки - вывод на экран
			return line_break; // перенос строки мы обрабатываем как отдельный случай, поэтому возвраащем не токен
		cin.get(received_char);
	}
	switch (received_char) 
	{
		// кейсы для операторов
		case '(': case ')': case '{': case '}':
		case '+': case '-': case '*': case '/': case '%':
		case ';': case '\n': case '=': case ',': case '#': case '$': 
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
		// кейс для переменных или служебных слов типа 'sqrt', 'exit', 'pow'
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
					return Token(exiting);
				if (input_string == "sqrt") 
					return Token(square_root);
				if (input_string == "pow") 
					return Token(power);
				if (input_string == "help")
					return Token(help);
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
	while (cin.get(received_char))
	{
		if (received_char == line_break)
			received_char = print; // пусть наш игнор воспринимает перенос строки как ";"
		if (received_char == last_ignore_char) // останавливаемся при нахождении символа - аргумента функции
			return;
	}
}