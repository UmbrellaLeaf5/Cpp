#include <iostream>

using namespace std;
void Decor()
{
    cout << endl << endl << "*****************************" << endl << endl;
}
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
class Student: public human
{
public:
    int gr_num;
    Student (string f)
    {
        fam = f;
    }
    Student (string f, string n )
    {
        fam = f;
        name = n;
    }
    void show()
    {
        cout << fam << ", " << gr_num << endl;
    }
private:

};

class Grups
{
public:
    void addStudent(Student S)
    {
        st[count] = S;
        count ++;
    }
    void show()
    {
        for (int i = 0; i < count; i ++)
        {
            cout << st[i].fam << endl;
        }
    }
    int getCount()
    {
        return count;
    }
private:
    int count = 0;
    Student st[10];
};

int main()
{
    Grups gr();
    Decor();


    return 0;
}
