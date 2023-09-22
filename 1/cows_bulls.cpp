#include <iostream>
#include <vector>
#include <tuple>
#include <exception>
using namespace std;


//Генерация числа, которое загадал компьютер
vector<char> gen_solution()
{
    return {'1','2','3','4'};
}

//Получения числа от пользователя (попытка), проверка на ввод от пользователя
vector<char> get_guess()
{
    vector<char> numbers;
    for(char temp; cin >> temp;) ///Вот тут ошибка!!!
    {
        if (cin.fail())
        {
            throw runtime_error("Error entering number. Please follow the rules of the game.");
        }
        numbers.push_back(temp);
    }
    if (numbers.size() > 4)
    {
        throw runtime_error("Error entering number. The number has too much digits. Please follow the rules of the game.");
    }
    /*for(size_t i = 0; i < nsize; i++) {
        for(size_t j = i; j < nsize; j++){
            if (numbers[i] == numbers[j])
            {
                throw runtime_error("Error entering number. The digits in the number are repeated. Please follow the rules of the game.");
            }
        }
    }*/
    return numbers;
}

//Посчитать, сколько встретился символ (для счета коров)
size_t count(const vector<char>& digits, char d)
{
    int k{};
    for (int i = 0; i < digits.size(); ++i)
        if (digits[i] == d)
            ++k;
    return k;
}

//Функция, которая считает быков и коров
tuple <int, int> calc_bulls_cows(vector<char> guess, vector<char> solution)
{
    int bulls = 0, cows = 0;
    for(size_t i = 0; i < guess.size(); i++)
    {
        if (guess[i] == solution[i])
        {
            bulls ++;
        } 
        else if (count(solution, guess[i]) > 0)
        {
            cows ++;
        }
    }
    return {bulls, cows};
}

int main()
{
    try{
        vector <char> solution = gen_solution(); //Загаданное число = сгенерированному
        //Стартовое сообщение
        cout << "<<Bulls and Cows>>\n"
             << "Computer sets a number of 4 unique digits.\n"
             << "Try to guess it.\n"
             << "<Bull> means right digit in the right position.\n"
             << "<Cow> means right digit in the wrong position.\n";
        //Основной цикл для работы игры
        for(bool run_game = true; run_game;)
        {
            vector<char> guess = get_guess(); //Текущая попытка = получить ввод числа от пользователя
            auto [bulls, cows] = calc_bulls_cows(guess, solution); //Количество "быков" и "коров" = функции, которая их считает
            if (bulls == 4) //Четыре быка - это победа
            {
                cout << "There are now 4 bulls! Wow, you won!" << endl;
                run_game = false;
            }
            else //Если не победа, игра продолжается
            {
                cout << "You are close to victory. There are " << bulls << " bulls and " 
                     << cows << " cows. Try again!" << endl << endl;
            }
        }
        system("pause");
        return 0;
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
        system("pause");
        return -1;
    }
}