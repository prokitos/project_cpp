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
#include <iomanip>


void zaMainM()
{
      // приходит строка. нужно добавить в конце цифру 1, или увеличить на 1 уже существующую цифру.
      //std::cout << incrementString("foobar99");


      //smallfuck. 
      // * = перевернуть бит в ячейке. > = указатель вправо. < = указатель влево.
      //std::cout << interpreter("<*<*", "10101");

      // дан набор букв алфавита, или нескольких алфовитов (в нижнем регистре)
      // вывести пропущенные буквы
      //std::cout << missing_alphabets("aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy"); // zz

      // вернуть строку чисел по возрастанию, если несколько чисел по порядку то написать их через тире. 1 2 3 4 5 = 1-5
      //std::cout << range_extraction({-6,-3,-2,-1,0,1,3,4,5,7,8,9,10,11,14,15,17,18,19,20});

      // вернуть сумму N чисел (1 + 1/4 + 1/7 + 1/10...), округ до 2 после запятой
      //std::cout << seriesSum(5);

      // убрать минимум из вектора, и не менять позиции элементов
      // std::vector<unsigned int> temp = removeSmallest({ 5, 3, 2, 1, 4 });
      // for(auto i: temp)
      //       std::cout << i << " ";

      // автоморфичное число или нет. (если квадрат числа заканчивается на то же число)
      //std::cout << autoMorphic(25);

      // найти самый часто повторящийся элемент в листе
      // std::forward_list<int> l = {1,2,3,4,2,3,2};
      // std::pair<int,int> temp = findMostFrequent(l);
      // std::cout << temp.first << "  " << temp.second;

      // вернуть true если слова в списке начинаются с окончания другого слова
      // excavate - endure - excess = true
      // trade - pole - view = false 
      //std::cout << solution({"excavate", "endure", "screen", "desire", "theater", "excess", "night"});

      // сумма двух строк
      //std::cout << sum_strings("123", "456");

      // вернуть строку, написав четные и нечетные буквы в разном регистре
      // std::pair<std::string, std::string> temp = capitalize("abcdef");
      // std::cout << temp.first << " " << temp.second;

      // псевдо шифрование. объединяет четные и нечетные числа в строке N раз.
      //std::cout << encrypt("This is a test!", 2) << std::endl;
      //std::cout << decrypt("s eT ashi tist!", 2) << std::endl;      

      // есть вектор чисел, нужно разделить их на первый-второй, и просуммировать.
      // std::pair<int,int> rowWs = rowWeights({50,60,70,80});
      // std::cout << rowWs.first << "  " << rowWs.second;

      // дан вектор чисел, вернуть самое минимальное число которое можно составить из этих чисел (без повторений)
      //std::cout << minValue({4,8,1,4});

      // case fixer. если большинство букв в ловер кейсе, то все слово в ловер кейс, иначе в аппер кейс, если равно то в ловер кейс.
      //std::cout << solve("CODe");

      // Дан путь в словах, сократить его (N S S W = S W)
      std::vector<std::string> res;
      std::vector<std::string> d1 = {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"};
      res = DirReduction::dirReduc(d1);
      for(auto i : res)
            std::cout << i << " ";

};

std::vector<std::string> DirReduction::dirReduc(std::vector<std::string> &arr)
{
      std::vector<std::string> result = arr;

            // перебор всего массива начиная со 2 элемента, чтобы сравнивать текущий и предидущий, и не словить выход за пределы вектора
            for (size_t i = 1; i < result.size(); i++)
            {     
                  // если подряд верх-низ
                  if( (result[i] == "NORTH" && result[i - 1] == "SOUTH") || (result[i - 1] == "NORTH" && result[i] == "SOUTH") )
                  {
                        // удаление этих двух элементов
                        result.erase(result.begin() + i);
                        result.erase(result.begin() + i - 1);
                        
                        // начинаем фор заново
                        i = 0;
                        continue;
                  }
                  // если подряд лево-право
                  if( (result[i] == "EAST" && result[i - 1] == "WEST") || (result[i - 1] == "EAST" && result[i] == "WEST") )
                  {     
                        // удаление этих двух элементов
                        result.erase(result.begin() + i);
                        result.erase(result.begin() + i - 1);

                        // начинаем фор заново
                        i = 0;
                        continue;
                  }
            }
      
      return result;
}

std::string solve(const std::string& str)
{
      int lCase = 0;
      int uCase = 0;

      // подсчет кол-во кейсов
      for(auto i : str)
      {
            if(std::tolower(i) == i)
                  lCase ++;
            else
                  uCase ++;
      }

      std::string result = str;
      bool lowerCase = false;

      if(lCase >= uCase)
            lowerCase = true;
      
      // перевод строки в ловер кейс или аппер кейс
      for (size_t i = 0; i < result.length(); i++)
      {
            if(lowerCase == true)
                  result[i] = std::tolower(result[i]);
            else
                  result[i] = std::toupper(result[i]);
      }
      
      return result;
}

unsigned long long minValue (std::vector <int> values)
{
      std::sort(values.begin(), values.end());
      std::string txtResult {};

      char last {};
      for (size_t i = 0; i < values.size(); i++)
      {
            if(last != values[i])
            {
                  last = values[i];
                  txtResult += std::to_string(last);
            }
      }
      
      unsigned long long result = std::stoull(txtResult);
      return result;
}

std::pair<int,int> rowWeights (const std::vector <int> &weights)
{
      std::pair<int,int> result {0,0};

      bool checker = false;
      for(auto i : weights)
      {
            if(checker == false)
            {
                  result.first += i;
                  checker = true;
            }
            else
            {
                  result.second += i;
                  checker = false;
            }
      }

      return result;
}

std::string encrypt(std::string text, int n)
{
      std::string temp = text;

      if(n < 1)
            n = 0;

      // n раз шифрует
      for (size_t i = 0; i < n; i++)
      {

            std::string temp1 {};
            std::string temp2 {};

            // добавляет четные и нечетные символы в temp1 и temp2
            for (size_t a = 0; a < temp.length(); a++)
            {
                 if(a % 2)
                 {
                        temp1 += temp[a];
                 }
                 else
                 {
                        temp2 += temp[a];
                 }
            }
            
            // объединяет четные и нечетные символы, и новая итерация будет идти по ним
            temp = temp1 + temp2;
      }
      
      return temp;
}

std::string decrypt(std::string encryptedText, int n)
{
      int len = encryptedText.length();
      int a = 0;

      if(n < 1)
            n = 0;

      // у четных и нечетных строк разнок макс-количество итераций до возвращения к стандартной строке
      if(len % 2)
      {
            a = 4;
      }
      else
      {
            a = 5;
      }

      // вычисление кол-ва итераций до возвращения к строке
      a = (a - n) % a;
      std::string temp = encrypt(encryptedText,a);

      return temp;
}


std::pair<std::string, std::string> capitalize(const std::string &s)
{
      std::string first {};
      std::string second {};
      std::pair<std::string, std::string> result;

      bool odd = true;
      for(auto i: s)
      {
            if(odd)
            {
                  first += std::tolower(i);
                  second += std::toupper(i);
            }
            else
            {
                  second += std::tolower(i);
                  first += std::toupper(i);
            }

            if(odd == true)
            {
                  odd = false;
            }
            else
            {
                  odd = true;
            }
      }

      result.first = first;
      result.second = second;
      return result;
}

std::string sum_strings(const std::string& a, const std::string& b)
{
      uint64_t temp1 = std::stoull(a);
      uint64_t temp2 = std::stoull(b);
      uint64_t summary = temp1 + temp2;
      return std::to_string(summary);
}

bool tempSolution(std::string word, const std::vector<std::string>& words)
{
      // если вектор пришел пустым то вернет тру
      if(words.empty())
      {
            return true;
      }

      // перебор по всем словам
      for (size_t i = 0; i < words.size(); i++)
      {
            // если последняя буква пришедшего слова совпадает с первой буквой слова из вектора
            // то создаем временный вектор, удаляем это слово и заходим снова в рекурсию
            if(word.back() == words[i].front() || word == "")
            {
                  std::vector<std::string> temp = words;
                  temp.erase(temp.begin() + i);

                  if(tempSolution(words[i], temp))
                  {
                        return true;
                  }
            }
      }

      // если мы не смогли ничего удалить и остался вектор, то возвращаем фолс
      return false;
}

bool solution(const std::vector<std::string>& words) 
{
      // вызов рекурсии
      return tempSolution("",words);
}

std::pair<int,int> findMostFrequent(std::forward_list<int> l)
{
      std::pair<int,int> output = {0,0};
      std::map<int,int> counters;

      // Запись элементов в справочник, получаем количество цифр
      for(auto i : l)
      {
            counters[i] ++;   
      }

      // перебираем элементы из полученного списка (чтобы найти именно первое макс количество по списку)
      // и если количество цифр больше старого то записываем в вывод количество и цифру.
      for(auto a : l)
      {
            auto i = counters[a];
            if(i > output.second)
            {
                  output.first = a;
                  output.second = i;
            }
      }
      
      return output;
}

std::string autoMorphic (int number)
{
      bool answer = false;

      int quad = number * number;
      int lenNumber = std::to_string(number).length();
      std::string StrNumb = std::to_string(number);
      std::string StrQuad = std::to_string(quad);
      
      
      for (size_t i = StrQuad.length() - 1; i >= 0; i--)
      {     
            // если каждый символ у входной строки совпал, то выкидываем и говорим что морф
            if(lenNumber == 0)
            {
                  answer = true;
                  break;
            }
            
            // если символ у квардрата и у числа совпадают то продолжать и снизить количество оставшихся символов
            if(StrQuad[i] == StrNumb[lenNumber - 1])
            {
                  lenNumber --;
            }
            // иначе выкинуть и сказать что число не морф
            else
            {
                  answer = false;
                  break;
            }
            
      }

      // вывод ответа
      std::string yesAnswer = "Automorphic";
      std::string noAnswer = "Not!!";
      if(answer == true)
            return yesAnswer;
      else
            return noAnswer;
}

std::vector<unsigned int> removeSmallest(const std::vector<unsigned int>& numbers) 
{
      std::vector<unsigned int> temp = numbers;
      auto min = std::min_element(temp.begin(),temp.end());

      // min_element содержит указатель на минимальный элемент, и мы его удаляем по указателю
      temp.erase(min);
      
      return temp;
}

std::string seriesSum(int n)
{
      if(n < 1)
      {
            return "0.00";
      }

      double summ = 1.00;

      for (size_t i = 0; i < n - 1; i++)
      {
            summ +=  1.0 / (4.0 + 3.0 * i); 
      }
      
      std::stringstream converter;
      converter << std::setprecision(2) << std::fixed << summ;
      return converter.str();
};

std::string range_extraction(std::vector<int> args)
{
      std::string result {};
      std::sort(args.begin(), args.end());

      int startValue = 0;
      bool startSeq = false;

      for (size_t i = 0; i < args.size(); i++)
      {     

            // если два числа идут подряд, а третье другое, то не надо писать их через тире. также если начата последовательность сюда не заходить.
            if(i + 2 < args.size() && args[i] + 1 == args[i + 1] && args[i] + 2 != args[i + 2] && startSeq == false)
            {
                  result += std::to_string(args[i]) + ",";
                  continue;
            }

            // если элемент не последний, и текущий элемент + 1 равен следующему
            if(i + 1 < args.size() && args[i] + 1 == args[i + 1])
            {
                  // если последовательность ещё не началась
                  if(startSeq == false)
                  {
                        startValue = args[i];
                        startSeq = true;
                  }

                  // так как мы внутри последовательности, нам не надо выводить текущее число, => скипаем эту итерацию
                  continue;
            }
            
            // если последовательность закончилась
            if(startSeq == true)
            {
                  result += std::to_string(startValue) + "-" + std::to_string(args[i]) + ",";

                  startSeq = false;
                  startValue = 0;

                  // так как мы уже сделали кастомный вывод, нам не нужен обычный => скипаем эту итерацию
                  continue;
            }

            // если обычное число без последовательности
            result += std::to_string(args[i]) + ",";
      }
      
      // убрать последнюю запятую
      result.pop_back();
      return result;
}

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