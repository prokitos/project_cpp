#include <string>
#include <iostream>

void zaMainN();


class operatorTest
{
public:
    operatorTest(std::string name)
    {
        this->name = name;
    };

    operatorTest(const operatorTest &src); // копирование
    operatorTest& operator = (operatorTest &src); // присваивание копированием

    operatorTest(operatorTest &&src); // перемещение
    operatorTest& operator = (operatorTest &&src); // присваивание перемещением

    void print();   // вывод name
private:
    std::string name = "null";
};