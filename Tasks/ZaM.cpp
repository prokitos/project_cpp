#include "zaM.h"
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
#include <chrono>
#include <bitset>

void zaMainM()
{
      // приходит строка. нужно добавить в конце цифру 1, или увеличить на 1 уже существующую цифру.
      //std::cout << incrementString("foobar99");


      //smallfuck. 
      // * = перевернуть бит в ячейке. > = указатель вправо. < = указатель влево.
      //std::cout << interpreter("<*<*", "10101");

      // дан набор букв алфавита, или нескольких алфовитов (в нижнем регистре)
      // вывести пропущенные буквы
      std::cout << missing_alphabets("aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy"); // zz

};

std::string missing_alphabets(const std::string &s)
{
      std::string result = "";
      int mass[26] {};
      int max = 0;

      // Добавление количества букв в массив. символ будет индексом, и ему плюсуется количество. чтото вроде мапа.
      for(auto i : s)
      {
            mass[i - 'a'] ++;
      }

      // находим сколько максимум одинаковых букв, значит столько алфавитов в последовательности.
      auto iter = std::max_element(std::begin(mass), std::end(mass));
      max = *iter;
      
      // перебираем массив с количеством букв, и если букв меньше чем кол-во алфавитов, то плюсуем эту букву в результат.
      for (size_t i = 0; i < 26; i++)
      {
            if(mass[i] < max)
            {
                  result += 'a' + i;
                  mass[i] ++;
                  
                  i --;
            }
      }

      return result;
}

std::string interpreter(const std::string &code, const std::string &tape)
{
      std::string result = tape;
      int pos = 0;
      int brackCount = 0;

      for (size_t i = 0; i < code.length(); i++)
      {
            switch (code[i])
            {
            case '*':
                  if(result[pos] == '0')
                        result[pos] = '1';
                  else
                        result[pos] = '0';
                  break;

            case '>':
                  pos ++;
                  pos = pos % result.length();
                  break;

            case '<':
                  pos --;
                  if(pos < 0)
                        pos = result.length() - 1;
                  break;

            case '[':
                  brackCount = 0;
                  if(result[pos] == '0')
                  {
                        brackCount ++;
                        while (brackCount > 0)
                        {
                              i++;
                              if(code[i] == '[') {brackCount ++;};
                              if(code[i] == ']') {brackCount --;};
                        }
                  }
                  break;

            case ']':
                  brackCount = 1;
                  if(result[pos] == '1')
                  {
                        while (brackCount > 0)
                        {
                              i --;
                              if(code[i] == '[') {brackCount --;};
                              if(code[i] == ']') {brackCount ++;};
                        }
                  }
                  break;
            
            default:
                  break;
            }

      }

      return result;
}

std::string incrementString(const std::string &str)
{
      std::string result {};
      std::string number {};
      int numb {};

      // перебор старой строки
      for(auto i : str)
      {     
            // если буква
            if(std::tolower(i) >= 'a' && std::tolower(i) <= 'z')
            {
                  // если попалось число, но оно в середине строки
                  result += number;
                  number = "";
                  
                  result += i;
            }
            // если цифры
            if(i >= '0' && i <= '9')
            {
                  number += i;
            }
      }

      int oldLen = 0;
      int newLen = 0;

      // добавление +1 к числу
      if(number == "")
            number = "0";

      oldLen = number.length();
      numb = std::stoi(number);
      numb ++;

      number = std::to_string(numb);
      newLen = number.length();

      if(oldLen > newLen)
      {
            int diff = oldLen - newLen;
            for (size_t i = 0; i < diff; i++)
            {
                  result += '0';
            }
      }
      result += number;

      return result;
}