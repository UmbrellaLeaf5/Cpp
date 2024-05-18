#include <iostream>

using namespace std;

class human
{
public:
    string fam;
    string name;
    string otch;
    void setAge(int age)
    {
        this->age = age;
    }
    void show()
    {
        cout << fam << ", " << age << endl;
    }
private:
    int age;
};

int main()
{
    human H;
    H.fam = "Абдухалимов";
    H.setAge(21);
    H.show();
    return 0;
}
