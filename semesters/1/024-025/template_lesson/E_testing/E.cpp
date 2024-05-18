#include "E.h"

size_t E::count = 0;

void E::counter() {
  ++count;
  if (count > max_count)
    throw E_except();
}

E::E() {
  TRACE_FUNC;
  counter();
}

E::E(E&& e) {
  TRACE_FUNC;
  counter();
}

E::~E() {
  TRACE_FUNC;
  --count;
}