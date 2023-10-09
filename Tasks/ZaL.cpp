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
#include <bitset>

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
      //std::cout << highAndLow("8 3 -5 42 -1 0 0 -9 4 7 4 -4");

      // получить двоичную форму суммы чисел
      //std::cout << add_binary(2, 2);

      // сколько нужно лет чтобы население страны выросло до Н количества
      //std::cout << nbYear(1500, 5, 100, 5000);

      // умножение N количества простых чисел подряд, от 2
      //std::cout << numPrimorial(5);

      // вывод последовательности из букв. accum(abcq) = A-Bb-Ccc-Qqqq
      //std::cout << accum("abcd");

      // создать строку в виде номера телефона
      //int mass[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
      //std::cout << createPhoneNumber(mass);

      // вывести тру если человек вернется на свое место ровно через 10 минут.
      //std::cout << isValidWalk({'e','w','e','w','n','s','n','s','e','w'});

      // возврат обатного числа
      //std::cout << opposite(-5);

      // сумма квадратов каждой цифры в числе.
      //std::cout << square_digits(3212);

      // суммировать цифры в числе, вычесть сумму и получить строку из справочника.
      //std::cout << SubtractSum(10);

      // тру если последовательность букв в алфавитном порядке, и встречаются всего 1 раз.
            // легче было просто отсортить входную строку, и если следующий элемент равен предыдущему + 1 то все хорошо
      //std::cout << solve("abd");
      std::cout << solve("dabc");
      //std::cout << solve("abccd");
};

bool solve(std::string s)
{
      if(s.length() < 2)
            return true;

      int AlphLen = 26;
      int mass[AlphLen] {};  // Для подсчета количества букв
      bool countLetter = true; // для проверки что количество букв 1

      //bool orderCheck = true;  // проверка порядка
      // mass[s[0] - 'a'] = 1;   // добавить +1 к первой букве в строке.
      // проверка порядка
      // for (size_t i = 1; i < s.length(); i++)
      // {
      //       char curLetter = s[i];
      //       char prevLetter = s[i-1];

      //       mass[curLetter - 'a'] ++;     //добавление 1 к колву букв

      //       // если текущая буква минус 1 не равна прошлой букве то фолс
      //       if(curLetter - 1 != prevLetter)
      //       {
      //             orderCheck = false;
      //             break;
      //       }
      // }

      // добавление в массив количество букв
      for (size_t i = 0; i < s.length(); i++)
      {
            mass[s[i] - 'a'] ++;     //добавление 1 к колву букв
      }

      bool orderCheck = false;  // проверка порядка
      bool localOrderCheck = false; // проверка что уже была последовательность
      // буквы могут быть в любом порядке, главное чтобы можно было составить алфавитную последовательность
      for (size_t i = 0; i < AlphLen; i++)
      {     
            // проверка количества элементов
            if(mass[i] > 1)
            {
                  countLetter = false;
            }

            // проверка последовательности
            if(orderCheck == false)
            {
                  if(mass[i] == 1)
                  {
                        orderCheck = true;
                  }
            }
            else
            {
                  // если уже была последовательность, и после нулей снова единицы
                  if(localOrderCheck == true && mass[i] == 1)
                  {
                        orderCheck = false;
                        break;
                  }
                  // последовательность закончилась
                  if(mass[i] == 0)
                  {
                        localOrderCheck = true;
                  }     
            }

      }
      
      if(orderCheck == true && countLetter == true)
            return true;
      else
            return false;
      
}

