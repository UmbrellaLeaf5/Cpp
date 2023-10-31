#include "std_lib_facilities.h"
#pragma once

class Person  // базовый класс
{
  protected:
    string name;

  public:
    string get_name () const { return name; }
};

class Student : public Person  // класс-наследний
{
  private:
    int stud_id;

  public:
    int get_id () const { return stud_id; }
};

class A
{
  public:
    virtual void Print () const { cout << "A" << endl; }
};

class B : public A
{
  public:
    void Print () const { cout << "B" << endl; }
};

void ShowInf (const A& a) { a.Print(); }