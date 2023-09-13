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
      std::vector<std::string> arr1 = {"arp", "tarp", "mice", "bull"};
      std::vector<std::string> arr2 = {"lively", "alive", "harp", "sharp", "armstrong", "bully"};
      std::vector<std::string> res = inArray(arr1,arr2);
      for(auto i : res)
            std::cout << i << " ";

};

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
