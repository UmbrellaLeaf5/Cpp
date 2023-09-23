/*
План:
1) Прочесть все (x, y)
    тип double
    while(std::cin >> x >> y) 
    {
        std::cin >> x...
    }
2) Записать в память программы
3) Вычислить a, b
4) Вывод результата

Работа с динамич. массивом (vector):
std::vector <double> x_values, y_values;
x_values.push_back(x);
y_values.push_back(y);
*/

#include <iostream>
#include <vector>
using namespace std;

//Реализация функции _x или _y элементов вектора
double vec__s(vector<double> a)
{
    double result = 0;
    for(unsigned long long i = 0; i < a.size(); i++)
    {
        result += a[i];
    }
    return result/a.size();
}

//Реализация функции, которая считает _(xy)
double vec__xy (vector<double> a, vector<double> b)
{
    double result = 0;
    for(unsigned long long i = 0; i < a.size(); i++)
    {
        result += a[i]*b[i];
    }
    return result/a.size();
}

//Реализация функции, которая считает _(x^2)
double vec__x_sqr (vector<double> a)
{
    double result = 0;
    for(unsigned long long i = 0; i < a.size(); i++)
    {
        result += a[i]*a[i];
    }
    return result/a.size();
}
//Реализация главной функции
int main()
{
    //Вектор с нашими значениями и считывание данных в него
    vector<double> x_values, y_values;
    double temp_x, temp_y;
    cout << "Enter x and y values." << endl;
    for(;;)
    {
        cin >> temp_x >> temp_y;
        if(cin.fail())
            break;
        x_values.push_back(temp_x);
        y_values.push_back(temp_y);
    }
    
    //Высчитывание коэф. a и b и их вывод
    double a, b;
    b = (vec__xy(x_values, y_values) - vec__s(x_values)*vec__s(y_values)) / 
        (vec__x_sqr(x_values) - vec__s(x_values)*vec__s(x_values));
    a = vec__s(y_values) - b*vec__s(x_values);
    cout << "a = " << a << endl << "b = " << b << endl;
    system("pause");
}