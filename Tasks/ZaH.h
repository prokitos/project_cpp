#include <iostream>
#include <vector>
#include <map>
#include <list>

void zaMainH();

bool narcissistic( int value );

std::string get_middle(std::string input);

float find_uniq(const std::vector<float> &v);

char findMissingLetter(const std::vector<char>& chars);

std::vector<int> fibonachiFast(int max);

std::vector<std::string> inArray(std::vector<std::string> &array1, std::vector<std::string> &array2);

std::string to24HourTime(int hour, int minute, const std::string& period);

// класс для создания коффе
struct Milk
{
  float fat;
};
struct Sugar
{
  std::string sort;
};

class Coffe
{
public:
  Coffe(){};
  void showCoffe()
  {
    // вывод типа кофе
    std::cout << "Сорт кофе = " << sort << std::endl;
    
    // вывод жирности молока
    std::cout << " Молоко = ";
    for(auto i: milk)
      std::cout << i.fat << " ";
    std::cout << std::endl;

    // вывод сортов сахара
    std::cout << " Вид сахара = ";
    for(auto i: sugar)
      std::cout << i.sort << " ";
    std::cout << std::endl;

  };

  std::string sort;
  std::vector<Milk> milk;
  std::vector<Sugar> sugar;
};

class CoffeeBuilder
{
public:
  CoffeeBuilder() {};

  // у всех функций тип класса, чтобы они возвращали тот же объект, и можно было дальше обращаться к нему в одну строку.

  // добавление видов кофе
  CoffeeBuilder set_black_coffee() 
  {
    _coffe.sort = "Черный";
    return *this;
  }
  CoffeeBuilder set_cubano_coffee() 
  {
    _coffe.sort = "Кубанский";
    with_sugar("Серый");
    return *this;
  }
  CoffeeBuilder set_antoccino_coffee() 
  {
    _coffe.sort = "Американо";
    with_milk(0.5);
    return *this;
  }

  // добавление молока и сахара
  CoffeeBuilder with_milk(float fat) 
  {
    _coffe.milk.push_back({fat});
    return *this;
  }
  CoffeeBuilder with_sugar(const std::string &sort) 
  {
    _coffe.sugar.push_back({sort});
    return *this;
  }

  // возвращает созданный объект кофе, который записывается в экземпляр.
  Coffe build() 
  {
    return _coffe;
  }

private:
  Coffe _coffe; // объект кофе, который хранит сахар тип и тд
};


class InstCopy
{
public:
  InstCopy(int x, std::string name)
  {
    this->name = name;  
    money = new int;
    *money = x;
  }
  void change()
  {
    *money -= 50;
  }
  void show()
  {
    std::cout << name << " " << *money << std::endl;
  }
protected:
  int* money {};
  std::string name {};
};

class InstDeepCopy
{
public:
  InstDeepCopy(int x, std::string name)
  {
    this->name = name;  
    money = new int;
    *money = x;
  }
  InstDeepCopy(InstDeepCopy& sample)
  {
    name = sample.name;
    money = new int;
    *money = *sample.money;
  }
  void change()
  {
    *money -= 50;
  }
  void show()
  {
    std::cout << name << " " << *money << std::endl;
  }
protected:
  int* money {};
  std::string name {};
};