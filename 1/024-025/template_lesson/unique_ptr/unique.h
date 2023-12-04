#pragma once

template <typename T> class Unique_ptr
{
  public:
    Unique_ptr() : link{nullptr} {};

    Unique_ptr(T* obj) : link{obj} {};
    Unique_ptr(const Unique_ptr<T>&) = delete;

    Unique_ptr(Unique_ptr<T>&& U)
        : link{U.release()}

          {};

    ~Unique_ptr() { delete link; }

    T* release ()
    {
        T* buff = link;
        link = nullptr;
        return buff;
    }

    T* operator->() { return link; }

    T& operator* () { return *link; }

    explicit operator bool () { return link != nullptr; }

    void reset (T* obj = nullptr)
    {
        delete link;
        link = obj;
    }

  private:
    T* link;
};