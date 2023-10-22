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
	char rec_ch = ' ';  // FIXME: fix issue when input stream was closed
	cin.get(rec_ch);
	if (cin){
		while (isspace(rec_ch)) { // пропускаем все пробельные символы
			if (rec_ch == line_break) // конец строки - вывод на экран
				return line_break; // перенос строки мы обрабатываем как отдельный случай, поэтому возвраащем не токен
			cin.get(rec_ch);
		}
		switch (rec_ch) 
		{
			// кейсы для операторов
			case '(': case ')': case '{': case '}':
			case '+': case '-': case '*': case '/': case '%':
			case ';': case '\n': case '=': case ',': case '#': case '$': 
				return Token(rec_ch);
			// кейсы для чисел
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
			{
				cin.unget(); // возвращаем предыдущий символ в стандартный поток ввода
				double rec_value;
				cin >> rec_value;
				return Token(number, rec_value);
			}
			// кейс для переменных или служебных слов типа 'sqrt', 'exit', 'pow'
			default: 
			{
				if (isalpha(rec_ch)) 
				{
					string user_input;
					user_input += rec_ch;
					while (cin.get(rec_ch) && (isalpha(rec_ch) || isdigit(rec_ch))) 
						// читаем посимвольно слово (из букв и цифр)
						user_input += rec_ch; 
					cin.unget();
					// если получены служебные слова, организуем соотв. действия в токене
					if (user_input == "exit") 
						return Token(exiting);
					if (user_input == "sqrt") 
						return Token(square_root);
					if (user_input == "pow") 
						return Token(power);
					if (user_input == "help")
						return Token(help);
					return Token(name, user_input); // а было получено не служебное слово, то это была переменная
				}
				error("bad token");
			}
		}
	}
	else
		return Token(exiting);
}

void Token_stream::unget(Token rec_t)
{ 
	buffer = rec_t; 
	is_full = true; 
}

// функция, проверяющая принадлежность символа вектору
bool contains(const vector<char>& vec, char ch)
{
	for(auto& i : vec){
		if(i == ch)
			return true;
	}
	return false;
}

void Token_stream::ignore(vector<char> ending_chars)
{
	// если символ этот в буфере, то останавливаемся, очищая буфер
	if (is_full && contains(ending_chars, buffer.kind)) { 
		is_full = false;
		return;
	}
	is_full = false;

	char rec_ch;
	while (cin.get(rec_ch))
	{
		if (contains(ending_chars, rec_ch))
			return;
	}
}