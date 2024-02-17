#pragma once

template <typename T>
class Counted_ptr {
 private:
  T* link;
  size_t* counter;

  void inc() {
    if (counter)
      ++*counter;
  }

  void decr() {
    if (counter && --*counter) {
      delete link;
      delete counter;
    }
  }

 public:
  Counted_ptr() : link{nullptr}, counter{nullptr} {}

  Counted_ptr(T* obj) : link{obj}, counter{new size_t(1)} {}

  Counted_ptr(const Counted_ptr<T>& c) : link{c.link}, counter{c.counter} {}

  Counted_ptr<T> operator=(const Counted_ptr<T>& c) {
    this->decr();
    link = c.link;
    counter = c.counter;
    inc();
  }

  T* operator->() { return link; }

  T& operator*() { return *link; }

  explicit operator bool() { return link != nullptr; }

  void reset(T* obj = nullptr) {
    delete link;
    link = obj;
  }

  ~Counted_ptr() : { decr(); }
};
