#include "LC1.h"

void leet1()
{

    // переставить числа в порядке, на которые указывают значения
    // std::vector<int> temp = buildArrayPermutation({0,2,1,5,3,4});
    // for(auto i : temp)
    //     std::cout << i << " ";

    // дан вектор значений, это изменение значения от 0. найти максимальное значение которое было.
    // std::cout << largestAltitudeGet({-5,1,5,0,-7});

    // отразить матрицу по горизонтали
    // std::vector<std::vector<int>> inpput = {{1,1,0},{1,0,1},{0,0,0}};
    // std::vector<std::vector<int>> temp = flipAndInvertImage(inpput);
    // for(auto i : temp)
    // {
    //     for(auto j : i)
    //         std::cout << j << " ";
    //     std::cout << std::endl;
    // }

    // найти сколько индексов совпадает у первого массива и сколько совпадает у второго массива
    // std::vector<int> temp = findIntersectionValues({4,3,2,3,1},{2,2,5,2,3,6});
    // for(auto i : temp)
    //     std::cout << i << " ";

    // найти первый полиндром в векторе
    //std::string temp = firstPalindrome("eget","ada","cool");
    // std::cout << temp;

    // найти сумму уникальных значений
    // int sum = sumOfUniqueElem({1,2,3,4,5,5});
    // std::cout << sum;

    // найти за O(n) единственное уникальное число в массиве, остальные встречаются 2 раза.
    // std::cout << singleNumberInVec({2,2,1});

    // дан вектор чисел от 0 До N в разном порядке. найти 1 недостоющее число.
    //std::cout << missingNumber({3,0,1});

    // найти минимальное стартовое значение (от 1) чтобы при сложении со всеми элементами, число не опускалось ниже 1.
    //std::cout << minStartValue({-3,2,-3,4,2});  // 5 - 3 = 2;  2 + 2 = 4; 4 - 3 = 1; ответ 5

    // найти самый первый "средний" индекс в векторе, чтобы все значения слева и справа от него были равны
    //std::cout << findMiddleIndex({2,3,-1, 8,4});  // за О(2n).  средний индекс 3 с числом 8.     2 + 3 - 1  ==  4.  

    // есть вектор чисел. найти число которое появляется больше всего раз. это число занимает как минимум половину вектора.
    //std::cout << majorityElement({2,2,1,1,1,2,2});  // работает только если одинаковых чиел больше чем половина вектора.

    // есть массив чисел. вернуть разницу между суммой чисел и суммой цифр
    // std::cout << differenceOfSum({1,15,6,3});

    // убрать последние нули из строки.
    // std::cout << removeTrailingZeros("35457008900");

    // составить строку длинной N, из букв, которые встречаются нечетное количество раз
    // std::cout << generateTheString(5);

    // в массиве содержатся двоичные строки. вернуть недостающую строку.  {000,001,011,100,101,111}  вернуть 010 или 110
    // std::cout << findDifferentBinaryString({"00","01","10"});

    // дана строка с символами и числами. заменить числа на буквы.
    // std::cout << replaceDigits("a1c1e1");  // a1c1e1  =  abcdef

    // сократить строку
    // std::cout << minimizedStringLength("abbc");

    // дан массив чисел. вернуть массив с произведением всех чисел, за исключением этого числа.
    // std::vector<int> temp = productExceptSelf({1,2,3,4});  //  -1,-1,0,-3,3  =  0,0,9,0,0
    // for(auto i : temp)
    // std::cout << i << " ";

    // разделить строку LLRLRLRL на равные подстроки RL. вернуть возможно количество равных подстрок
    //std::cout << balancedStringSplit("RLRRLLRLRL"); // RL RRLL RL RL

    // дано число из цифр 6 и 9.  изменить 1 цифру, чтобы получилось макисмально возможное число.
    // std::cout << maximum69Number(9669);

    // дано число. можно переназначить одно число на другое 1 раз. найти разницу между самым большим возможным числом, и самым маленьким
    //std::cout << minMaxDifference(11891); // 1 = 9; max = 99899; 1 = 0; min = 890;  99899 - 890 = 99009;

    // приходит строка чисел, и одна цифры. удалить одну такую цифру из строки, чтобы осталось максимальное значение
    //std::cout << removeDigit("123",'1');

    // дано число цифр, и сумма индексов. составить минимально возможное лексиграфическое слово.
    //std::cout << getSmallestString(5,73); // 3 цифры, с суммой индексов 28.  aby;

    // дан массив чисел (положительных и отрицательных). вернуть максимально возможное значение, которое можно получить путем перемножения (можно использовать не все).
    //std::cout << maxStrength({3,-1,-5,2,5,-9});  // перемножаем все числа кроме -1, так как оно даст отрицательное итоговое значение, а заменить его другим отрицательным уже не можем

    // есть двумерная карта с клетками, содержащими золото. нужно найти путь чтобы собрать максимальное количество золота, и не заходить на пустые клетки.
    //std::vector<std::vector<int>> temp = {{1,0,7},{2,0,6},{3,4,5},{0,3,0},{9,0,20}};  // == 28  
    std::vector<std::vector<int>> temp = { {0,1,6,20,0}, {0,0,3,0,0}, {16,9,16,8,0}, {14,0,4,20,9} };  // == 92
    std::cout << getMaximumGoldWhile(temp);    // лучший путь через 1 2 3 4 5 6 7 = 28, так как это больше чем 20, к которому нет проходу вообще

}   

