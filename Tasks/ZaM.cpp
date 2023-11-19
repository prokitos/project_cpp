#include "zaM.h"
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <unordered_map>
#include <iterator>    
#include <sstream>
#include <regex>
#include <numeric>
#include <chrono>
#include <bitset>
#include <iomanip>
#include <set>
#include <array>


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
      // std::vector<std::string> res;
      // std::vector<std::string> d1 = {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"};
      // res = DirReduction::dirReduc(d1);
      // for(auto i : res)
      //       std::cout << i << " ";

      // перевернуть строку, и оставить только буквы
      //std::cout << reverse_letter("krish21an");

      // найти в строке последовательность согласных букв, и вывести наибольшую сумму из всех последовательностей
      //std::cout << solveStr("k.ZODIACg"); // c + g = 10;

      // сумма чисел от а до b
      //std::cout << get_sum(-1,2);

      // проверка отсортирован ли массив
      // std::cout << is_sorted_and_how({15, 7, 3, -8});

      // массив чисел. умножить 2 числа подряд, и найти самое большое такое значение.
      // std::cout << adjacentElementsProduct({5,1,2,3,1,4});  // 5*1 = 5,  2*3 = 6!!!

      // дан вектор чисел, и лимитированое число. если все значения в векторе меньше или равны лимиту то тру, иначе фолс.
      // std::cout << small_enough(std::vector<int>{78, 117, 110, 99, 104, 117, 107, 115}, 100);

      // приходит строка со словами. перевенуть слова которые длинной 5+ символов
      // std::cout << spinWords("Hey fellow warriors");

      // найти четное среди нечетных, или наоборот
      //std::cout << FindOutliers({2,6,8,10,5});

      // отсортировать нечетные числа, а четные оставить на своих местах
      // std::vector<int> res = sortArrayOdd({9, 8, 7, 6, 5, 4, 3, 2, 1, 0});
      // for(auto i : res)
      //       std::cout << i << " ";

      // отсортировать вектор, чтобы сначала шли четные а потом нечетные цифры (в изначальном порядке).
      // std::vector<int> mass = sortOddEven({2,1,0,3,4,5,6});
      // for(auto i : mass)
      //       std::cout << i << " ";

      // строка с числами. отсортировать по сумме цифр в числе.
      //std::cout << orderWeightStr("56 65 74 100 99 68 86 180 90");

      // найти число которое встречается нечетное количество раз
      //std::cout << findOdder({1,1,2,-2,5,2,4,4,-1,-2,5});

      // удалить элемент если он встречается больше чем N раз. порядок элементов должен соблюдаться.
      // std::vector<int> temp = deleteElements({20,37,20,21},1);
      // for(auto i : temp)
      //       std::cout << i << " ";

      // сдвинуть гласные буквы в слове на N
      // std::cout << vowelShiftText(";jibOTBPrak0i72M2DlkNAZ?", 3);

      // посчитать и вывести кол-во разных букв в слове
      // std::map<char, unsigned> temp = countChars("abaddon");
      // for(auto i : temp)
      //       std::cout << i.first << "  " << i.second << std::endl;

      // посчитать сумму положительных чисел в строке.
      //std::cout << sumPositiv("0 4 12 -10 -40 4");

      // строку текста в строку чисел с номерами букв алфавита
      // std::cout << alphabet_position_print("babai ka");

      // функция принимает числовое значение. Умножить N количество первых простых чисел начиная с 1.
      // std::cout << numPrimorialMultiple(3);

      // дан массив чисел. вернуть пары чисел, которые при вычитании дадут число 2.
      // std::vector<std::pair<int, int>> temp = twos_difference_pair({4,1,2,3});
      // for(auto i : temp)
      //       std::cout << i.first << "  " << i.second << std::endl;

      // даны 2 вектора. узнать являются ли числа одного вектора квадратами чисел другого вектора
      // std::vector<int> a = {121, 144, 19, 161, 19, 144, 19, 11};
      // std::vector<int> b = {14641, 20736, 361, 25921, 361, 20736, 361, 121};
      // std::cout << compareQuad(b,a);

      // вернуть вектор с символами, убрав множественные повторения.
      // std::vector<char> temp = uniqueInStroka("ZZAAAABBBEECCDAABBB");
      // for(auto i : temp)
      //       std::cout << i;

      // быстрое решение трибоначи (фибоначи из 3).
      // std::vector<int> res = fastTribonacci({1,1,1},10);  // 1 1 1 3 5 9 17 31 57 105
      // for(auto i : res)
      //       std::cout << i << " ";

      // число в двоичную сс, а потом посчитать количество единиц.
      // std::cout << countBits(1234);  // 1234 = 10011010010 = 5 единиц

      // есть вектор чисел. найти сумму последовательности, которая даст максимальную сумму.
            // можно сделать решение в 1 форе. также записывать во временную переменную сумму, если она больше чем была
            //а если сумма в минусе то обнулять и начинать с этого элемента.
      //std::cout << maxSequence({-2, 1, -3, 4, -1, 2, 1, -5, 4});

      // убрать одинаковые символы подряд
      // std::vector<std::string> temp = dup({"ccooddddddewwwaaaaarrrrsssss","piccaninny","hubbubbubboo"});
      // for(auto i : temp)
      //       std::cout << i << "  ";

      // удалить одинаковые элементы со всего вектора, но оставить порядок.  ( 5 1 3 9 6 8 4 7 2 0 )
      // std::vector<int> temp = duplicationDelete({5,1,3,5,1,9,3,6,8,3,4,7,3,1,2,8,0,3,4,5,7,1,2});
      // for(auto i : temp)
      //       std::cout << i << "  ";

      // merge sort.
      // int mass[21]{0,7,3,6,3,7,3,9,4,7,1,8,3,5,1,7,8,4,3,0,4};
      // mergeSortMain(mass,std::size(mass));
      // for(auto i : mass)
      //       std::cout << i << " ";

      // число перевести в ip4 адрес.
      // std::cout << uint32_to_ip(2154959208); // 128.114.17.104

      // найти сумму длинн интервалов. интервалы могут пересекаться
      // std::cout << sum_intervals({{1, 5}});

      // сумма самого маленького и самого большого числа в векторе
      // std::cout << sum_min_max({3,6,8,3,6,8,4,2,11});

      // даны 2 массива с 3 элементами каждый. перемножить 3 элемента между собой, и найти разницу 2 массивов.
      std::cout << findDifferenceCuboid({3, 2, 5},{1,4,4});
};

