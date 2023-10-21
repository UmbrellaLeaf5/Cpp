#pragma once

// структура токена (у него есть тип, значение и (возможно) имя переменной)
struct Token
{ 
	char kind;
	double value;
	string name;
	//использование конструкторов для разных вариантов использования токена (числового значения, ключевого слова, имени переменной и т.п.)
	Token(char received_char) : kind(received_char), value(0) { }
	Token(char received_char, double val) : kind(received_char), value(val) { }
	Token(char received_char, string n) : kind(received_char), value(0), name(n) { }
};

// поток с буфером для чтения токенов
class Token_stream
{ 
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