// без рекурсии
int getMaximumGoldWhile(std::vector<std::vector<int>> &grid)
{
    int globalSum = 0;

    position globalPos;
    globalPos.x = 0;
    globalPos.y = 0;

    // проход по всем клеткам. пытаемся начать с каждой клетки
    while(globalPos.y < grid[globalPos.x].size())
    {
        int localSum = 0;       // локальная сумма для цикла в цикле
        int localMaxSum = 0;    // локальное хранилище максимальной суммы в данном цикле
        bool localEnd = false;
        position localPos;
        localPos.x = globalPos.x;
        localPos.y = globalPos.y;

        // создаем и заполняем карту нулями
        std::vector<std::vector<int>> mapp;
        mapp.resize(grid.size());
        for(int i = 0; i < grid.size(); i++)
        {
            mapp[i].resize(grid[i].size());
            std::fill(mapp[i].begin(),mapp[i].end(),0);
        }

        // пройдем по всему лабиринту, если текущяя клетка не нулевая
        if(grid[globalPos.x][globalPos.y] != 0)
        while (localEnd == false)
        {
            // если текущая клетка не пустая и мы ещё не были на этой клетке то получаем значение и ставим что уже были на этой клетке.
            if(grid[localPos.x][localPos.y] != 0 && mapp[localPos.x][localPos.y] == 0)
            {
                localSum += grid[localPos.x][localPos.y];
                mapp[localPos.x][localPos.y] = localSum;
            }

            // записываем максимальную сумму, если она больше чем была
            if(localSum > localMaxSum)
                localMaxSum = localSum;


            // ищем в какую сторону больше показывает
            bool cheker = false;
            int minValue = 0;
            int directionX = 0;
            int directionY = 0;

            // если есть влево то идти влево. конец итерации
            if(localPos.x - 1 >= 0 && mapp[localPos.x - 1][localPos.y] == 0 && grid[localPos.x - 1][localPos.y] != 0 && grid[localPos.x - 1][localPos.y] > minValue)
            {
                minValue = grid[localPos.x - 1][localPos.y];
                cheker = true;
                directionX = -1;
                directionY = 0;
            }
            // если есть назад то идти назад. конец итерации
            if(localPos.y - 1 >= 0 && mapp[localPos.x][localPos.y - 1] == 0 && grid[localPos.x][localPos.y - 1] != 0 && grid[localPos.x][localPos.y - 1] > minValue)
            {
                minValue = grid[localPos.x][localPos.y - 1];
                cheker = true;
                directionX = 0;
                directionY = -1;
            }
            // если есть вперед то идти вперед. конец итерации
            if(localPos.y + 1 < mapp[localPos.x].size() && mapp[localPos.x][localPos.y + 1] == 0 && grid[localPos.x][localPos.y + 1] != 0 && grid[localPos.x][localPos.y + 1] > minValue)
            {
                minValue = grid[localPos.x][localPos.y + 1];
                cheker = true;
                directionX = 0;
                directionY = 1;
            }
            // если есть вправо то идти вправо. конец итерации
            if(localPos.x + 1 < mapp.size() && mapp[localPos.x + 1][localPos.y] == 0 && grid[localPos.x + 1][localPos.y] != 0 && grid[localPos.x + 1][localPos.y] > minValue)
            {
                minValue = grid[localPos.x + 1][localPos.y];
                cheker = true;
                directionX = 1;
                directionY = 0;
            }
            if(cheker == true)
            {
                localPos.x += directionX;
                localPos.y += directionY;
                continue;
            }

            // если на старте, и нет проходов. то заканчиваем цикл
            if(localPos.x == globalPos.x && localPos.y == globalPos.y)
            {
                localEnd = true;
                continue;
            }

            // если некуда идти, то идти к глобал стартовой точке.
            minValue = INT32_MAX;
            directionX = 0;
            directionY = 0;

            if(localPos.y + 1 < mapp[localPos.x].size() && mapp[localPos.x][localPos.y + 1] < minValue && mapp[localPos.x][localPos.y + 1] != 0)
            {
                directionY = 1;
                directionX = 0;
                minValue = mapp[localPos.x][localPos.y + 1];
            }
            if(localPos.y - 1 >= 0 && mapp[localPos.x][localPos.y - 1] < minValue && mapp[localPos.x][localPos.y - 1] != 0)
            {
                directionY = -1;
                directionX = 0;
                minValue = mapp[localPos.x][localPos.y - 1];
            }
            if(localPos.x + 1 < mapp.size() && mapp[localPos.x + 1][localPos.y] < minValue && mapp[localPos.x + 1][localPos.y] != 0)
            {
                directionY = 0;
                directionX = 1;
                minValue = mapp[localPos.x + 1][localPos.y];
            }
            if(localPos.x - 1 >= 0 && mapp[localPos.x - 1][localPos.y] < minValue && mapp[localPos.x - 1][localPos.y] != 0)
            {
                directionY = 0;
                directionX = -1;
                minValue = mapp[localPos.x - 1][localPos.y];
            }

            // изменяем текущее положение и начинаем цикл заново
            localPos.x += directionX;
            localPos.y += directionY;

            if (grid[localPos.x][localPos.y] != 0 && mapp[localPos.x][localPos.y] != 0)
            {
                localSum = mapp[localPos.x][localPos.y];
            }

        }
        

        // если в цикле было найдена более большая сумма, то заменить
        if(localMaxSum > globalSum)
            globalSum = localMaxSum;

        // в конце увеличиваем счетчик по X и Y, тем самым меняем начальную точку
        globalPos.x ++;
        if(globalPos.x >= grid.size())
        {
            globalPos.x = 0;
            globalPos.y ++;
        }
    }
    
    return globalSum;
}



