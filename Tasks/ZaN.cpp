#include "ZaN.h"

void zaMainN()
{

      // проверка конструктора копирования и перемещения.
      operatorTest ex1 = operatorTest("tank");
      operatorTest ex2 = operatorTest("samolet");

      // operatorTest ex3 = ex1;              // копирование
      operatorTest ex3 = std::move(ex1);   // перемещение
    
      // operatorTest ex3("test");
      // ex3 = std::move(ex1);                   // оператор перемешения
      // ex3 = ex1;                              // оператор копирования

      ex1.print();
      ex3.print();



}


operatorTest::operatorTest(const operatorTest &src)
{
      name = src.name;
};
operatorTest::operatorTest(operatorTest &&src)
{
      std::swap(src.name,name);
};
operatorTest& operatorTest::operator = (operatorTest &src)
{
      name = src.name;
      return *this;
}
operatorTest& operatorTest::operator = (operatorTest &&src)
{
      std::swap(src.name, name);
      return *this;
}
void operatorTest::print()
{
      std::cout << name << std::endl;
};


