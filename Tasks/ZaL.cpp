#include "zaL.h"
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

class deb
{
public:
      deb(){};
      int x;
};

void zaMainL()
{

      // являются ли элементы вектора 1, подэлементами вектора 2 (возведенные в степень).
      //std::vector<int> a = {121, 144, 19, 161, 19, 144, 19, 11};
      //std::vector<int> b = {14641, 20736, 361, 25921, 361, 20736, 361, 121};
      //std::cout << comp(a,b);

      // мяч бросается с крыши, отскакивает на высоту, сколько раз мяч увидят на Н этаже.
      //std::cout << bouncingBall(30, 0.66, 1.5);

      // передвинуть нули в конец вектора.
      //std::vector<int> input = {1, 2, 1, 1, 3, 1, 0, 0, 0, 0};
      //std::vector<int> output = move_zeroes(input);
      //for(auto i : output)
      //      std::cout << i;

      // мексиканская волна. Заглавная буква в слове будет смещаться в право
      //std::vector<std::string> output = wave("hello");
      //for(auto i : output)
      //      std::cout << i << " ";


      // если умножение двух подряд идущих чисел фибоначи дают это число, то вернуть 2 эти числа и тру, иначе фолс.
      // для сокращения кода можно убрать внутренний вектор и return {first,second,1} , а в while проверять First * Second, и убрать CurMax.
      //std::vector<unsigned long long> output = productFib(714);
      //for(auto i : output)
      //      std::cout << i << " ";
      

      // ROT13 шифр. вроде переставляет буквы на 13 вперед.
      // можно индексы 64 91 96 123 поменять на a A z Z
      //std::cout << rot13("EBG13 rknzcyr.");

      // все числа от 1 до 2 числа, состоят из цифр   2 3 5 7  и не являются простыми.
      //std::vector<unsigned> outer;
      //outer = not_primes(2,  222);
      //for(auto i : outer)
      //      std::cout << i << " ";


      // разделить строку на вектор с элементами по 2 символа.
      //std::vector<std::string> outer = solution("abc");
      //for(auto i : outer)
      //      std::cout << i << " ";


      // MERGE sort и BUBBLE sort
      // auto start = std::chrono::steady_clock::now();
            
      //       int mass[22]{4,2,6,1,7,15,9,14,6,12,11,3,67,12,87,34,6,1,5,1,2,4};
      //       int massSize = std::size(mass);

      //       // сравнение пузырьковой и мердж сортировки.  при 20 элементах скорость равная.
      //       //testBubbleSort(mass,massSize);     // быстрее если меньше 20 элементов.  1800ns при 22
      //       testMergeSort(mass,massSize);      // быстрее если больше 20 элементов.  1700ns при 22

      // auto end = std::chrono::steady_clock::now();
      // std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

      //       // вывод элементов не учитывается, т.к. input/output занимает много времени.
      //       std::cout << std::endl;
      //       for(auto i : mass)
      //             std::cout << i << " ";
            

      // получить максимальный и минимальный элемент
      std::cout << highAndLow("8 3 -5 42 -1 0 0 -9 4 7 4 -4");

};

std::string highAndLow(const std::string& numbers)
{
      std::vector<std::string> inputs;     
      std::vector<int> output;   
      std::istringstream iss(numbers);
      std::copy(std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>(), std::back_inserter(inputs));

      for(auto i : inputs)
            output.push_back(std::stoi(i));

      std::sort(output.begin(),output.end());

      std::string result {};
      result += std::to_string(output[output.size() - 1]);
      result += " " + std::to_string(output[0]);

      return result;
}

// пузырьковая сортировка
void testBubbleSort(int input[], int sizeMass)
{
      for (size_t i = 0; i < sizeMass; i++)
      for (size_t j = 0; j < sizeMass; j++)
      {
            if(input[i] < input[j])
            {
                  int temp = input[i];
                  input[i] = input[j];
                  input[j] = temp;
            }
      }
}

// сортировка слиянием
void testMergeSort(int input[], int sizeMass)
{
      // определение длинны двух подМассивов. (чет/нечет число элементов)
      int sizeOne = sizeMass / 2;
      int sizeTwo {};
      if(sizeMass % 2)
            sizeTwo = (sizeMass / 2) + 1;
      else
            sizeTwo = sizeMass / 2;

      int massChapOne[sizeOne] {};
      int massChapTwo[sizeTwo] {};

      // вставка элементов из общего массива в подмассивы
      int counter = 0;
      for (size_t i = 0; i < sizeMass; i++)
      {    
            if(i == sizeMass / 2)
                  counter = 0;

            if(i >= sizeMass / 2)
                  massChapTwo[counter] = input[i];
            else
                  massChapOne[counter] = input[i];

            counter ++;
      }

      // пузырьковая сортировка подмассивов
      testBubbleSort(massChapOne,sizeOne);
      testBubbleSort(massChapTwo,sizeTwo);

      // собираем обратно в общий массив. сравниваем числа в обоих массивах и вставляем меньшее
      // затем прибавляем итератор у массива, из которого выбрали число и сравниваем дальше
      int firstIterator = 0;
      int secondIterator = 0;
      for (size_t i = 0; i < sizeMass; i++)
      {     
            if( (massChapOne[firstIterator] <= massChapTwo[secondIterator] && firstIterator < sizeOne) || secondIterator == sizeTwo)
            {
                  input[i] = massChapOne[firstIterator];
                  firstIterator ++;
            }
            else
            {
                 input[i] = massChapTwo[secondIterator]; 
                 secondIterator ++;
            }
                  
      }

}

