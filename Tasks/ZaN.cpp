#include "ZaN.h"


void zaMainN()
{

      // проверка конструктора копирования и перемещения.
      // operatorTest ex1 = operatorTest("tank");
      // operatorTest ex2 = operatorTest("samolet");

      // operatorTest ex3 = ex1;              // копирование
      // operatorTest ex3 = std::move(ex1);   // перемещение
    
      // operatorTest ex3("test");
      // ex3 = std::move(ex1);                   // оператор перемешения
      // ex3 = ex1;                              // оператор копирования

      // ex1.print();
      // ex3.print();


      // слить два массива в первый (вместо нулей)
      // massMerge();
      
      // массив из чисел от 1 до 100. оставить в массиве только числа которые делятся на 7 с остатком 3.
      // massSpecPrint();

      // вернуть самую длинную строку, из которой состоит слово.
      std::cout << longestStringRet({"zone", "ooccc", "theta", "form", "libe", "zas", "theta", "abigail"}, "oocccffuucccjzonajjkkkjyyyabigaileehhtheta");
      
      

}

std::string longestStringRet(const std::vector<std::string> &strarr, std::string stroka)
{
      std::vector<std::string> vec = strarr;

      // сортировка по длине слов.
      std::sort(vec.begin(), vec.end(), [](std::string a, std::string b){return a.length() > b.length();});

      for(auto i : vec)
      {     
            // поиск начинается с самого длинного слова, и если оно есть в строке то вывод, иначе следующее слово.
            if(stroka.find(i) != std::string::npos)
                  return i;
      }

      return "";
}


void massSpecPrint()
{
      int mass[100];

      for (size_t i = 0; i < std::size(mass); i++)
      {
            mass[i] = i + 1;
      }

      // так как у массива нет функции erase, можно сделать только цикл который дойдет до итератора.
      auto iter = std::remove_if(std::begin(mass),std::end(mass),[](int x){return x % 7 != 3;});
      for (auto i = std::begin(mass); i < iter; i++)
      {
            std::cout << *i << " ";
      }
}

void massMerge()
{
      int mass1[6]{1,2,3,0,0,0};
      int mass2[3]{2,5,6};
      
      int counter = 0;
      for(auto &i : mass1)
      {
            if(i == 0 && counter < std::size(mass2))
            {
                  i = mass2[counter];
                  counter ++;
            }
      }

      std::sort(std::begin(mass1),std::end(mass1));

      // решение O(n2)
      for(auto i : mass1)
            std::cout << i << " ";
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