int findDifferenceCuboid(std::array<int, 3> a, std::array<int, 3> b)
{
      int sum1 = 1;
      int sum2 = 1;
      for(auto i : a)
            sum1 *= i;
      for(auto i : b)
            sum2 *= i;

      return sum1 > sum2 ? sum1 - sum2 : sum2 - sum1;
}

int sum_min_max(std::vector<int> input)
{
      auto pair = std::minmax_element(input.begin(), input.end());
      int summ = *pair.first + *pair.second;
      return summ;
}

int sum_intervals(std::vector<std::pair<int, int>> intervals) 
{
      int summ = 0;
  
      for(auto &i : intervals)
      {
            for(auto &j : intervals)
            {
                  bool delChecker = false;
                  // если интервалы пересекаются, и второе число больше чем было
                  if(i.first >= j.first && i.first <= j.second && i.second > j.second)
                  {
                        j.second = i.second;
                        delChecker = true;
                  }
                  // если интервалы пересекаются, и первое число меньше чем было
                  if(i.second >= j.first && i.second <= j.second && i.first < j.first)
                  {
                        j.first = i.first;
                        delChecker = true;
                  }

                  // если интервалы пересекаются, и интервалы равны, или один интервал в другом
                  if(j.first >= i.first && j.second <= i.second && (i.first != j.first && i.second != j.second))
                  {
                        j.first = 0;
                        j.second = 0;
                  }

                  // удаление интервалов которые попали в критерии
                  if(delChecker == true)
                  {
                        i.first = 0;
                        i.second = 0;
                  }
            }
      }
      
      // сумма интервалов
      for (auto i : intervals)
      {
            summ += i.second - i.first;
      }
      
      return summ;
}

std::string uint32_to_ip(uint32_t ip)
{
      std::string result {};

      uint32_t maxer[4] = {1, 256, 256*256, 256*256*256};
      int mass[4] = {0,0,0,0};

      for (int i = 3; i >= 0; i--)
      {
            if(ip >= maxer[i])
            {
                  mass[i] = ip / maxer[i];
                  ip = ip % maxer[i];
            }
      }
      
      result = std::to_string(mass[3]) + "." + std::to_string(mass[2]) + "." + std::to_string(mass[1]) + "." + std::to_string(mass[0]);

      return result;
}