int goldRecur(int sum, std::vector<std::vector<int>> &grid, int posMain, int posSub)
{

      if(grid[posMain][posSub] == 0)
      return sum;

      sum += grid[posMain][posSub];
      grid[posMain][posSub] = 0;

      int max = 0;
      int temp = 0;
      bool lastDigit = true;
      
      if(grid[posMain].size() > posSub + 1 && grid[posMain][posSub + 1] != 0)
      {
        lastDigit = false;
        std::vector<std::vector<int>> tempGrid = grid;
        temp = goldRecur(sum, tempGrid, posMain, posSub + 1);

        if(temp > max)
        max = temp;
      }
      if(posSub - 1 >= 0 && grid[posMain][posSub - 1] != 0)
      {
        lastDigit = false;
        std::vector<std::vector<int>> tempGrid = grid;
        temp = goldRecur(sum, tempGrid, posMain, posSub - 1);

        if(temp > max)
        max = temp;
      }
      if(grid.size() > posMain + 1 && grid[posMain + 1][posSub] != 0)
      {
        lastDigit = false;
        std::vector<std::vector<int>> tempGrid = grid;
        temp = goldRecur(sum, tempGrid, posMain + 1, posSub);

        if(temp > max)
        max = temp;
      }
      if(posMain - 1 >= 0 && grid[posMain - 1][posSub] != 0)
      {
        lastDigit = false;
        std::vector<std::vector<int>> tempGrid = grid;
        temp = goldRecur(sum , tempGrid, posMain - 1, posSub);

        if(temp > max)
        max = temp;
      }

      if(lastDigit == true)
      {
        return sum;
      }

      return max;

}

