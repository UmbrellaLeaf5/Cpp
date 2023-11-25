#include "link.h"
#include <iostream>

// Link::~Link()
// { /* all done */
// }

Link* Link::insert(Link* link)
{
    if (this == nullptr)
        return link;
    if (link == nullptr)
        return this;
    link->next = this;
    link->prev = this->prev;
    this->prev = link;
    if (link->prev != nullptr)
        link->prev->next = link;
    return link;
}

Link* Link::add(Link* link)
{
    if (this == nullptr)
        return nullptr;
    if (!link)
        return this;
    link->next = this->next;
    link->prev = this;
    this->next = link;
    return link;
}

Link* Link::find(const std::string& str)
{
    Link* helper = this;
    while (helper != nullptr)
    {
        if (helper->value == str)
            return helper;
        helper = helper->next;
    }
    return nullptr;
}

const Link* Link::find(const string& str) const
{
    Link* l = const_cast<Link*>(this);
    return l->find(str);
}

Link* Link::erase()
{
    if (this == nullptr or this->prev == nullptr or this->next == nullptr)
        return nullptr;
    this->prev->next = this->next;
    this->next->prev = this->prev;
    return this;
}

void Link::print() const
{
    if (this != nullptr)
        cout << this->value << std::endl;
    else
        cout << "nullptr" << std::endl;
}

const string Link::get_value() const
{
    if (this != nullptr)
        return this->value;
    return "nullptr";
}