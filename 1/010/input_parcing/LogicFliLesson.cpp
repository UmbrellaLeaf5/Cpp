#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

// class Scheme {
// public:

// private:
//     map<string, Element> m_elements;
//     friend istream& operator>> (istream& is, Scheme s);

// };

// istream& operator>> (istream& is, Scheme s){

// }

struct ElementLine
{
    string name, type;
    vector<string> inputs;
};

istream& operator>> (istream& is, ElementLine& s)
{
    string str, s0;
    getline(is, str);
    stringstream ss(str);
    ss >> s.name >> s.type >> s0;
    if (s0 == "<")
    {
        while (ss >> s0)
        {
            s.inputs.push_back(s0);
        }
    }
    return is;
}

vector<ElementLine> Elements;

int main ()
{
    ifstream fin("input.txt");

    ElementLine a;
    while (fin >> a)
    {
        Elements.push_back(a);
        a = {};
    }
    for (auto i : Elements)
    {
        cout << i.name << ' ' << i.type << " * ";
        for (auto j : i.inputs)
            cout << j << ' ';
        cout << '\n';
    }
}

// scr1 source
// scr2 source
// ans1 and < src1
// src3 source
// ans2 or < src2 src3