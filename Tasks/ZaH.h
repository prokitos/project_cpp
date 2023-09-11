#include <iostream>
#include <vector>
#include <map>
#include <list>

void zaMainH();

//
struct Milk 
{
  float fat;
};

struct Sugar 
{
  std::string sort;
};

struct Coffee 
{
  std::string sort;
  std::vector<Milk> milk;
  std::vector<Sugar> sugar;
};

class CoffeeBuilder 
{
  public:
    CoffeeBuilder() {}

    CoffeeBuilder set_black_coffee() 
    {
      _coffee.sort = "Black";
      return *this;
    }
    CoffeeBuilder set_cubano_coffee() 
    {
      _coffee.sort = "Cubano";
      with_sugar("Brown");
      return *this;
    }
    CoffeeBuilder set_antoccino_coffee() 
    {
      _coffee.sort = "Americano";
      with_milk(0.5);
      return *this;
    }
    CoffeeBuilder with_milk(float fat) 
    {
      _coffee.milk.push_back({fat});
      return *this;
    }
    CoffeeBuilder with_sugar(const std::string &sort) 
    {
      _coffee.sugar.push_back({sort});
      return *this;
    }
  
    Coffee build() 
    {
      return _coffee;
    }
  private:
    Coffee _coffee;
};