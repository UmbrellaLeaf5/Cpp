#include "std_lib_facilities.h"
#include <stdlib.h>   // только для exit();
#include <windows.h>  // только для Sleep();
using namespace std;

// строки, показывающие, что пользователь ввёл не то, что от него ожидалось
const string player_do_wrong_message =
    "Invalid input. Please follow the logic of the game and try again!";
const string player_do_wrong_exit_message = "You have left the program. Enjoy your next time!";

// вывод стартового сообщения
void show_start_menu ()
{
    cout << "                           NIM THE GAME" << endl;
    cout << "          You can take any number of chips from any row." << endl;
    cout << "              The one who takes the last chip wins." << endl;
    cout << endl;
}

// вывод игрового поля
void game_situation_show (vector<int> field, int turn)
{
    cout << "Row number";
    if (!(turn % 2))
        cout << "                 Your turn!" << endl;
    else
        cout << "                 Bot's turn!" << endl;
    for (auto i = 0; i < field.size(); i++)
    {
        cout << "   " << i + 1 << "                       ";
        for (int j = 0; j < field[i]; j++)
            cout << "O ";
        cout << endl;
    }
}

// функция, закрывающая программу
void game_exit (int exit_value)
{
    cout << player_do_wrong_exit_message << endl;
    system("pause");
    exit(exit_value);
}

// функция, выполняющая ввод данных в программу
int read_number ()
{
    string help_read_string;
    while (!cin.fail())
    {
        getline(cin, help_read_string);
        if (help_read_string.length() > 1)
        {
            cout << "Remember that only the first character is valid." << endl;
            // нас интересует только первый символ из строки, которую ввёл пользователь
            Sleep(2500);
        }
        return help_read_string[0] - '0';
    }
    return 0;
}

// функция, считающая проверяющая ним-сумму на равность нулю
int nim_sum (vector<int> field)
{
    int nim = 0;
    for (auto& i : field)
        nim = nim ^ i;
    return nim;
}

// функция, которая отвечает за ход бота
void bot_turn_move (vector<int>& field)
{
    long long unsigned int i = 0;
    // елси ним-сумма уже равна 0, то можно брать по одной фишке, бот уже победил
    if (nim_sum(field) == 0)
    {
        while (field[i] == 0)
            i++;
        cout << "Bot takes from the row:" << endl << i + 1 << endl;
        Sleep(2500);
        cout << "Chips in number of:" << endl << "1" << endl;
        Sleep(2500);
        field[i]--;
    }
    // бот берёт такое количество фишек, чтобы ним-сумма оказалась равной 0
    else
    {
        while (((field[i] ^ nim_sum(field)) >= field[i]) && (i < field.size()))
            i++;
        cout << "Bot takes from the row:" << endl << i + 1 << endl;
        Sleep(2500);
        cout << "Chips in number of:" << endl << field[i] - (field[i] ^ nim_sum(field)) << endl;
        Sleep(2500);
        field[i] = field[i] ^ nim_sum(field);
    }
}

// функция, возвращающая информацию об окончании игры, то есть, что фишек не осталось
bool is_win (vector<int> field) { return accumulate(field.begin(), field.end(), 0) <= 0; }

// функция, проверяющая, что фишки можно вычесть адекватно
bool is_chips_input_correct (vector<int> field, int chips, int row)
{
    switch (chips)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        // возвращаем ответ на вопрос о том, можно ли вычесть преобразованное в int кол-во
        // фишек из выбранного ряда
        return (field[row] - chips >= 0);
    default:
        // остальные значения некорректны
        return 0;
    }
}

// функция, проверяющая, что из данного ряда можно взять фишку
bool is_row_input_correct (vector<int> field, int row)
{
    switch (row)
    {
    case 1:
    case 2:
    case 3:
        // возвращаем ответ на вопрос о том, можно ли выбрать преобразованный в int ряд
        return (field[row - 1] != 0);
    default:
        // других рядов у нас нету, все остальные значения некорректны
        return 0;
    }
}

// функция, проверяющая корректность ввода фишек, а также выполняющая операцию с ними
void chip_operation (vector<int>& field, int& player_chips, int player_row)
{
    bool is_first_iteration = true;
    do
    {
        if (!is_first_iteration)
            cout << player_do_wrong_message << endl;
        player_chips = read_number();
        if (cin.fail())  // проверка на то, что пользователь не сломал ввод
            game_exit(0);
        is_first_iteration = false;
    }
    while (!(is_chips_input_correct(field, player_chips, player_row)));
    field[player_row] -= player_chips;  // вычитаем фишки при успешном вводе
}

// функция, проверяющая корректность ввода ряда
void row_operation (vector<int>& field, int& player_row)
{
    bool is_first_iteration = true;
    do
    {
        if (!is_first_iteration)
            cout << player_do_wrong_message << endl;
        player_row = read_number();
        if (cin.fail())  // проверка на то, что пользователь не сломал ввод
            game_exit(0);
        is_first_iteration = false;
    }
    while (!(is_row_input_correct(field, player_row)));
    player_row -= 1;  // перевод из char в нужное значение ряда
}

// функция, печатающая сообщение о победе
void somebody_wins_message (vector<int> field, int turn)
{
    if (turn % 2 == 0)
    {
        game_situation_show(field, 0);
        cout << "Unfortunately, a smart bot has surpassed you. You lose! Try again next time!"
             << endl;
        cout << "This is the end of the program. ";
    }
    else
    {
        game_situation_show(field, 1);
        cout << "Congratulations! You beated a smart bot! You won!" << endl;
        cout << "This is the end of the program. ";
    }
}

// функция, выполняющая 1 ход игры и проверяющая, что он прошел успешно
void step_of_the_game (vector<int>& field, int turn)
{
    int player_row, player_chips;
    game_situation_show(field, turn);
    if (!(turn % 2))
    {  // ход пользователя
        cout << "Enter the row." << endl;
        row_operation(field, player_row);
        cout << "Enter the number of chips." << endl;
        chip_operation(field, player_chips, player_row);
    }
    else
    {  // ход бота
        bot_turn_move(field);
    }
}

int main ()
{
    show_start_menu();
    vector<int> field = {3, 4, 5};  // вектор, задающий количество фишек
    int turn = 0;

    // цикл выполняется до тех пор, пока не будет достигнуто условие победы
    // есть счетчик, по которому определяется, кто ходит
    while (!is_win(field))
    {
        step_of_the_game(field, turn);
        turn++;
        system("cls");  // чистка консоли
    }
    somebody_wins_message(field, turn);
    system("pause");
    return 0;
}
