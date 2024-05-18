#include <iostream>
#define NOMINMAX  // чтобы не получить из <windows.h> неприятные макросы max и min
#include <stdlib.h>   // только для exit();
#include <windows.h>  // только для Sleep();
#include <limits>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

// строки, показывающие, что пользователь ввёл не то, что от него ожидалось
const string player_do_wrong_message =
    "Invalid input. Please follow the logic of the game and try again!";
const string player_do_wrong_exit_message =
    "You have left the program. Enjoy your next time!";

// вывод стартового сообщения
void show_start_menu() {
  cout << "                           NIM THE GAME" << endl;
  cout << "          You can take any number of chips from any row." << endl;
  cout << "              The one who takes the last chip wins." << endl;
  cout << endl;
}

// вывод игрового поля
void game_situation_show(vector<int> chip_position, int turn) {
  cout << "Row number";
  if (!(turn % 2))
    cout << "                 Your turn!" << endl;
  else
    cout << "                 Bot's turn!" << endl;
  for (auto i = 0; i < chip_position.size(); i++) {
    cout << "   " << i + 1 << "                       ";
    for (int j = 0; j < chip_position[i]; j++)
      cout << "O ";
    cout << endl;
  }
}

// функция, закрывающая программу
void game_exit(int exit_value) {
  cout << player_do_wrong_exit_message << endl;
  system("pause");
  exit(exit_value);
}

// функция, выполняющая ввод данных в программу
char reading() {
  string help_read_string;
  while (!cin.fail()) {
    getline(cin, help_read_string);
    if (help_read_string.length() > 1) {
      cout << "Remember that only the first character is valid." << endl;
      // нас интересует только первый символ из строки, которую ввёл пользователь
      Sleep(2500);
    }
    return {help_read_string[0]};
  }
  return 0;
}

// функция, считающая проверяющая ним-сумму на равность нулю
int nim_sum(vector<int> chip_position) {
  int nim = 0;
  for (auto& i : chip_position)
    nim = nim ^ i;
  return nim;
}

// функция, которая отвечает за ход бота
void bot_turn_move(vector<int>& chip_position) {
  long long unsigned int i = 0;
  // елси ним-сумма уже равна 0, то можно брать по одной фишке, бот уже победил
  if (nim_sum(chip_position) == 0) {
    while (chip_position[i] == 0)
      i++;
    cout << "Bot takes from the row:" << endl << i + 1 << endl;
    Sleep(2500);
    cout << "Chips in number of:" << endl << "1" << endl;
    Sleep(2500);
    chip_position[i]--;
  }
  // бот берёт такое количество фишек, чтобы ним-сумма оказалась равной 0
  else {
    while (((chip_position[i] ^ nim_sum(chip_position)) >= chip_position[i]) &&
           (i < chip_position.size()))
      i++;
    cout << "Bot takes from the row:" << endl << i + 1 << endl;
    Sleep(2500);
    cout << "Chips in number of:" << endl
         << chip_position[i] - (chip_position[i] ^ nim_sum(chip_position))
         << endl;
    Sleep(2500);
    chip_position[i] = chip_position[i] ^ nim_sum(chip_position);
  }
}

// функция, возвращающая информацию об окончании игры, то есть, что фишек не осталось
bool is_win(vector<int> chip_position) {
  return accumulate(chip_position.begin(), chip_position.end(), 0) <= 0;
}

