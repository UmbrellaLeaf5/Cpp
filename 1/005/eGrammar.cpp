//g++ -Og -Wall -Wextra -pedantic -Ilib -o bin/p 1/eGrammar.cpp

/*
Необходимо проверить на корректность следующей грамматике:


Предложение : Имя_
    существительное Глагол          // Например , С++ rules
    Предложение Союз Предложение    // Например , Birds fly but
                                    // fish swim
Союз :
    "and"
    "or"
    "but"
Имя_существитепьное :
    "Ьirds "
    "fish"
    "С++"
Глагол :
    "rules "
    "fly"
    "swim" 

идеи:
vector<string> noun_items {"C++", "fish", "birds"};
vector<string> verb_items {"fly", "swim", "rules"};
vector<string> conjuction_items {"and", "but", "or"};

bool contains (const vector<string>& items, const string& val)
{
    bool f = false;
    for(const auto& x: items){
        if(val == x){
            f = true;
            break;
        }
    }
    return f;
}
*/

#include "../lib/std_lib_facilities.h"

vector<string> noun_items = {"C++", "fish", "birds"};
vector<string> verb_items = {"fly", "swim", "rules"};
vector<string> conjunction_items = {"and", "but", "or"};


bool contains(const vector<string>& items, const string& val){
    for(const string &str : items){
        if(val == str){
            return true;
        }
    }
    return false;
}


bool sentence(){
    string word;
    cin >> word;
    if(cin.fail() || !(contains(noun_items, word))) return false;
        cin >> word;
    if(cin.fail() || !(contains(verb_items, word))) return false;
        cin >> word;
    if(!cin.fail() && word == ".") return true;
    if(cin.fail() || !(contains(conjunction_items, word))) return false;
    return sentence();
}


int main(){
    while(!cin.fail()){
        bool ok = sentence();
        cout << (ok ? "OK" : "not OK") << endl;
    }
    return 0;
}