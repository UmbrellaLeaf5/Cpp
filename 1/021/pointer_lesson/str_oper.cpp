#include "str_oper.h"

bool startswithx(const char* s, const char* x) {
  while (*s != '\0' && *s == *x) {
    s++;
    x++;
  }
  return *x == '\0';
}

const char* findx(const char* s, const char* x) {
  while (*s != '\0' && !startswithx(s, x)) {
    s++;
  }
  return s;
}