void mergeSortMain(int *massiv, int lenght)
{
      // разделяем главный массив на 2 части.
      int len1 = lenght / 2;
      int len2 = lenght - len1;
      int mass1[len1];
      int mass2[len2];

      // в массиве перебираем главный массив, и делим элементы на 1 и 2 массив.
      for (size_t i = 0; i < lenght; i++)
      {
            if(i < len1)
                  mass1[i] = massiv[i];
            else
                  mass2[i - len1] = massiv[i];
      }

      // сортируем части массива
      mergeSorted(mass1, len1);
      mergeSorted(mass2, len2);

      // складываем массивы.
      mergeMassive(massiv, mass1, len1, mass2, len2);
      
}
void mergeSorted(int *massiv, int len)
{
      // внутри медж сорта, используем бабл сорт.
      for (size_t i = 0; i < len; i++)
      {
           for (size_t j = 0; j < len; j++)
           {
                  if(massiv[i] < massiv[j])
                        std::swap(massiv[i],massiv[j]);
           }
      }
}
void mergeMassive(int *main, int *first, int len1, int *second, int len2)
{
      // создаем итераторы по 2 массивам
      int summator1 = 0;
      int summator2 = 0;
      int maxIteration = len1 + len2;

      // проходимся по главному массиву
      for (size_t i = 0; i < maxIteration; i++)
      {
            // если второй элемент меньше первого, или первые элементы закончились
            if(first[summator1] > second[summator2] || summator1 == len1)
            {
                  // добавляем второй элемент в главный массив, и берем следующий второй элемент
                  main[i] = second[summator2];
                  summator2 ++;
            }
            else
            {     // иначе идем и добавляем первый элемент
                  main[i] = first[summator1];
                  summator1 ++;
            }            
      }
      
      
}


std::vector<int> duplicationDelete(std::vector<int> input)
{
      std::vector<int> result;
      std::set<int> temp;

      for(auto i : input)
      {
            auto boolTemp = temp.insert(i);
            if(boolTemp.second == true)
            {
                  result.push_back(i);
            }
      }

      return result;
}

std::vector<std::string> dup(std::vector<std::string> arr)
{
      std::vector<std::string> result;
      for(auto &item : arr)
      {     
            for (int i = 1; i < item.length(); i++)
            {
                  if(item[i] == item[i - 1])
                  {
                        item.erase(item.begin() + i);
                        i --;
                  }
            }
            
            result.push_back(item);
      }
      return result;

      // for (auto& s : arr)
      // {
            // unique откидывает в !конец одинаковые буквы, а через ерейс удаляем начиная с этого !конца
            //s.erase(std::unique(s.begin(), s.end()),s.end());
      //}
      //return arr;
}

int maxSequence(const std::vector<int>& arr)
{     
      // самое простое решение в лоб. O(2)
      int result = 0;
      // начиная с какого элемента идет перебор
      for (size_t i = 0; i < arr.size(); i++)
      {     
            int sum = 0;
            int tempSum = 0;
            // перебирает последовательность с N элемента
            for (size_t j = i; j < arr.size(); j++)
            {    
                  // записывает во временную переменную, если сумма больше чем была
                  if(tempSum < sum)
                        tempSum = sum;
                  sum += arr[j];
            }

            // проверка на локальный максимум, больше ли он чем глобальный максимум?
            int localMax = std::max(sum,tempSum);
            if(result < localMax)
                  result = localMax;
      }

      return result;     
}

unsigned int countBits(unsigned long long n)
{
      std::string dInt {};

      // если число делится нацело, то 0, иначе 1
      while(n > 0)
      {
            if(n % 2 == 0)
                  dInt += "0";
            else
                  dInt += "1";
            
            n = n / 2;
      }
      std::reverse(dInt.begin(), dInt.end());   // можно не реверсить. просто для правильного отображения в 2 сс.
      auto temp = std::count(dInt.begin(), dInt.end(), '1');
      return temp;
}

