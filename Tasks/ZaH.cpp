#include "zaH.h"
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



void zaMainH()
{
      
      // функция создания кофе
      //Coffe cofe = CoffeeBuilder().set_cubano_coffee().with_sugar("Обычный").with_milk(3.5).build();
      //cofe.showCoffe();

      // быстрая функция фибоначи
      //std::vector<int> vec = fibonachiFast(40);
      //for(auto i : vec)
      //      std::cout << i << " ";


      // вернуть строки из 1 вектора, если они являются частью строк второго вектора.
      //std::vector<std::string> arr1 = {"arp", "tarp", "mice", "bull"};
      //std::vector<std::string> arr2 = {"lively", "alive", "harp", "sharp", "armstrong", "bully"};
      //std::vector<std::string> res = inArray(arr1,arr2);
      //for(auto i : res)
      //      std::cout << i << " ";

      // найти пропущенную букву в массиве. O(n)
      //char temp = findMissingLetter({'l', 'm', 'n', 'p', 'q', 'r', 's', 't'});
      //std::cout << temp;

      // 12 часовой вид в 24 часовой.
      //std::cout << to24HourTime( 12, 0, "am");

      // глубокое и поверхностное копирование
            // поверхностное. указатели в классе просто копируют адрес старого указателя
            InstCopy inst1 = InstCopy(100,"TEST");    
            inst1.show();
            InstCopy inst2 = inst1;
            inst1.change();   // меняется значение у указателя в первом классе.
            inst2.show();     // значение указателя второго класса сменилось тоже, т.к. они указывают на оду область.

            // глубокое. в указателях класса выделяется новая память.
            InstDeepCopy inst3 = InstDeepCopy(100,"lol");
            inst3.show();
            InstDeepCopy inst4 = inst3;
            inst3.change();   // меняется значение указателя в первом классе.
            inst4.show();     // указателю во втором классе пофигу.
   


};



std::string to24HourTime(int hour, int minute, const std::string& period) 
{
      std::string out {};

      if(hour == 12)
            hour -= 12;

      if(period == "pm")
      {
            hour += 12;
      }

      if(hour > 9)
      {
            out += std::to_string(hour);
      }
      else
      {
            out += "0" + std::to_string(hour);
      }

      if(minute > 9)
      {
            out += std::to_string(minute);
      }
      else
      {
            out += "0" + std::to_string(minute);
      }

      return out;
}

char findMissingLetter(const std::vector<char>& chars)
{
      char mass[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
      char output {};

      int j = 0;
      bool matchedCheck = false;
      bool isUpperCase = false;

      // перебор по массиву всех букв алфавита
      for (auto i : mass)
      {     
            // если буквы начали совпадать
            int lower = std::tolower(chars[j]);
            if(i == lower)
            {
                  matchedCheck = true;
                  
                  // большие буквы
                  if(chars[j] < 97)
                        isUpperCase = true;

                  j++;
            }

            // если буквы уже совпали и перестали совпадать
            if(matchedCheck == true && i != lower)
            {
                  output = i;
                  break;
            }

      }


      // если был верхний регист
      if(isUpperCase == true)
            output = std::toupper(output);
      
      return output;
}

std::vector<std::string> inArray(std::vector<std::string> &array1, std::vector<std::string> &array2)
{
      std::vector<std::string> res {};

      for (size_t i = 0; i < array1.size(); i++)
      {
            for (size_t j = 0; j < array2.size(); j++)
            {
                  if ( array2[j].find(array1[i]) != std::string::npos )
                  {
                        res.push_back(array1[i]);
                        break;
                  }
            }
            
      }
      
      return res;
}

std::vector<int> fibonachiFast(int max)
{
      std::vector<int> out {};
      out.reserve(max + 2);

      int first = 0;
      int second = 1;
      int temp = 0;
      out.push_back(first);
      out.push_back(second);

      for (size_t i = 2; i < max; i++)
      {
            temp = first + second;
            first = second;
            second = temp;
            out.push_back(second);
      }
      
      return out;
};
