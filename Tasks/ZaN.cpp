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
      // std::cout << longestStringRet({"zone", "ooccc", "theta", "form", "libe", "zas", "theta", "abigail"}, "oocccffuucccjzonajjkkkjyyyabigaileehhtheta");
      
      // имеются строки состоящие из цифр (0469). найти процент совпадения цифр на одинаковых позициях
      //std::cout << posAverage("6900690040, 4690606946, 9990494604");

      // даны 2 строки в ловеркейсе. если из букв первой строки можно собрать вторую, то вернуть true.
      // std::cout << scramble("rkqodlw", "world");         // true ...  есть все буквы
      // std::cout << scramble("katas", "steak");              // false...  нет буквы e

      // тест std алгоритмов
      algorithmTest();
}

bool scramble(const std::string& s1, const std::string& s2)
{
      std::map<char,int> first;
      std::map<char,int> second;

      // подсчет всех букв в первой строке
      for(auto i : s1)
      {
            first[i] ++;
      }
      // подсчет всех букв во второй строке
      for(auto i : s2)
      {
            second[i] ++;
      }

      // сравнение полученных букв
      for(auto i : second)
      {
            char bukva = i.first;
            int chislo = i.second;

            // если в первой строке было меньше таких букв, либо 0 (вообще не было), то возвращаем что невозможно собрать такую строку
            if(chislo > first[bukva])
                  return false;
      }

      // иначе если всех букв хватило (ни разу не зашло внутрь того условия) то можно собрать такую строку 
      return true;
}


double posAverage(const std::string &s)
{
      double result = 0;
      int map[4]{0,0,0,0};
      int len = 0;

      std::stringstream tempString(s);
      std::vector<std::string> vec(std::istream_iterator<std::string>(tempString),{});

      // удаление запятых
      for(auto &i : vec)
      {
            auto pos = i.find(',');
            if(pos < i.length())
                  i.erase(pos,1);
      }

      len = vec[0].length();
      double charCounter = 0;

      // сравнение по буквам
      for (size_t i = 0; i < len; i++)
      {     
            // сравнение по разным векторам
            for(auto item : vec)
            {
                  if(item[i] == '0')
                        map[0] ++;
                  if(item[i] == '4')
                        map[1] ++;
                  if(item[i] == '6')
                        map[2] ++;
                  if(item[i] == '9')
                        map[3] ++;
            }

            // сколько разных чисел попадалось
            int count = 0;
            if(map[0] > 0)
                  count ++;
            if(map[1] > 0)
                  count ++;
            if(map[2] > 0)
                  count ++;
            if(map[3] > 0)
                  count ++;

            // если одинаковых цифр 2 и больше, то прибавляем 
            if(map[0] > 1)
                  charCounter += map[0] / count;
            if(map[1] > 1)
                  charCounter += map[1] / count;
            if(map[2] > 1)
                  charCounter += map[2] / count;
            if(map[3] > 1)
                  charCounter += map[3] / count;

            map[0] = 0; map[1] = 0; map[2] = 0; map[3] = 0;
      }

      double charAllCount = len * vec.size();
      result = (charCounter / charAllCount ) * 100;
      
      return result;
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


void algorithmTest()
{
      // найти позицию пробела в строе
      // std::string stroka = "basic text";
      // if( stroka.find(" ") != std::string::npos )
      // {
      //       auto pos = stroka.find(" ");
      //       std::cout << pos << std::endl;
      // }
      // else
      // {
      //       std::cout << "нет пробела" << std::endl;
      // }

      // есть ли число в векторе, и на какой позиции
      // std::vector<int> vec {0,1,2,9,3,4,5,6,7,8,9,2,4,9};
      // int searchNum = 9;
      // if( std::find(std::begin(vec), std::end(vec), searchNum) != std::end(vec) )
      // {
      //       auto pos = std::find(std::begin(vec), std::end(vec), searchNum);
      //       std::cout << *pos << "  at pos " << pos - vec.begin() << std::endl;
      // }

      // найти все позиции числа 9 в векторе.
      // std::vector<int> vec {0,1,2,9,3,4,5,6,7,8,9,2,4,9};
      // int searchNum = 9;
      // if( std::find(std::begin(vec), std::end(vec), searchNum) != std::end(vec) )
      // {
      //       auto realPos = 0;
      //       auto pos = std::find(std::begin(vec), std::end(vec), searchNum);
      //       while(pos != vec.end())
      //       {
      //             realPos = pos - vec.begin();
      //             std::cout << *pos << "  at pos " << realPos << std::endl;
      //             pos = std::find(pos + 1, std::end(vec), searchNum);
      //       }
      // }

      // найти первое нечетное число
      // std::vector<int> vec {1,2,3,4,5,6,7,8,9,2,4,9};
      // auto pos = std::find_if(vec.begin(),vec.end(),[](int x){return x % 2 == 0;});
      // std::cout << *pos << "  at pos " << pos - vec.begin() << std::endl;

      // умножить все числа в векторе на 2
      // std::vector<int> vec {1,2,3,4,5,6};    // можно вставить результат в другой вектор
      // std::transform(vec.begin(), vec.end(), vec.begin(), [](int x){return x * 2;});
      // for(auto i : vec)
      //       std::cout << i << "  ";

      // все ли числа из вектора 1 есть в векторе 2 ?
      // std::vector<int> vec1 {5,6,1};
      // std::vector<int> vec2 {1,1,1,2,3,4,5,6};
      // std::sort(vec1.begin(), vec1.end());
      // std::sort(vec2.begin(), vec2.end());
      // if( std::includes(vec2.begin(), vec2.end(), vec1.begin(), vec1.end()) )
      //       std::cout << "все элементы есть во втором множестве" << std::endl; 
      // else
      //       std::cout << "не все элементы во втором множестве" << std::endl; 

      // найти сколько элементов между цифрами 5
      // std::vector<int> vec {1,5,1,1,2,3,4,5,6};
      // int findNumb = 5;
      // auto iter1 = std::find(vec.begin(), vec.end(), findNumb);
      // auto iter2 = std::find(iter1 + 1, vec.end(), findNumb);
      // std::cout << std::distance(iter1, iter2) - 1 << " элементов между цифрами 5";

      // убрать повторяющиеся подряд элементы
      // std::vector<int> vec {1,1,1,2,3,4,5,6};
      // auto iter = std::unique(vec.begin(), vec.end());
      // auto resizeLen = std::distance(vec.begin(), iter);
      // vec.resize(resizeLen);
      // for(auto i : vec)
      //       std::cout << i << " ";

      // убрать любые повторяющиеся элементы в векторе, но оставить порядок. если элементы просто добавлять в set, то порядок сбросится
      // std::vector<int> vec {1,4,1,7,2,2,3,4,7};
      // std::vector<int> result;
      // std::set<int> temp;
      // for(auto i : vec)
      // {
      //       auto boolTemp = temp.insert(i);
      //       if(boolTemp.second == true)
      //       {
      //             result.push_back(i);
      //       }
      // }
      // for(auto i : result)
      //       std::cout << i << " ";
}