std::vector<int> fastTribonacci(std::vector<int> signature, int n)
{
      // проверка некорректного ввода
      if(signature.size() < 3)
      {
            return signature;
      } 
      // если n меньше 4, то обрезаем вектор до n элементов.
      if(n < 4)
      {
            signature.resize(n);
            return signature;
      }

      // к переменным обращение быстрее чем к вектору по [i].
      // ещё более лучше сделать массив из n элементов, т.к. к массиву обращение к любому элементу тоже n(1).
      int first = signature[0];
      int second = signature[1];
      int third = signature[2];

      // каждую итерацию складываем переменные, переприсваиваем, и пушим в вектора за O(1).
      while(signature.size() < n)
      {
            int temp = first + second + third;
            first = second;
            second = third;
            third = temp;

            signature.push_back(temp);
      }

      return signature;
}

std::vector<char> uniqueInStroka(const std::string& iterable)
{
      std::vector<char> result;

      for(auto i : iterable)
      {
            if(result.empty() || result.back() != i)
                  result.push_back(i);
      }

      return result;
}

bool compareQuad(std::vector<int>&a, std::vector<int>&b)
{      
      for(auto &i : a)
            i = i * i;

      std::sort(a.begin(),a.end());
      std::sort(b.begin(),b.end());
      
      if(a == b)
            return true;
      else
            return false;
}

std::vector<std::pair<int, int>> twos_difference_pair(const std::vector<int> &vec)
{
      std::vector<int> input = vec;
      std::vector<std::pair<int, int>> result;

      // сортировка вектора
      std::sort(input.begin(), input.end());

      for (size_t i = 0; i < input.size(); i++)
      {     
            for (size_t j = i + 1; j < input.size(); j++)
            {
                  // разница между двумя числами.
                  int diff = input[j] - input[i];
                  //если разница 2, то добавляем пару в результат.
                  if(diff == 2)
                  {
                        result.push_back({input[i],input[j]});
                        break;
                  }
                  // если разница между числами больше 2, то сразу пропускаем, т.к. массив отсортирован и дальше разница будет ещё больше.
                  if(diff > 2)
                  {
                        break;
                  }
            }
      }
      
      return result;
}

unsigned long long numPrimorialMultiple (unsigned short int number)
{
      // начальный значения
      unsigned long long result = 2; 
      int counter = 1;
      int curNumber = 2;

      // проверка если пришел 0 или минус.
      if(number < 1)
            return 0;

      // в цикле проверка, чтобы умножилось N простых чисел.
      while(counter < number)
      {
            curNumber ++;

            // если это число простое, то умножается, иначе просто идет на следующий круг
            if(primalCheckMultiple(curNumber))
            {
                  result *= curNumber;
                  counter ++;
            }

      }
      
      return result;
}

// проверка на простое число
bool primalCheckMultiple(unsigned long long numPrimor)
{
      // по стандарту число простое.
      bool result = true;
      // цикл начинается с 2, потомучто на 1 делится любое положительное число. и до корня пришедшего числа.
      for (size_t i = 2; i <= std::sqrt(numPrimor); i++)
      {
            // если наше число делится на i без остатка, то оно не простое. говорим фолс и выкидываем.
            if(numPrimor % i == 0)
            {
                  result = false;
                  break;
            }
      }
      return result;
}

std::string alphabet_position_print(const std::string &text)
{
      std::string result {};
      std::map<char,int> dict;
      dict['a'] = 1; dict['b'] = 2; dict['c'] = 3; dict['d'] = 4; dict['e'] = 5; dict['f'] = 6; dict['g'] = 7; 
      dict['h'] = 8; dict['i'] = 9; dict['j'] = 10; dict['k'] = 11; dict['l'] = 12; dict['m'] = 13; dict['n'] = 14; 
      dict['o'] = 15; dict['p'] = 16; dict['q'] = 17; dict['r'] = 18; dict['s'] = 19; dict['t'] = 20; dict['u'] = 21; 
      dict['v'] = 22; dict['w'] = 23; dict['x'] = 24; dict['y'] = 25; dict['z'] = 26;

      for(auto i : text)
      {
            int temp = dict[std::tolower(i)];
            if(temp > 0)
            {
                  result += std::to_string(temp);
                  result += " ";
            }
      }

      if(result.empty() == false)
      {
            result.pop_back();
      }

      return result;
}

int sumPositiv(std::string text)
{
      std::stringstream sstream(text);
      std::vector<int> temp(std::istream_iterator<int>(sstream),{});
      auto summ = std::accumulate(temp.begin(),temp.end(),0,[](int x, int y){return x + (y > 0 ? y : 0);});
      return summ;
}