int getMaximumGold(std::vector<std::vector<int>> &grid)
{
      int maximum = 0;
      int localMax = 0;

      // начало с каждого не нулевого элемента
      for(int i = 0; i < grid.size(); i++)
      {
            for(int j = 0; j < grid[i].size(); j++)
            {     
                  // если клетка не нулевая, то пытаться зайти в рекурсию
                  if(grid[i][j] != 0)
                  localMax = goldRecur(0,grid,i,j);

                  if(localMax > maximum)
                  maximum = localMax;
            }
      }

      return maximum;
}

long long maxStrength(std::vector<int> nums)
{
    // быстрое по времени решение!!!
    long sum = 1;
    long minElem = INT32_MIN;
    bool positive = false;
    bool negative = false;

    if(nums.size() == 1)
        return nums[0];

    // проход по вем положительным и отрицательным числам. нули пропускаем
    for(auto i : nums)
    {
        if(i > 0)
        {
            positive = true;
            sum *= i;
        }
            
        if(i < 0)
        {
            negative = true;
            if(i > minElem)
            minElem = i;

            sum *= i;
        }
    }

    // проверка если мы можем убрать одно отрицательное число и получится плюс. также проверка что не надо было умножать
    if(sum < 0)
    {
        if(sum == minElem && positive == false)
        return 0;
    
        sum = sum / minElem;
    }

    // проверка что были только нули
    if(negative == false && positive == false)
    return 0;
    
    return sum;
}




std::string getSmallestString(int n, int k)
{

    std::string result {};


        // пока оставшееся число цифр больше 0
        while(n > 0)
        {   
            // если индекс букв больше N числа. (26 букв + оставшееся количество чисел). то онимаем 26 и пишем Z
            if(k - 26 + 1 >= n)
            {
                result.push_back('a' + 26 - 1);
                n --;
                k -= 26;
            }
            else
            {
                // если индекс все ещё больше чем количество цифр, но меньше 26, то вычисляем конкретную букву, до сравнивания индеса
                if(k > n)
                {
                    result.push_back('a' + (k - n));
                    k -= (k - n);
                }
                // индекс и количество цифр одинаковы. пишем буквы А
                else
                {
                    result.push_back('a');
                }
                
                k--;
                n--;
            }
                

        }

    // инвертируем строку.
    std::reverse(result.begin(), result.end());

    return result;

    // std::string result {};

    // while(n > 0)
    // {

    //     if(k > n)
    //     {
    //         result.push_back('a' + std::min((k - n),25));
    //         k -= std::min((k - n),25);
    //     }
    //     else
    //     {
    //         result.push_back('a');
    //     }
        
    //     k--;
    //     n--;

    // }

    // std::reverse(result.begin(), result.end());

    // return result;
}

std::string removeDigit(std::string number, char digit)
{
        std::string temp {};

        for(int i = 0; i < number.length(); i++)
        {
            // сравниваем каждое вхождение
            if(number[i] == digit)
            {
                // получение строки без этого числа
                std::string peace = number.substr(0, i) + number.substr(i+1);
                // запись во временную переменную большего результата. 
                temp = std::max(peace,temp);
            }
        }

        return temp;
}

