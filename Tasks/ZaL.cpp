#include "zaL.h"
#include <vector>
#include <algorithm>
#include <math.h>
#include <iterator>    
#include <sstream>
#include <map>
#include <iterator>    
#include <sstream>
#include <regex>
#include <numeric>

class deb
{
public:
      deb(){};
      int x;
};

void zaMainL()
{

      // являются ли элементы вектора 1, подэлементами вектора 2 (возведенные в степень).
      //std::vector<int> a = {121, 144, 19, 161, 19, 144, 19, 11};
      //std::vector<int> b = {14641, 20736, 361, 25921, 361, 20736, 361, 121};
      //std::cout << comp(a,b);

      // мяч бросается с крыши, отскакивает на высоту, сколько раз мяч увидят на Н этаже.
      //std::cout << bouncingBall(30, 0.66, 1.5);

      // передвинуть нули в конец вектора.
      //std::vector<int> input = {1, 2, 1, 1, 3, 1, 0, 0, 0, 0};
      //std::vector<int> output = move_zeroes(input);
      //for(auto i : output)
      //      std::cout << i;

      // мексиканская волна. Заглавная буква в слове будет смещаться в право
      //std::vector<std::string> output = wave("hello");
      //for(auto i : output)
      //      std::cout << i << " ";


      // если умножение двух подряд идущих чисел фибоначи дают это число, то вернуть 2 эти числа и тру, иначе фолс.
      // для сокращения кода можно убрать внутренний вектор и return {first,second,1} , а в while проверять First * Second, и убрать CurMax.
      //std::vector<unsigned long long> output = productFib(714);
      //for(auto i : output)
      //      std::cout << i << " ";
      

      // ROT13 шифр. вроде переставляет буквы на 13 вперед.
      // можно индексы 64 91 96 123 поменять на a A z Z
      std::cout << rot13("EBG13 rknzcyr.");


};


std::string rot13(const std::string& str)
{     
      std::string out = str;

      for (size_t i = 0; i < str.length(); i++)
      {
            int index = str[i];
            
            // большие английские
            if(index > 64 && index < 91)
            {
                  index +=  13;
                  index = index % 91;
                  if(index < 65)
                        index += 65;
            }
            // маленькие английские
            if(index > 96 && index < 123)
            {
                  index +=  13;
                  index = index % 123;
                  if(index < 97)
                        index += 97;
            }

            out[i] = index;
      }

      return out;
}

typedef unsigned long long BigLong;
std::vector<BigLong> productFib(BigLong prod)
{
      std::vector<BigLong> exitVec {};

      BigLong First = 0;
      BigLong Second = 1;
      BigLong Temp {};
      BigLong CurMax {};
      

      while(CurMax < prod)
      {
            Temp = First + Second;
            First = Second;
            Second = Temp;
            CurMax = First * Second;
      }

      exitVec.push_back(First);
      exitVec.push_back(Second);

      if(CurMax == prod)
             exitVec.push_back(1);
      else
             exitVec.push_back(0);

      return  exitVec;
}

std::vector<std::string> wave(std::string y)
{
      std::vector<std::string> result {};

      if(y.empty())
            return result;

      for (size_t i = 0; i < y.length(); i++)
      {
            if(y[i] != ' ')
            {
                  y[i] = std::toupper(y[i]);
                  result.push_back(y);
                  y[i] = std::tolower(y[i]);
            }
      }
      
      return result;
}

std::vector<int> move_zeroes(const std::vector<int>& input) 
{
      std::vector<int> output {};
      int zeroCount {};

      // перенос в новый вектор всех чисел
      for(auto i : input)
      {
            if(i == 0)
                  zeroCount ++;
            else
                  output.push_back(i);      
      }

      // в конце добавление нулей
      for (size_t i = 0; i < zeroCount; i++)
      {
            output.push_back(0);
      }

      return output;
}

int bouncingBall(double h, double bounce, double window)
{     
      // проверка некорректных введеных данных
      if(h <= 0 || bounce >= 1 || bounce <= 0 || window >= h)
            return -1;
      
      int result = {};

      // мяч пролетает из окна в одну и вдругую сторону
      while (h > window)
      {
            h = h * bounce;
            result += 2;
      }
      result --;

      return result;
};


bool comp(std::vector<int>&a, std::vector<int>&b)
{
      bool checker[b.size()] {};
      bool result = true;

      std::vector<int> temp1 = a;
      std::vector<int> temp2 = b;

      for (size_t i = 0; i < temp2.size(); i++)
      {
            for (size_t j = 0; j < temp1.size(); j++)
            {
                  if(temp1[j] * temp1[j] == temp2[i])
                  {
                        temp1.erase(temp1.begin() + j);
                        temp2.erase(temp2.begin() + i);
                        checker[i] = true;
                        i --;
                        j --;
                        break;
                  }
            }

      }

      if(temp1.empty())
            return true;
      else 
            return false;

};