std::map<char, unsigned> countChars(const std::string& string) 
{
      std::map<char, unsigned> dictionary;
      for(auto i : string)
            dictionary[i] ++;

      return dictionary;
}

std::string vowelShiftText(std::string text, int n)
{
      std::string vowels {};

      // добавление всех гласных в строку
      for(auto i : text)
      {
            if(std::tolower(i) == 'i' || std::tolower(i) == 'a' || std::tolower(i) == 'o' || std::tolower(i) == 'e' || std::tolower(i) == 'u')
            vowels += i; 
      }

      // вычисление позиции с которой начниается последовательность гласных.
      int counter = vowels.length() - n;
      // вставка вместо старых гласных - новых.
      for (size_t i = 0; i < text.length(); i++)
      {
            char temp = text[i];
            if(std::tolower(temp) == 'i' || std::tolower(temp) == 'a' || std::tolower(temp) == 'o' || std::tolower(temp) == 'e' || std::tolower(temp) == 'u')
            {     
                  // вычисление позиций если ушло за пределы массива.
                  int len = vowels.length();
                  if(counter >= len)
                  {
                        counter = counter % vowels.length();
                  }
                  if(counter < 0)
                  {
                        counter = counter % vowels.length();
                        if(counter < 0)
                        counter = vowels.length() + counter;
                  }
                  
                  // старая гласная меняется на новую, по указанной позиции из строки.
                  text[i] = vowels[counter];
                  counter ++;
            }
      }     
      
      return text;
}

std::vector<int> deleteElements(std::vector<int> arr, int n)
{
      std::vector<int> temp;
      std::map<int,int> dictionary;

      for(auto i : arr)
      {
            dictionary[i] ++;

            if(dictionary[i] <= n)
            {
                  temp.push_back(i);
            }
      }

      return temp;
};

int findOdder(const std::vector<int>& numbers)
{
      std::map<int,int> dictionary;
      int result {};

      for(auto i : numbers)
      {
            dictionary[i] ++;
      }

      for(auto i : dictionary)
      {
            if(i.second % 2 == true)
            {
                  result = i.first;
                  break;
            }
      }
      
      return result;
}

std::string orderWeightStr(const std::string &strng)
{
      // проверка что пришла не пустота
      if(strng == "")
            return "";

      // строка в вектор
      std::stringstream temp(strng);
      std::vector<std::string> strVec(std::istream_iterator<std::string>(temp),{});

      // кастомная сортировка через лямбда функцию
      std::sort(strVec.begin(),strVec.end(), [](std::string x, std::string y)
      {
            // считаем сумму цифр у двух чисел
            int temp1 = 0;
            for(auto i : x)
                  temp1 += i - '0';
            int temp2 = 0;
            for(auto i : y)
                  temp2 += i - '0';
            
            // сравниваем суммы цифр для сортировки. если равны то сортируется по алфавитному порядку.
            if(temp1 == temp2)
            {
                  return x > y ? false : true;
            }
            if(temp1 > temp2)
                  return false;
            else
                  return true;
      });

      // сборк строки из вектора
      std::string result {};
      for(auto i : strVec)
            result += i + " ";
      result.pop_back();

      return result;
}

std::vector<int> sortOddEven(std::vector<int> input)
{
      std::vector<int> result;
      std::vector<int> odd;
      std::vector<int> even;

      // вставка только четных или нечетных чисел в нужные вектора
      std::copy_if(input.begin(), input.end(), std::back_inserter(odd),  [](int x){return x % 2 ? true : false;});
      std::copy_if(input.begin(), input.end(), std::back_inserter(even), [](int x){return x % 2 ? false : true;});

      // если нужна сортировка внутри мини векторов, то обычный сорт ODD и EVEN тут.
      
      // Добавление в итоговый вектор четных а потом нечетных чисел
      result.insert(result.end(),even.begin(),even.end());
      result.insert(result.end(),odd.begin(),odd.end());

      return result;
}

std::vector<int> sortArrayOdd(std::vector<int> array)
{
      // O(2 n)
      std::vector<int> oddVec;

      // добавляем в новый вектор все нечетные
      for(auto i : array)
      {
            if(i % 2)
            {
                  oddVec.push_back(i);
            }
      }
      
      // отсортировать нечетные числа в новом векторе
      std::sort(oddVec.begin(), oddVec.end());

      // нечетные числа в обычном векторе меняем на числа из нового вектора по одной штуке.
      int j = 0;
      for (size_t i = 0; i < array.size(); i++)
      {
            if(array[i] % 2)
            {
                  array[i] = oddVec[j];
                  j ++;
            }
      }
      
      return array;
}

