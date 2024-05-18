#include <iostream>
#include "link/link.h"

using namespace std;

int main() {
  Link* l = new Link("2");
  l->insert(new Link("1"))->print();
  l->add(new Link("3"))->print();
  cout << l->find("2") << endl;
  l->find("2")->print();
  l->find("3")->print();
  cout << l->find("4") << endl;
  // l->find("4")->get_value();
  // l->find("4")->print();
}