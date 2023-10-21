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


double Names::set_value(string received_name, double received_value) 
{
	for (int i = 0; i <= names.size(); ++i)
	{
		if (names[i].name == received_name) 
		{
			if(!names[i].is_const){
				names[i].value = received_value;
				return names[i].value;
			}
			error("set: " + received_name + " is const");
		}
	}
	error("set: undefined name ", received_name); // переменной не оказалось в нашем списке
}


bool Names::is_declared(string prob_name) 
{
	for (int i = 0; i < names.size(); ++i) {
		if (names[i].name == prob_name) 
			return true;
	}
	return false;
}

double Names::define_name(string received_var, double value, bool is_const) { 
	if (is_declared(received_var)) // проверяем, не существует ли уже переменная с таким именем
		error(received_var, ": declared twice");
	names.push_back(Variable(received_var, value, is_const)); // иначе добавляем её в вектор
	return value;
}