int minMaxDifference(int num) 
{   
    std::string temp = std::to_string(num);
    std::string min = std::to_string(num);
    std::string max = std::to_string(num);

    char minDigit = 'a';
    char maxDigit = 'a';
    for(int i = 0; i < temp.length(); i++)
    {
        if(minDigit == 'a' && temp[i] != '0')
        {
            minDigit = temp[i];
        }
        if(minDigit == min[i])
        {
            min[i] = '0';
        }

        if(maxDigit == 'a' && temp[i] != '9')
        {
            maxDigit = temp[i];
        }
        if(maxDigit == max[i])
        {
            max[i] = '9';
        }
    }

    return std::stoi(max) - std::stoi(min);

}

int maximum69Number (int num)
{
    std::string temp = std::to_string(num);

    for(auto &i : temp)
    {
        if(i == '6')
        {
            i = '9';
            break;
        }
    }

    return std::stoi(temp);
}

int balancedStringSplit(std::string s) 
{
    int Lcounter = 0;
    int Rcounter = 0;
    int res = 0;
    // можно создать одну переменную counter которая будет + или - при букве, и res++ если переменная 0

    for(auto i : s)
    {
        if(i == 'R')
        Rcounter ++;

        if(i == 'L')
        Lcounter ++;

        if(Lcounter == Rcounter && Lcounter != 0)
        res ++;    
    
    }

    return res;
}

std::vector<int> productExceptSelf(std::vector<int> nums)
{
    std::vector<int> temp;
    temp.reserve(nums.size());

    for(int i = 0; i < nums.size(); i++)
    {
        int summ = 1;

        for(int j = 0; j < nums.size(); j++)
        {
            if(i == j)
            continue;

            summ *= nums[j];
        }
        temp.push_back(summ);

    }

    return temp;

    
    // int n = nums.size();
    // vector<int> output(n);
    // output[0] = 1;

    // for(int i=1; i<n; i++)
    // {
    //     output[i] = output[i-1] * nums[i-1];
    // }

    // int right = 1;
    // for(int i=n-1; i>=0; i--)
    // {
    //     output[i] *= right;
    //     right *= nums[i];
    // }
    
    // return output;

}

int minimizedStringLength(std::string s)
{
    // std::map<char,int> maps;
    // for(auto i : s)
    // {
    //     maps[i] ++;
    // };
    // return maps.size();



    std::set<char> temp(s.begin(), s.end());
    return temp.size();
}

std::string replaceDigits(std::string s) 
{
    char globalTemp {};
    for(auto &i : s)
    {
        char temp = i - '0';
        if(temp >= 0 && temp <= 9)
        {
            i = globalTemp + temp;
        }

        globalTemp = i;
    }

    return s;
}

std::string findDifferentBinaryString(std::vector<std::string> nums)
{

    int len = nums[0].length();
    for(int i = 0; i < std::pow(2,len); i++)
    {
        std::bitset<16> temp(i);
        std::string searcher = temp.to_string();
        searcher = searcher.substr(16-len,len);

        if(std::find(nums.begin(), nums.end(), searcher) == nums.end())
        return searcher;
    }
    return " ";

    // решение кантора за O(n). работает только с определенными выходными данными
    // std::string ans="";
    // for(int i=0; i<nums.size(); i++) 
    //     ans+= nums[i][i]=='0' ? '1' : '0';          
    // return ans;
}


std::string generateTheString(int n)
{
    int ostatok = - (n % 2 - 1);
    std::string res = std::string(n - ostatok,'p');

    if(ostatok == 1)
    res += 'q';

    return res;
}

std::string removeTrailingZeros(std::string num)
{
    char temp = num.back();
    while(temp == '0')
    {
        num.pop_back();
        temp = num.back();
    }

    return num;
}

int differenceOfSum(std::vector<int> nums) 
{
    int sum = 0;
    int minSum = 0;

    for(int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        std::string temp = std::to_string(nums[i]);
        for(auto j = 0; j < temp.length(); j++)
        {
            minSum += temp[j] - '0';
        }
    }

    return sum - minSum;
}

