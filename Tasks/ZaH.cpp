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
      char temp = findMissingLetter({'l', 'm', 'n', 'p', 'q', 'r', 's', 't'});
      std::cout << temp;

};

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