std::vector<std::string> solution(const std::string &s)
{
      std::vector<std::string> result;

      int iterator = 0;
      std::string tempStroka = "";

      for (size_t i = 0; i < s.length(); i++)
      {
            iterator ++;
            tempStroka += s[i];
            if(iterator == 2)
            {
                  result.push_back(tempStroka);
                  tempStroka = "";
                  iterator = 0;
            }
      }
      
      if(iterator == 1)
      {
            tempStroka += '_';
            result.push_back(tempStroka);
      }

      return result;
}


// проверка что число состоит из 2 3 5 7
bool checkDigits(unsigned x)
{
      bool checker = true;

      std::string temp = std::to_string(x);
      for(auto i : temp)
      {     
            // если попалось ни одно из этих чисел то выкинуть
            if(i != '2' && i != '3' && i != '5' && i != '7')
            {
                  checker = false;
                  break;
            }
      }

      return checker;
}

// проверка что число НЕ простое
bool checkPrimal(unsigned x)
{
      bool checker = false;

      if(x == 25)
      std::cout << "this 22  ";

      for (size_t i = 2; i <= sqrt(x); i++)
      {     
            // если попадает, то число не простое
            if(x % i == 0)
            {
                  checker = true;
                  break;
            }
                  
      }
      
      return checker;
}

std::vector<unsigned> not_primes(unsigned a, unsigned b)
{
      std::vector<unsigned> result;

      while(a < b)
      {
            bool checkers = false;

            // сначала проверка что число состоит из 2 3 5 7
            checkers = checkDigits(a);
            if(checkers == false)
            {
                  a++;
                  continue;
            }
                  
            // потом проверка что число не простое
            checkers = checkPrimal(a);
            if(checkers == false)
            {
                  a++;
                  continue;
            }
                  
            // если все условия выполняются то добавление в массив
            result.push_back(a);
            a++;
      }

      return result;
}

std::string rot13(const std::string& str)
{     
      std::string out = str;

      for (size_t i = 0; i < str.length(); i++)
      {
            int index = str[i];
            
            // большие английские
            if(index > 64 && index < 91)
            {
                  index +=  13;
                  index = index % 91;
                  if(index < 65)
                        index += 65;
            }
            // маленькие английские
            if(index > 96 && index < 123)
            {
                  index +=  13;
                  index = index % 123;
                  if(index < 97)
                        index += 97;
            }

            out[i] = index;
      }

      return out;
}

typedef unsigned long long BigLong;
std::vector<BigLong> productFib(BigLong prod)
{
      std::vector<BigLong> exitVec {};

      BigLong First = 0;
      BigLong Second = 1;
      BigLong Temp {};
      BigLong CurMax {};
      

      while(CurMax < prod)
      {
            Temp = First + Second;
            First = Second;
            Second = Temp;
            CurMax = First * Second;
      }

      exitVec.push_back(First);
      exitVec.push_back(Second);

      if(CurMax == prod)
             exitVec.push_back(1);
      else
             exitVec.push_back(0);

      return  exitVec;
}

std::vector<std::string> wave(std::string y)
{
      std::vector<std::string> result {};

      if(y.empty())
            return result;

      for (size_t i = 0; i < y.length(); i++)
      {
            if(y[i] != ' ')
            {
                  y[i] = std::toupper(y[i]);
                  result.push_back(y);
                  y[i] = std::tolower(y[i]);
            }
      }
      
      return result;
}

std::vector<int> move_zeroes(const std::vector<int>& input) 
{
      std::vector<int> output {};
      int zeroCount {};

      // перенос в новый вектор всех чисел
      for(auto i : input)
      {
            if(i == 0)
                  zeroCount ++;
            else
                  output.push_back(i);      
      }

      // в конце добавление нулей
      for (size_t i = 0; i < zeroCount; i++)
      {
            output.push_back(0);
      }

      return output;
}

int bouncingBall(double h, double bounce, double window)
{     
      // проверка некорректных введеных данных
      if(h <= 0 || bounce >= 1 || bounce <= 0 || window >= h)
            return -1;
      
      int result = {};

      // мяч пролетает из окна в одну и вдругую сторону
      while (h > window)
      {
            h = h * bounce;
            result += 2;
      }
      result --;

      return result;
};


bool comp(std::vector<int>&a, std::vector<int>&b)
{
      bool checker[b.size()] {};
      bool result = true;

      std::vector<int> temp1 = a;
      std::vector<int> temp2 = b;

      for (size_t i = 0; i < temp2.size(); i++)
      {
            for (size_t j = 0; j < temp1.size(); j++)
            {
                  if(temp1[j] * temp1[j] == temp2[i])
                  {
                        temp1.erase(temp1.begin() + j);
                        temp2.erase(temp2.begin() + i);
                        checker[i] = true;
                        i --;
                        j --;
                        break;
                  }
            }

      }

      if(temp1.empty())
            return true;
      else 
            return false;

};
