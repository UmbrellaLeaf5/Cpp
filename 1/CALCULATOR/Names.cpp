#include "std_lib_facilities.h"

#include "Variable.h"
#include "Names.h"

double Names::get_value(string prob_name) 
{
	for (int i = 0; i < names.size(); ++i) {
		if (names[i].name == prob_name) 
			return names[i].value;
	}
	error("get_value: undefined name ", prob_name); // переменной не оказалось в нашем списке
}


double Names::set_value(string rec_name, double rec_value) 
{
	for (int i = 0; i <= names.size(); ++i)
	{
		if (names[i].name == rec_name) 
		{
			if(!names[i].is_const){
				names[i].value = rec_value;
				return names[i].value;
			}
			error("set: " + rec_name + " is const");
		}
	}
	error("set: undefined name ", rec_name); // переменной не оказалось в нашем списке
}


bool Names::is_declared(string prob_name) 
{
	for (int i = 0; i < names.size(); ++i) {
		if (names[i].name == prob_name) 
			return true;
	}
	return false;
}

double Names::define_name(string var_name, double value, bool is_const) { 
	if (is_declared(var_name)) // проверяем, не существует ли уже переменная с таким именем
		error(var_name, ": declared twice");
	names.push_back(Variable(var_name, value, is_const)); // иначе добавляем её в вектор
	return value;
}