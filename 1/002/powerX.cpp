#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

// Реализация функции возведения в степень циклом
double pow_c (double x, int n)
{
    double result = 1;
    for (int i = 0; i < abs(n); i++)
    {
        result *= x;
    }
    // Случай, когда всё положительно
    if (n > 0)
        return result;
    // Случай, когда показатель отрицательный, но аргумент положиелен
    else if (n < 0 && x != 0)
        return 1 / result;
    // Случай, когда число строго большее нуля возводится в нулевую степень
    else if (x > 0 && n == 0)
        return 1;
    // Все остальные неопределенные случаи и доброе пояснение :)
    else
        throw runtime_error{"Fuck you."};
}

// Реализация функции возведения в степень рекурсией
double pow_r (double x, int n)
{
    // Все неопределенные случаи и доброе пояснение :)
    if (x == 0 && n <= 0)
        throw runtime_error{"Fuck you."};
    // Случай, когда число возводится в нулевую степень
    if (n == 0)
        return 1;
    // Случай, когда всё положительно
    if (n > 0)
    {
        if (n == 1)
            return x;
        return pow_r(x, n - 1) * x;
    }
    // Случай, когда показатель отрицательный, но аргумент положиелен
    if (n < 0)
    {
        return pow_r(x, n + 1) / x;
    }
    return -1;
}

// Процедура тестирования
void test_pow (double x, double tol)
{
    for (auto n : {0, -1, 1, -2, 2, -5, 5})
    {
        cout << "x = " << x << ", "
             << "n = " << n << ": " << endl;
        double etalon = pow(x, n);
        cout << "std::pow " << etalon << endl;
        using Func = double (*)(double, int);
#define FUN_NAME(function) make_pair(Func{function}, string(#function))
        auto powers = {FUN_NAME(pow_c), FUN_NAME(pow_r)};
#undef FUN_NAME
        for (auto [f, name] : powers)  // C++17
        {
            cout << setw(8) << left << name << " " << flush;
            double p = f(x, n);
            double diff = p - etalon;
            cout << p << " (difference is " << diff << ")"
                 << " [" << (abs(diff) < tol ? "OK" : "FAILED") << "]" << endl;
        }
        cout << "\n";
    }
}

int main ()
{
    double x;
    cin >> x;
    test_pow(x, 10);
    system("pause");
    return 0;
}