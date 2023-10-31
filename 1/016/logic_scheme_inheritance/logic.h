#pragma once

class Operation; 

class Element
{
    public:
        Element(State output_state, const std::vector <Output>& elem_outputs);
        void set_output_state (State st);
        State output_state() const;
        const std::vector <Output>& outputs const;
        Element& operator >> (Operation& rhs);

    protected:
        virtual void calc()=0;
        bool out {false};

    private:
        State out_state; // инвертированно или нет
        std::vector <Output> elem_outputs;
};

class Source : public Element
{
    public:
        Source(Signal sig, State output_state = State::direct, 
                    const std::vector <Output>& outputs = {});

        void set_signal (Signal sig);
        Source& operator= (Signal sig);
};