int FindOutliers(std::vector<int> arr)
{
      // сравнивать числа от второго элемента по четности, и если все равны = значит первый элемент отличался, и пишем его
      // иначе сравниваем разные числа с самым первым
      int temp1 {};
      int temp2 {};

      // сравниваем два числа подряд, если одно из них четное а другое нет - записываем в переменную
      for (size_t i = 1; i < arr.size(); i++)
      {
            if( (arr[i - 1] % 2) != (arr[i] % 2) )
            {
                  temp1 = arr[i];
                  temp2 = arr[i - 1];
                  break;
            }
      }

      // если первое и последнее число в массиве по четности равны TEMP1, то значит TEMP2 отличается по четности, и вернуть его. иначе temp1
      if( (temp1 % 2) == (arr[0] % 2) == (arr[arr.size()] % 2) )
      {
            return temp2;
      }
      else
      {
            return temp1;
      }
}

std::string spinWords(const std::string &str)
{     
      // строку в вектор, разделяя пробелами
      std::stringstream temp(str);
      std::vector<std::string> vecStr(std::istream_iterator<std::string>(temp),{});

      // смотрим каждое слово, и если больше 4 символов то разворачиваем
      for (size_t i = 0; i < vecStr.size(); i++)
      {
            if(vecStr[i].length() > 4)
            {
                  std::reverse(vecStr[i].begin(),vecStr[i].end());
            }
      }

      // добавляем в строку каждое слово из вектора, и добавляем пробелы. в конце убираем лишний пробел.
      std::string result {};
      for(auto i : vecStr)
      {
            result += i + " ";
      }
      result.pop_back();

      return result;
}

bool small_enough(std::vector<int> arr, int limit)
{
      std::sort(arr.begin(),arr.end(),std::greater());

      if(arr[0] > limit)
            return false;
      else
            return true;
}

int adjacentElementsProduct(std::vector<int> inputArray) 
{
      int max = INT32_MIN;

      for (size_t i = 1; i < inputArray.size(); i++)
      {
            int temp = inputArray[i - 1] * inputArray[i];
            if(temp > max)
            {
                  max = temp;
            }
      }
      
      return max;
}

std::string is_sorted_and_how(std::vector<int> array)
{
      std::vector<int> asc = array;
      std::sort(asc.begin(), asc.end());

      std::vector<int> desc = array;
      std::sort(desc.begin(), desc.end(), std::greater());

      if(array == asc)
            return "yes, ascending";
      if(array == desc)
            return "yes, descending";

      return "no";
}

int get_sum(int a, int b)
{
      int sum = 0;
      int min, max;

      if(a >= b)  
      {
            min = b;
            max = a;
      }
      else
      {
            min = a;
            max = b; 
      }

      for (int i = min; i <= max; i++)
      {
            sum += i;
      }
      
      return sum;
}


// вывод суммы позиций последовательности
int solveStr(const std::string &s)
{
      int sum = 0;
      int sumMax = 0;

      // более быстрое решение, но не работает со спец символами (точка будет считаться -70 или типо того)
      // а делать условие на 20 согласных букв не очень круто, поэтому прошлое решение лучше
      for(auto i : s)
      {
           char curChar = std::tolower(i);

           if(curChar == 'i' || curChar == 'a' || curChar == 'e' || curChar == 'o' || curChar == 'u' || curChar == 'y')
           {
                  if(sum > sumMax)
                  {
                        sumMax = sum;
                  }
                  sum = 0;
           }
           else
           {
                  sum += curChar - 'a' + 1;
           }
      }

      return std::max(sum,sumMax);
}

std::string reverse_letter(const std::string &str)
{
      std::string temp = str;
      std::reverse(temp.begin(),temp.end());

      for (size_t i = 0; i < temp.length(); i++)
      {     
            // если буква то пропустить
            if(temp[i] >= 'a' && temp[i] <= 'z')
            {
                  continue;
            }
            // иначе удалить символ, и уменьшить итерацию на 1
            else
            {
                  temp.erase(temp.begin() + i);
                  i --;
            }
      }

      return temp;
}

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