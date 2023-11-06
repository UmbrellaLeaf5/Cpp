#include "logic.h"

Input::Input(Element& elem, State st) : m_elem{elem}, is_inv{st == State::inverted} {}

bool Input::signal() const
{
    bool res = element().out;
    return is_inv ? !res : res;
}

State Input::state() const { return is_inv ? State::inverted : State::direct; }