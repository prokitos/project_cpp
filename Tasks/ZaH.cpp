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
      Coffe cofe = CoffeeBuilder().set_cubano_coffee().with_sugar("Обычный").with_milk(3.5).build();
      cofe.showCoffe();

      // быстрая функция фибоначи
      //std::vector<int> vec = fibonachiFast(40);
      //for(auto i : vec)
      //      std::cout << i << " ";


};

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
