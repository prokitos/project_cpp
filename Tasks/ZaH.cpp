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
      
      Coffee actual = CoffeeBuilder().set_black_coffee().with_sugar("Regular").with_milk(3.2).build();
      std::cout << actual.sort << " ";
      std::cout << actual.milk[0].fat << " ";
      std::cout << actual.sugar[0].sort << " ";



};
