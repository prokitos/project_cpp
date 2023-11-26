#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>
#include <iterator>
#include <sstream>
#include <map>

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


void massMerge();
void massSpecPrint();

std::string longestStringRet(const std::vector<std::string> &strarr, std::string stroka);

double posAverage(const std::string &s);

bool scramble(const std::string& s1, const std::string& s2);