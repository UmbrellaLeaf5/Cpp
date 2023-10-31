#pragma once

class Operation; 

class Element
{
    public:
        //Element(State output_state, const std::vector <Output>& elem_outputs);
        void set_output_state (State st);
        State output_state() const;
        const std::vector <Output>& outputs const;
        Element& operator >> (Operation& rhs);

    protected:
        Element(State output_state, const std::vector <Output>& elem_outputs);
        //virtual void calc()=0;
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
        //void calc() override {}
};

class Operation : public Element
{
    public:
        using Element::Element;
        Connection operator~ (); //const?
        const std::vector <Input>& inputs() const;
    
    protected: 
        virtual void calc() = 0;
    
    private:
        std::vector <Input> elem_inputs;
};

class And : public Operation
{
    public:
        using Operation::Operation;
    
    protected:
        void calc() override;
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