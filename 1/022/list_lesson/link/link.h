#include <string>
using namespace std;

class Link
{
  private:
    Link* prev;
    Link* next;
    string value;

  public:
    Link(string value, Link* prev = nullptr, Link* next = nullptr)
        : value{value}, prev{prev}, next{next}
    {
    }

    Link* insert (Link* link);
    Link* add (Link* link);
    Link* find (const string& value);
    const Link* find (const string& value) const;
    Link* erase ();
    void print () const;
    const string get_value () const;
    // ~Link();
};
