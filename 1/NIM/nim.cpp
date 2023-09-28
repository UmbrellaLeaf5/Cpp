#include <D:/Programs/2023-2024/C++/lib/std_lib_facilities.h>
#include <windows.h> // только для Sleep();

// строки, показывающая, что пользователь ввёл не то, что от него ожидалось
const string player_do_wrong_message = "Invalid input. Please follow the logic of the game and try again!";

// переменная, которая даёт понять, что ввод был провален
bool cin_ok = true;

// вывод стартового сообщения
void show_start_menu() 
{
    cout << "                           NIM THE GAME" << endl;
    cout << "          You can take any number of chips from any row." << endl;
    cout << "              The one who takes the last chip wins." << endl;
    cout << endl;
}

// вывод игрового поля
void game_show(vector <int> chips_game_status, int turn) 
{
    cout << "Row number";
    if (not(turn % 2))
        cout << "                 Your turn!" << endl;
    else
        cout << "                 Bot's turn!" << endl;
    for (auto i = 0; i < chips_game_status.size(); i++)
    {
        cout << "   " << i + 1 << "                       ";
        for(int j = 0; j < chips_game_status[i]; j++)
            cout << "O ";
        cout << endl;
    }
}

// функция, выполняющая ввод данных в программу и проверку
int reading(char reading_object_type)
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
        char reading_result {help_read_string[0]};
        switch(reading_object_type){
            case 'r': // случай, когда пользователь вводит ряд
                switch(reading_result){
                    case '1': case '2': case '3':
                        return (reading_result - '0') - 1;
                    default:
                        cout << player_do_wrong_message << endl;
                        break;
                }
                break;
            case 'c': // случай, когда пользователь вводит кол-во фишек
                switch(reading_result){
                    case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                        return reading_result - '0';
                    case '0':
                        cout << "Invalid input. You cannot take zero chips!" << endl;
                        break;
                    default:
                        cout << player_do_wrong_message << endl;
                        break;
                }
                break;
        }
    }
    cin_ok = false;
    return 0;
}

// функция, считающая проверяющая ним-сумму на равность нулю
int nim_sum(vector <int> chips_game_status)
{
    int nim = 0;
    for (auto i = 0; i < chips_game_status.size(); i++)
    {
        nim = nim ^ chips_game_status[i];
    }
    return nim;
}

// функция, которая отвечает за ход бота
void bot_turn_move(vector <int>& chips_game_status)
{
    long long unsigned int i = 0;
    if (nim_sum(chips_game_status) == 0) // елси ним-сумма уже равна 0, то можно брать по одной фишке, бот уже победил
    {
        while (chips_game_status[i] == 0)
            i++;
        cout << "Bot takes from the row:" << endl << i + 1 << endl;
        Sleep(2500);
        cout << "Chips in number of:" << endl << "1" << endl;
        Sleep(2500);
        chips_game_status[i] --;
    }
    else // бот берёт такое количество фишек, чтобы ним-сумма оказалась равной 0
    {
        while(((chips_game_status[i] ^ nim_sum(chips_game_status)) >= chips_game_status[i]) && (i < chips_game_status.size()))
            i++;
        cout << "Bot takes from the row:" << endl << i + 1 << endl;
        Sleep(2500);
        cout << "Chips in number of:" << endl << chips_game_status[i] - (chips_game_status[i] ^ nim_sum(chips_game_status)) << endl;
        Sleep(2500);
        chips_game_status[i] = chips_game_status[i] ^ nim_sum(chips_game_status);
    }
}

// функция, возвращающая информацию об окончании игры
bool is_win(vector <int> chips_game_status){ 
    return not(accumulate(chips_game_status.begin(), chips_game_status.end(), 0) > 0);}

// функция, проверяющая, что фишки можно вычесть адекватно
bool chips_test_ok(vector <int> chips_game_status, int chips, int row){
    return (chips_game_status[row] - chips >= 0);}

