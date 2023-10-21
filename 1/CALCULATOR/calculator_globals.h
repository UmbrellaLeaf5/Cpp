#include "Token.h"
#include "Names.h"
#pragma once

// поток ввода токенов, используемый во всей программе
extern Token_stream ts; 

// таблица символов, используемая во всей программе
extern Names nm;

const string input_letter = "> "; // символ, предлагающий пользователю ввод
const string result_letter = "= "; // символ, показывающий начало вывода результата