int majorityElement(std::vector<int> nums)
{
    int searcherNums = 0;
    int searchCount = 0;

    for(auto i : nums)
    {
        if(i == searcherNums)
        {
            searchCount ++;
        }
        if(searchCount == 0)
        {
            searcherNums = i;
        }
        if(i != searcherNums)
        {
            searchCount --;
        }
    }

    return searcherNums;

    //     int fCounter = 0;
    // int sCounter = 0;
    // int fNum = nums.front();
    // int sNum = 0;

    // for(auto i : nums)
    // {
    //     if(i == fNum)
    //     {
    //         fCounter ++;
    //     }
    //     else
    //     {
    //         if(i != sNum)
    //         sNum = i;
    //         else
    //         sCounter ++;
    //     }
    // }

    // return fCounter > sCounter? fNum : sNum;

}

int findMiddleIndex(std::vector<int> nums) 
{
    if(nums.size() == 1)
    return 0;

    int sum = 0;
    int localSum = 0;

    for(auto i : nums)
    {
        sum += i;
    }

    for(int i = 0; i < nums.size(); i++)
    {
        if(sum - localSum - nums[i] == localSum)
        return i;

        localSum += nums[i];
    }

    return -1;
}

int minStartValue(std::vector<int> nums) 
{
    int nach = 1;
    int minPeak = 1;
    int sum = nach;

    for(auto i : nums)
    {
        sum += i;

        if(sum < minPeak)
        {
            minPeak = sum;
        }
    }

    return nach - minPeak + 1;
}

int missingNumber(std::vector<int> nums)
{
    int sum = 0;
    int max = nums.size();

    for(int i = 1; i < max + 1; i++)
    {
        sum -= nums.back();
        nums.pop_back();
        sum += i;
    }
    
    return sum;
}

int singleNumberInVec(std::vector<int> nums)
{
    int res = 0;

    for(auto i : nums)
    {
        // XOR.  0 ^ 4 = 4;   0 ^ 4 ^ 4 = 0;   0 ^ 4 ^ 4 ^ 5 = 5;
        res = res ^ i;
    }

    return res;

}

int sumOfUniqueElem(std::vector<int> nums)
{
    int sum = 0;

    for(int i = 0; i < nums.size(); i++)
    {
        if(std::count(nums.begin(), nums.end(),nums[i]) == 1)
        sum += nums[i];
    }

    return sum;
}

std::string firstPalindrome(std::vector<std::string>& words)
{
    for(auto i : words)
    {
        int len = i.length();
        bool res = true;

        for(int j = 0; j < len / 2; j++)
        {
            if(i[j] != i[len - j - 1])
            {
                res = false;
                break;
            }
        }

        if(res == true)
        return i;
    }

    return "";
}

std::vector<int> findIntersectionValues(std::vector<int> nums1, std::vector<int> nums2)
{

    int first = 0;
    int second = 0;

    for(auto i : nums1)
    {
        if(std::find(begin(nums2), end(nums2), i) != end(nums2))
        first ++;
    }
    for(auto i : nums2)
    {
        if(std::find(begin(nums1), end(nums1), i) != end(nums1))
        second ++;
    }

    return {first,second};
}

std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>> &image)
{
    // улучшенный алгоритм. скорость выполнения больше а затраты памяти меньше.
    for(auto &i : image)
    {  
        int iterators = i.size() - 1;
        int max = i.size() / 2;
        for(int j = 0; j < i.size(); j++)
        {
            if(iterators >= max)
            {
                std::swap(i[j],i[iterators]);
                iterators --;
            }

            if(i[j] == 0)
                i[j] = 1;
            else
                i[j] = 0;
        }
    }

    return image;
}

int largestAltitudeGet(std::vector<int> gain)
{
    int res = 0;
    int cur = 0;
    for(auto i : gain)
    {
        cur = cur + i;
        if(cur > res)
        res = cur;
    }
    return res;
}

std::vector<int> buildArrayPermutation(std::vector<int> nums)
{
    std::vector<int> ans;
    ans.reserve(nums.size());
    
    for(int i = 0; i < nums.size(); i++)
    {
        ans.push_back(nums[nums[i]]);
    }
    
    return ans;
}

