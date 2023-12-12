#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using uint = unsigned int;
using ushort = unsigned short;

struct Time
{
    ushort hours;
    ushort minutes;

    Time() : hours{0}, minutes{0} {}

    Time(ushort h, ushort m)
    {
        if (h < 24)
            hours = h;
        else
            throw std::invalid_argument("invalid hours: " + std::to_string(h));
        if (m < 60)
            minutes = m;
        else
            throw std::invalid_argument("invalid minutes: " + std::to_string(m));
    }

    void print ()
    {
        if (hours < 10)
        {
            if (minutes < 10)
                std::cout << '0' << hours << ":0" << minutes;
            else
                std::cout << '0' << hours << ":" << minutes;
        }
        else if (minutes < 10)
            std::cout << hours << ":0" << minutes;
        else
            std::cout << hours << ":" << minutes;
    }
};

class Experiment
{
    Time start;
    Time end;

  public:
    Experiment() : start{0, 0}, end{0, 0} {}

    Experiment(ushort h, ushort m, ushort d)
        : start{h, m}, end{(h + (m + d) / 60) % 24, m + d - ((m + d) / 60) * 60}
    {
    }

    void print ()
    {
        end.print();
        std::cout << std::endl;
    }

    ushort abs () { return (end.hours * 60 + end.minutes); }
};

void print (std::vector<Experiment> exps)
{
    for (auto& exp : exps)
        exp.print();
}

std::vector<Experiment> sorted (const std::vector<Experiment>& vec)
{
    std::vector<Experiment> res = vec;
    for (size_t i = 0; i < vec.size() - 1; i++)
    {
        for (size_t j = 0; j < vec.size() - i - 1; j++)
        {
            if (res[j].abs() > res[j + 1].abs())
                std::swap(res[j], res[j + 1]);
        }
    }
    return res;
}

int main ()
{
    std::string a;
    int n;
    std::cin >> n;
    std::vector<Experiment> exps;
    std::cin.ignore(std::cin.rdbuf()->in_avail());
    for (ushort i = 0; i < n + 1; ++i)
    {
        std::getline(std::cin, a);
        ushort h = 0, m = 0, d = 0;
        if (i > 0)
        {
            std::string hours = "";
            for (size_t k = 0; k < 2; k++)
                hours += a[k];
            h = std::stoi(hours);

            std::string minutes = "";
            for (size_t k = 3; k < 5; k++)
                minutes += a[k];
            m = std::stoi(minutes);

            std::string duration = "";
            for (size_t k = 5; k < a.size(); k++)
                duration += a[k];
            d = std::stoi(duration);

            exps.push_back(Experiment{h, m, d});
        }
    }
    print(sorted(exps));
    return 0;
}