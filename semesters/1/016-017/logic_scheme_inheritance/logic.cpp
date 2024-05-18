#include "logic.h"

Element& operator>>(Element& lhs, Connection rhs) {
  Operation& op = rhs.op;
  // check_loop(lhs, op);
  lhs.elem_outputs.push_back(op);
  rhs.elem_inputs.push_back({lhs, rhs.st});
  return op;
}

Element& operator>>(Element& lhs, Operation& rhs) {
  return lhs >> Connection{rhs, State::direct};
}

Input::Input(Element& elem, State st)
    : m_elem{elem}, is_inv{st == State::inverted} {}

bool Input::sig() const {
  bool res = element().out;
  return is_inv ? !res : res;
}

State Input::state() const {
  return is_inv ? State::inverted : State::direct;
}