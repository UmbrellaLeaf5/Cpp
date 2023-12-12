#include <iostream>
#include <string>
#include <vector>

using uint = unsigned int;
using ushort = unsigned short;

class math_vec
{
    uint x, y;

  public:
    math_vec() : x{0}, y{0} {}

    math_vec(uint x, uint y) : x{x}, y{y} {}

    void print () { std::cout << x << " " << y << std::endl; }
};

void print (std::vector<math_vec> exps)
{
    for (auto& exp : exps)
        exp.print();
}

int main ()
{
    std::string a;
    int n;
    std::cin >> n;
    std::vector<math_vec> vecs;
    std::cin.ignore(std::cin.rdbuf()->in_avail());
    for (ushort i = 0; i < n + 1; ++i)
    {
        std::getline(std::cin, a);
        std::vector<int> temp_vec{2};
        ushort coord = 0;
        if (i > 0)
        {
            std::string temp = "";
            temp += a[0];
            std::cout << "a: " << a.size() << std::endl;
            for (size_t j = 1; j < a.size(); j++)
            {
                std::cout << "j: " << j << std::endl;
                if (a[j] != ':')
                    temp += a[j];
                else
                {
                    temp_vec[coord] = std::stoi(temp);
                    temp = "";
                    std::cout << "coord: " << coord << std::endl;
                    coord++;
                    if (coord == 2)
                        coord = 0;
                }
                std::cout << "temp: " << temp << std::endl;
            }
            temp_vec[coord] = std::stoi(temp);
            temp = "";
            std::cout << "coord: " << coord << std::endl;
            coord++;
            if (coord == 2)
                coord = 0;
            vecs.push_back(math_vec{temp_vec[1], temp_vec[2]});
        }
    }
    print(vecs);
    return 0;
}