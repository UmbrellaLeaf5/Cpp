#include "checker.h"
#include "cell.h"

void Checker::detach() { cell = nullptr; }

void Checker::attach(const Cell& c)
{
    move(c.center().x - center().x, c.center().y - center().y);
    cell = &c;
}