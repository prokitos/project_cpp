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
    std::vector<int> temp = productExceptSelf({1,2,3,4});  //  -1,-1,0,-3,3  =  0,0,9,0,0
    for(auto i : temp)
    std::cout << i << " ";

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