// функция, проверяющая корректность ввода фишек, а также выполняющая операцию с ними
bool chip_operation_cin_fail(vector <int>& chips_game_status, int& player_chips, int player_row)
{
    player_chips = reading('c');
    if (not(cin_ok)) // проверка на то, что пользователь не сломал ввод
        return 1;
    // пока пользователь не введет адекватное значение, будем продолжать спрашивать
    while(not(chips_test_ok(chips_game_status, player_chips, player_row)))
    {
        cout << "Invalid input. You can not take so many chips from this row!" << endl;
        player_chips = reading('c');
        if (not(cin_ok)) // проверка на то, что пользователь не сломал ввод
            return 1;
    }
    chips_game_status[player_row] -= player_chips;
    return 0;
}

// функция, проверяющая, что из данного ряда можно взять фишку
bool row_test_ok(vector <int> chips_game_status, int row){
    return (chips_game_status[row] != 0);}

// функция, проверяющая корректность ввода ряда
bool row_operation_cin_fail(vector <int>& chips_game_status, int& player_row)
{
    player_row = reading('r');
    if (not(cin_ok)) // проверка на то, что пользователь не сломал ввод
        return 1;
    // пока пользователь не введет адекватное значение, будем продолжать спрашивать
    while(not(row_test_ok(chips_game_status, player_row)))
    {
        cout << "Invalid input. There are no chips left in this row!" << endl;
        player_row = reading('r');
        if (not(cin_ok)) // проверка на то, что пользователь не сломал ввод
            return 1;
    }
    return 0;
}

//функция, печатающая сообщение о победе
void somebody_wins_message(vector<int> chips_game_status, bool bot_is_winner)
{
    if (bot_is_winner){
            game_show(chips_game_status, 0);
            cout << "Unfortunately, a smart bot has surpassed you. You lose! Try again next time!" << endl;
            cout << "This is the end of the program. ";
        }
        else{
            game_show(chips_game_status, 1);
            cout << "Congratulations! You beated a smart bot! You won!" << endl;
            cout << "This is the end of the program. ";
        }
}

//функция, выполняющая 1 ход игры и проверяющая, что он прошел успешно
bool game_action_turn_cin_fail(vector<int>& chips_game_status, bool& bot_is_winner, int turn)
{
    if (cin_ok) // если ввод сломали, не следует лишний раз выводить поле
        game_show(chips_game_status, turn);
    if (not(turn % 2)){ // ход пользователя
        cout << "Enter the row." << endl;
        int player_row; // ряд, который вводит пользователь
        if (row_operation_cin_fail(chips_game_status, player_row)) // проверка на нормальный ввод ряда
            return 1;
        cout << "Enter the number of chips." << endl;
        int player_chips; // количество фишек, вводимое пользователем
        if (chip_operation_cin_fail(chips_game_status, player_chips, player_row)) // проверка на нормальный ввод фишек
            return 1;
        return 0;
    }else{ // ход бота
        bot_turn_move(chips_game_status);
        if (is_win(chips_game_status))
            bot_is_winner = true;
        return 0;
    }
}

int main()
{
    bool bot_wins_true = false;
    show_start_menu();
    vector <int> chips_game_status = {3, 4, 5}; // вектор, задающий количество фишек

    // цикл выполняется до тех пор, пока не будет достигнуто условие победы
    // есть счетчик, по которому определяется, кто ходит
    for(int turn = 0; not(is_win(chips_game_status)); turn ++) 
    {
        if(game_action_turn_cin_fail(chips_game_status, bot_wins_true, turn))
            break;
        system("cls"); // чистка консоли
    }

    if (cin_ok){ // при несломанном вводе и выходе из основного цикла, кто-то побеждает
        somebody_wins_message(chips_game_status, bot_wins_true);
    }
    keep_window_open();
    return 0;
}

// юху, 222 :)