/* Эти функции теперь не нужны

// функция, проверяющая, что фишки можно вычесть адекватно
bool is_chips_input_correct(vector <int> chip_position, int chips, int row)
{
    switch (chips) {
    case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
        // возвращаем ответ на вопрос о том, можно ли вычесть преобразованное в int кол-во
        // фишек из выбранного ряда
        return (chip_position[row] - (chips - '0') >= 0);
    default:
        // остальные значения некорректны
        return 0;
    }
}

// функция, проверяющая, что из данного ряда можно взять фишку
bool is_row_input_correct(vector <int> chip_position, int row)
{
    switch (row) {
    case '1': case '2': case '3':
        // возвращаем ответ на вопрос о том, можно ли выбрать преобразованный в int ряд
        return (chip_position[(row - '0') - 1] != 0);
    default:
        // других рядов у нас нету, все остальные значения некорректны
        return 0;
    }
}

// функция, проверяющая корректность ввода фишек, а также выполняющая операцию с ними
void chip_operation(vector <int>& chip_position, int& player_chips, int player_row)
{
    bool is_first_iteration = true;
    do {
        if (!is_first_iteration)
            cout << player_do_wrong_message << endl;
        player_chips = reading();
        if (cin.fail()) // проверка на то, что пользователь не сломал ввод
            game_exit(0);
        is_first_iteration = false;
    } while (!(is_chips_input_correct(chip_position, player_chips, player_row)));
    chip_position[player_row] -= (player_chips - '0'); // вычитаем фишки при успешном вводе
}

// функция, проверяющая корректность ввода ряда
void row_operation(vector <int>& chip_position, int& player_row)
{
    bool is_first_iteration = true;
    do {
        if (!is_first_iteration)
            cout << player_do_wrong_message << endl;
        player_row = reading();
        if (cin.fail()) // проверка на то, что пользователь не сломал ввод
            game_exit(0);
        is_first_iteration = false;
    } while (!(is_row_input_correct(chip_position, player_row)));
    player_row -= ('0' + 1); //перевод из char в нужное значение ряда
}
*/

//функция, печатающая сообщение о победе
void somebody_wins_message(vector<int> chip_position, bool is_bot_wins) {
  if (is_bot_wins) {
    game_situation_show(chip_position, 0);
    cout << "Unfortunately, a smart bot has surpassed you. You lose! Try again "
            "next time!"
         << endl;
    cout << "This is the end of the program. ";
  } else {
    game_situation_show(chip_position, 1);
    cout << "Congratulations! You beated a smart bot! You won!" << endl;
    cout << "This is the end of the program. ";
  }
}

// функция, которая отвечает за ход игрока
void player_turn_move(vector<int>& chip_position) {
  while (true) {
    cout << "Enter the row and chips count." << endl;
    int row = -1, chips_to_take = -1;
    std::cin >> row >> chips_to_take;

    if (cin.fail())  // проверка на то, что пользователь не сломал ввод
    {
      if (cin.eof())
        game_exit(0);

      cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      cout << "Wrong input. Try again!" << std::endl;
      continue;
    }

    if (row < 1 || row > chip_position.size()) {
      cout << "Wrong row number. Try again!" << std::endl;
      continue;
    }

    size_t row_index = (size_t)row - 1;

    if (chips_to_take < 1 || chips_to_take > chip_position[row_index]) {
      cout << "Wrong chips count. Try again!" << std::endl;
      continue;
    }

    chip_position[row_index] -= chips_to_take;
    break;
  }
}

//функция, выполняющая 1 ход игры и проверяющая, что он прошел успешно
void step_of_the_game(vector<int>& chip_position, int turn) {
  int player_row, player_chips;
  game_situation_show(chip_position, turn);
  if (!(turn % 2)) {  // ход пользователя
    player_turn_move(chip_position);
  } else {  // ход бота
    bot_turn_move(chip_position);
  }
}

int main() {
  show_start_menu();
  vector<int> chip_position = {3, 4, 5};  // вектор, задающий количество фишек
  int turn = 0;

  // цикл выполняется до тех пор, пока не будет достигнуто условие победы
  // есть счетчик, по которому определяется, кто ходит
  while (!is_win(chip_position)) {
    step_of_the_game(chip_position, turn);
    turn++;
    system("cls");  // чистка консоли
  }

  bool is_bot_wins = !(turn % 2);
  somebody_wins_message(chip_position, is_bot_wins);
  system("pause");
  return 0;
}