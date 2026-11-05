#include <iostream>
using namespace std;

class human{
public:
    string fam;
    string name;
    string otch;
    void setAge(int age){
        this->age = age;
    }
    void show(){
        cout << fam << ", "
             << age << endl;
    }
private:
    int age;
};

class Student:public human{
public:
    Student();
    Student(string f){
        fam = f;
    }
    Student(string f, string n){
        fam = f;
        name = n;
    }
    int gr_num;
    void show(){
        cout << fam << ", "
             << gr_num << endl;
    }
};

class Grup{
public:
    void addStudent(Student S){
        st[count] = S;
        count ++;
    }
    void show(){
        for (int i=0;i<count;i++) {
            cout << st[i].fam <<endl;
        }
    }
    int getCount(){
        return count;
    }
private:
    int count = 0;
    Student st[10];
};

int main()
{
    Grup gr;
    Student item("Valenov");
    item.gr_num = 1;
    gr.addStudent(item);
    gr.show();

    return 0;
}
