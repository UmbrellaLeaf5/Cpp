#include "std_lib_facilities.h"

#include "Token.h"
#include "const_kinds.h"
#include "calculator.h"
#include "main_grammar_functions.h"


// функция, выводящаяя инструкцию по работе с программой
void user_help_cout()
{
	cout << "Instructions for using the calculator:" << endl;
	cout << "With the enabled operations, this calculator can calculate lowercase mathematical expressions." << endl;
	cout << "Allowed operations in accordance with the axioms of mathematics:" << endl;
	cout << "! addition ('+'), subtraction ('-');" << endl;
	cout << "! multiplication ('*'), division ('/'), division remainder ('%');" << endl;
	cout << "! exponentiation ('pow(,)'), square root ('sqrt()');" << endl;
	cout << "! declaration of variables ('#'), declaration of constants ('$');" << endl;
	cout << "! evaluating the expression in brackets, assigning new values to variables ('=')." << endl;
	cout << "To get the result of a calculation, use the symbol ';' to separate expressions and line breaks, or just use line breaks." << endl;
	cout << "An example of a working program using all the commands:" << endl;
	cout << "> # s = 10; $ p = 5; 2 + s; s = 5 * p; pow(p, 4); sqrt(s); s % 10; s / 5; s / (5 % 10) + 6 - 7;" << endl;
}

// функция, очищающая потока ввода (игнорирование буфера до символа вывода результата включительно)
void clean_up_mess() 
{
	ts.ignore(print);
}

// функция, обрабатывающая вычисления: инструкция, вывод, выход, вычисление, инструкция
void calculate() 
{
	for (;cin;) // бесконечный цикл работы, так как завершаемся мы только при получении соотв. команды или сломанном вводе
	{
		try 
		{
			cout << input_letter; // начинается ввод
			Token received_token = ts.get();
			while (received_token.kind == print || received_token.kind == line_break) // пропускаем несколько символов вывода подряд
				received_token = ts.get(); 
			if (received_token.kind == exiting) // выход из программы если на ввод было получено соотв. слово
				return; 
			if (received_token.kind == help) // вывод сообщения - инструкции
				user_help_cout();
			else
			{
				ts.unget(received_token); 
				// если нечего выводить на экран, но и не происходит выход из программы, то возвращаем токен в поток ввода и обрабатываем инструкцию, выводя результат
				cout << result_letter << statement() << endl;
			}
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