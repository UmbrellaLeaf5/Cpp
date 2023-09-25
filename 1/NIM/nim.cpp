#include <D:/Programs/2023-2024/C++/lib/std_lib_facilities.h>
#include <windows.h>

// строки, показывающая, что пользователь ввёл не то, что от него ожидалось
const string player_do_wrong = "Invalid input. Please follow the logic of the game!";
const string player_do_wrong_hold_on = "Invalid input. Please follow the logic of the game and try again!";

// переменная, которая отвечает за закрытие программы при cin.fail()
bool cin_ok = true;

// вывод стартового сообщения
void start_menu() 
{
    cout << "                           NIM THE GAME" << endl;
    cout << "          You can take any number of chips from any row." << endl;
    cout << "              The one who takes the last chip wins." << endl;
}

// вывод игрового поля
void game_show(vector <int> situation) 
{
    cout << "Row number" << endl;
    for (int i = 0; i < situation.size(); i++)
    {
        cout << "   " << i + 1 << "                       ";
        for(int j = 0; j < situation[i]; j++)
            cout << "O ";
        cout << endl;
    }
}

// функция, выполняющая ввод данных в программу и проверку
int reading(char r_c)
{
    string temp; 
    while (!cin.fail())
    {
        getline(cin, temp);
        if (temp.length() > 1)
        {
            cout << player_do_wrong << endl << "Only the first character is valid." << endl;
            Sleep(2000);
        }
        char res {temp[0]}; // нас интересует только первый символ из строки, которую ввёл пользователь
        switch(r_c){
            case 'r': // случай, когда пользователь вводит ряд
                switch(res){
                    case '1': case '2': case '3':
                        return (res - '0') - 1;
                    default:
                        cout << player_do_wrong_hold_on << endl;
                        break;
                }
                break;
            case 'c': // случай, когда пользователь вводит кол-во фишек
                switch(res){
                    case '1': case '2': case '3': case '4': case '5':
                        return res - '0';
                    default:
                        cout << player_do_wrong_hold_on << endl;
                        break;
                }
                break;
        }
    }
    cin_ok = false;
}

// функция, возвращающая информацию об окончании игры
bool is_win(vector <int> situation){ 
    return not(accumulate(situation.begin(), situation.end(), 0) > 0);}

// функция, проверяющая, что фишки можно вычесть адекватно
bool chips_test(vector <int> situation, int chips, int row){
    return (situation[row] - chips >= 0);}

int main()
{
    start_menu();
    vector <int> status = {3, 4, 5}; // вектор, задающий количество фишек
    for(int turn = 0; not(is_win(status)); turn ++)
    //while (not(is_win(status)))
    {
        game_show(status);
        cout << "Enter the row." << endl;
        int r = reading('r'); // выбранный пользователем ряд
        if (not(cin_ok)) // проверка на то, что пользователь не сломал ввод
            break;
        cout << "Enter the number of chips." << endl;
        int c = reading('c'); // выбранное пользователем количество фишек
        if (not(cin_ok)) // проверка на то, что пользователь не сломал ввод
            break;
        if (chips_test(status, c, r)){ // проверка на возможность вычитания введенного количества фишек
            status[r] -= c;
        }
        else{
            cout << player_do_wrong << " Now, loading..." << endl;
            Sleep(5000); 
        }
        system("cls");
    }
    if (cin_ok) 
        cout << "You won! ";
    keep_window_open();
}