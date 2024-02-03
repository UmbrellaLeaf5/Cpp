
#include <iostream>
#include <vector>
using namespace std;

int main ()
{
    // ЗАДАЧА 1
    // дан упорядоченный массив размера n, содержащий целые числа
    // найти два числа из массива, которые в сумму дадут k = 12

    vector<int> vec{-3, 0, 3, 4, 10, 12, 14, 17};
    auto n = vec.size();
    int k = 12;

    // метод двойным перебором O(n^2)
    cout << "first method: " << endl;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            if (vec[i] + vec[j] == k)
                cout << i << " " << j << endl;
        }
    }

    // метод бинарынм поиском O(n*logn)

    // метод поиском с двух сторон O(n)
    cout << "third method: " << endl;
    for (size_t i = 0, j = n - 1; i < j;)
    {
        auto sum = vec[i] + vec[j];
        if (sum < k)
            i++;
        else if (sum > k)
            j--;
        else if (sum == k)
        {
            cout << i << " " << j << endl;
            break;
        }
    }

    // ЗАДАЧА 2
    // построить стек, у которого всегда можно найти минимум

    return 0;
}