std::string SubtractSum(int n)
{     
      // проверка условий
      if(n < 10 || n > 9999)
            return "";

      // получение суммы цифры в числе
      int dictionaryDigit = n;
      std::string stroka = std::to_string(n);

      // по кругу уменьшение значения, пока не станет меньше 100
      do
      {
            int sumInt = 0;
            for (size_t i = 0; i < stroka.length(); i++)
            {
                  sumInt += stroka[i] - '0';
            }
            dictionaryDigit = dictionaryDigit - sumInt;
      }
      while (dictionaryDigit > 100);

      dictionaryDigit --;
      std::vector<std::string> fruits {
      "kiwi", "pear", "kiwi", "banana", "melon", "banana", "melon", "pineapple", "apple", "pineapple",
      "cucumber", "pineapple", "cucumber", "orange", "grape", "orange", "grape", "apple", "grape", "cherry",
      "pear", "cherry", "pear", "kiwi", "banana", "kiwi", "apple", "melon", "banana", "melon",
      "pineapple", "melon", "pineapple", "cucumber", "orange", "apple", "orange", "grape", "orange", "grape",
      "cherry", "pear", "cherry", "pear", "apple", "pear", "kiwi", "banana", "kiwi", "banana",
      "melon", "pineapple", "melon", "apple", "cucumber", "pineapple", "cucumber", "orange", "cucumber", "orange",
      "grape", "cherry", "apple", "cherry", "pear", "cherry", "pear", "kiwi", "pear", "kiwi",
      "banana", "apple", "banana", "melon", "pineapple", "melon", "pineapple", "cucumber", "pineapple", "cucumber",
      "apple", "grape", "orange", "grape", "cherry", "grape", "cherry", "pear", "cherry", "apple",
      "kiwi", "banana", "kiwi", "banana", "melon", "banana", "melon", "pineapple", "apple", "pineapple"
      };

      std::string result = fruits[dictionaryDigit];
      return result;
}

int square_digits(int num)
{
      std::string input = std::to_string(num);
      std::string result {};

      for (size_t i = 0; i < input.length(); i++)
      {
            // перевод одного символа в цифру
            int temp = input[i] - '0';
            // квадрат цифры записываем строкой
            result += std::to_string(temp * temp);
      }
      
      // возврат результата числом, а не строкой
      return std::stoi(result);
}

int opposite(int number) 
{
  return - number;
}

bool isValidWalk(std::vector<char> walk) 
{
      // позиция и время
      int pos_x = 0;
      int pos_y = 0;
      int time = 0;

      // каждую итерацию человек движется на 1, и проходит 1 минута
      for(auto i : walk)
      {
            if(i == 'n')
                  pos_x ++;
            if(i == 's')
                  pos_x --;
            if(i == 'w')
                  pos_y --;
            if(i == 'e')
                  pos_y ++;

            time ++;
      }

      // если прошло 10 минут и человек в начальной позиции
      if(time == 10 && pos_x == 0 && pos_y == 0)
            return true;
      else
            return false;
}

std::string createPhoneNumber(const int arr [10])
{

      std::string input {};
      for (size_t i = 0; i < 10; i++)
      {
            input += std::to_string(arr[i]);
      }

      std::regex vowels("(...)(...)(....)");

      return std::regex_replace(input, vowels, "($1) $2-$3");

}

std::string accum(const std::string &s)
{
      std::string result {};

      // перебор каждого символа с троке
      int iterator = 1;
      for (size_t i = 0; i < s.length(); i++)
      {     
            // каждый символ добавляется iterator раз
            for (size_t j = 0; j < iterator; j++)
            {
                  if(j == 0)
                        result += std::toupper(s[i]);
                  else
                        result += std::tolower(s[i]);
            }

            // если не последний, то печатать тире
            if(i + 1 != s.length())
                  result += '-';

            // увеличивать iterator после добавления символа.
            iterator ++;
      }
      
      return result;
}

unsigned long long numPrimorial (unsigned short int number )
{     
      // массив первых 20 простых чисел
      int mass[20] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71};
      unsigned long long sum = mass[0];

      // умножение простых чисел по очереди
      for (size_t i = 1; i < number; i++)
      {
            sum = sum * mass[i];
      }
      
      return sum;
}

// население, процент роста в год, приезжее население , сколько нужно населения
int nbYear(int p0, double percent, int aug, int p)
{
      int needYears = 0;
      percent = percent / 100;

      while(p0 < p)
      {     
            p0 += p0 * percent;
            p0 += aug;
            needYears ++;
      }

      return needYears;
}

std::string add_binary(uint64_t a, uint64_t b) {

      uint64_t summy = a + b;
      std::string res = std::bitset<16>(summy).to_string();
      std::string finalResult {};

      bool checker = false;
      for(auto i : res)
      {     
            if(checker == true)
                  finalResult += i;
            else
            {
                  if(i == '1')
                  {
                        checker = true;
                        finalResult += i;
                  }
            }
      }

      return finalResult;
}

std::string highAndLow(const std::string& numbers)
{
      std::vector<std::string> inputs;     
      std::vector<int> output;   
      std::istringstream iss(numbers);
      // сразу в инт будет эффективнее чем в стриг а потом в инт.
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
