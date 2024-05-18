#pragma once

#include <functional>
#include <iostream>
#include <vector>

using namespace std;

class Operation;

enum class State { direct = 0, inverted };

using Output = std::vector<std::reference_wrapper<Element>>;

class Input;

struct Connection {
  reference_wrapper<Operation> op;
  State st;
};

class Element {
 public:
  // Element(State output_state, const vector <Output>& elem_outputs);
  void set_output_state(State st);
  State output_state() const;
  const vector<Output>& outputs() const;
  bool out{false};
  // слева может быть и src и oper, а справа - только oper или вспомог. Connection
  Element& operator>>(Connection rhs);
  Element& operator>>(Operation& rhs);

 protected:
  Element(State output_state, const vector<Output>& elem_outputs);
  // virtual void calc()=0;
  // bool out{false};

 private:
  State out_state;  // инвертированно или нет
  vector<Output> elem_outputs;
};

class Source : public Element {
 public:
  Source(bool sig, State output_state = State::direct,
         const vector<Output>& outputs = {});
  // void calc() override {}
};

class Operation : public Element {
 public:
  using Element::Element;

  // Input operator~() { return {*this, State::inverted}; }

  Operation& operator~();

  const vector<Input>& inputs() const;

 protected:
  virtual void calc() = 0;

 private:
  vector<Input> elem_inputs;
};

class And : public Operation {
 public:
  using Operation::Operation;

 protected:
  void calc() override;
};

class Or : public Operation {
 public:
  using Operation::Operation;

 protected:
  void calc() override;
};

class Input {
 public:
  Input(Element& elem, State st);

  Element& element() { return m_elem; }

  const Element& element() const { return m_elem; }

  bool sig() const;
  State state() const;

 private:
  reference_wrapper<Element> m_elem;
  // reference_wrapper улучшает копируемость, чтобы удобнее хранить векторы и т.д. в контейнерах
  const bool is_inv;
};

/*
вспоминаем, как она когда-то работала:
src1 >> and1 >> or 2;
        and1 >> ~or2;
*/

/*
void set_signal (Signal sig);
Source& operator= (Signal sig);
*/