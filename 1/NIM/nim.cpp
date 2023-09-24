#include <D:/Programs/2023-2024/C++/lib/std_lib_facilities.h>

void start_menu() // вывод стартового сообщения
{
    cout << "                           NIM THE GAME" << endl;
    cout << "          You can take any number of chips from any row." << endl;
    cout << "              The one who takes the last chip wins." << endl;
}

void game_show(vector <char> situation) // вывод игрового поля
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

int main()
{
    start_menu();
    vector<char> status = {3, 4, 5};
    game_show(status);
    keep_window_open();
}