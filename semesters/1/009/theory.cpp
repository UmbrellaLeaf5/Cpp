/*
Интерфейс класса - часть методов класса, которые доступны пользователю
Реализация класса - часть методов класса, которые не доступны полльзователю

const в классе используется для объявления метода, который не будет изменять объект класса

class A
{
    public:
        static voitd do();
        const vector<int>& data() const {return m_data;}
        vecor<int>& data() {return m_data;}
    private:
        vector<int> m_data;
};

если объявить какой-то метод статическим (static), то этот метод будет принадлежать всему классу
и не имеет права обращаться к private.
и тогда A::do(); - не вызовет ошибки
однако в остальных случаях следует использовать this

const string& f()
{
    static string def_val = "some string"; - способ жизни static схож с глобальной переменной -
                                             на проятжении всей программы
    return def_val; - так что это разумно
}
если локальная, то память о ней в стеке, при завершении память освобождается
и при возврате её ссылки мы получаем неожиданное поведение
*/