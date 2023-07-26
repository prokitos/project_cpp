#include "zaA.h"
#include <vector>
#include <algorithm>
#include <numeric>

std::string to_camel_case(std::string text)
{
    for (size_t i = 0; i < text.length(); i++)
    {
        if(text[i] == '-')
        {
            text.erase(i,1);
            text[i] = toupper(text[i]);
        }
    }
    
    return text;
}

void printStroka(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        std::cout << str[i];
    }
}

long sumTwoSmallestNumbers(std::vector<int> numbers)
{
    std::sort(numbers.begin(), numbers.end());
    long outs = numbers[0] + numbers[1];
    return outs;
}

bool XO(const std::string& str)
{
    int xCount = 0;
    int oCount = 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        if(std::toupper(str[i]) == 'X')
            xCount ++;
        if(std::toupper(str[i]) == 'O')
            oCount ++;
    }

    return xCount == oCount;
}

bool is_negat(int x){return x > 0;}

int positive_sum (const std::vector<int> arr)
{
    
/*
    int sum = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        if(arr[i] >= 0)
            sum += arr[i];
    }
    return sum;
*/

    return std::accumulate(arr.begin(), arr.end(), 0, [](int x, int y) { return x + (y > 0 ? y : 0); });
}

std::string sliceString (std::string str )
{
  str.erase(str.end() - 1);
  str.erase(str.begin());
  return str;
}

std::vector<std::string> string_to_array(const std::string& s) 
{
    std::vector<std::string> vec1;

    auto Pos1 = s.find(' ');
    auto Pos2 = s.find(' ');
    vec1.push_back(s.substr(0,Pos1));

    while (s[Pos1] == ' ')
    {
        Pos2 = s.find(' ', Pos1 + 1);
        vec1.push_back(s.substr(Pos1 + 1,Pos2 - Pos1 - 1));
        Pos1 = Pos2;
    }

    return vec1;
}

void zaMain()
{
    // зд 1
    //std::string stroka = to_camel_case("the-stealth-warrior");
    //printStroka(stroka);

    // зд 2
    //std::vector<int> vec1 = {4, 1, 2, 5, 8, 5, 4};
    //long res = sumTwoSmallestNumbers(vec1);
    //std::cout << res;

    // зд 3
    //bool tmp = XO ("xoxoxo");
    //if (tmp == true)  
    //    std::cout << "good"; 
    //else
    //    std::cout << "no good";

    // зд 4
    //std::vector<int> vec1 = {4, -5, 2, 5, -12, 5, 4};
    //int tmp = positive_sum(vec1);
    //std::cout << tmp;

    // зд 5
    //std::string sss = sliceString("qwerty");
    //std::cout << sss;

    // зд 6
    std::vector<std::string> vec1 = string_to_array("al oli gero torns ar");

    for (size_t i = 0; i < vec1.size(); i++)
    {
        std::cout << vec1.at(i);
    }
    
};