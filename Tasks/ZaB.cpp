#include "zaB.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <string>
#include <iterator>
#include <cmath>

int score(const std::vector<int>& dice) 
{
    int f_score = 0;
    int counts[7] = {};

    for (auto d : dice)
    {
        counts[d] ++;
    }
    
    f_score = counts[1] / 3 * 1000 + counts[2] / 3 * 200 + counts[3] / 3 * 300 +
    counts[4] / 3 * 400 + + counts[5] / 3 * 500 + + counts[6] / 3 * 600;
    f_score += counts[1] % 3 * 100 + counts[5] % 3 * 50;

    /*
    for (size_t i = 1; i < 7; i++)
    {
        int temp_score = std::count(dice.begin(), dice.end(), i);

            for (size_t j = 0; j < 2; j++)
            {
                if(temp_score > 2 && i == 1) 
                {
                    f_score += 100 * 10;
                    temp_score -= 3;
                }
                if(temp_score > 0 && i == 1)
                {
                    f_score += 100;
                    temp_score -= 1;
                } 
            
                if(temp_score > 2 && i > 1)
                {
                    f_score += 100 * i;
                    temp_score -= 3;
                }
                if(i == 5 && temp_score > 0)
                {
                    f_score += 50;
                    temp_score -= 1;
                }
                    
            }
    }   
    */
    
    return f_score;
}

std::string alphabet_position(const std::string &text) 
{
    std::string mass = "abcdefghijklmnopqrstuvwxyz";
    std::string output = "";

    for (size_t i = 0; i < text.length(); i++)
    {
        auto Posl = mass.find(std::tolower(text[i]));
        Posl ++;

        if(Posl <= mass.length() + 1 && Posl > 0)
        {
            if(output.length() > 0)
                output += " ";

            output += std::to_string(Posl);
        }
    }
    
    return output;
}

int findOdd(const std::vector<int>& numbers)
{
    int result = INT32_MAX;
    
    for (size_t i = 0; i < numbers.size(); i++)
    {
        int temp = std::count(numbers.begin(), numbers.end(), numbers[i]);
        if(temp % 2 == true)
        {
            result = numbers[i];
            break;
        }
    }
    
    return result;
}

int FindOutlier(std::vector<int> arr)
{
    int output = INT32_MAX;

    for (size_t i = 0; i < arr.size(); i++)
    {
        if((bool)(arr[i] % 2) == (bool)(arr[i + 1] % 2) && (bool)(arr[i] % 2) == (bool)(arr[i + 2] % 2))
        {
            continue;
        }

        if((bool)(arr[i] % 2) == (bool)(arr[i + 1] % 2))
            output = arr[i + 2];
        else if((bool)(arr[i] % 2) == (bool)(arr[i + 2] % 2))
            output = arr[i + 1];
        else
            output = arr[i];
        
        break;
    }
    

    return output;
}


std::vector<int> WeightSort::strNumSum(std::vector<std::string> strng)
{
    std::vector<int> vecInt;
    for (size_t i = 0; i < strng.size(); i++)
    {
        int temp = 0;
        for (size_t j = 0; j < strng.at(i).length(); j++)
        {
            char dee = strng.at(i)[j];
            temp += dee - '0';
        }
        vecInt.push_back(temp);
    }
    return vecInt;
}

std::string WeightSort::orderWeight(const std::string &strng)
{
    std::vector<std::string> vecStr;

    auto Pos1 = 0;
    auto Pos2 = strng.find(' ');
    vecStr.push_back(strng.substr(Pos1,Pos2-Pos1));
    
    while (Pos2 > 0 && Pos2 < strng.length())
    {
        Pos1 = Pos2;
        Pos2 = strng.find(' ',Pos1 + 1);
        vecStr.push_back(strng.substr(Pos1 + 1,Pos2-Pos1-1));
    }

    std::vector<int> vecInt = strNumSum(vecStr);
    
    for (size_t i = 0; i < vecInt.size(); i++)
    {       
        for (size_t j = 0; j < vecInt.size(); j++)
        {
            if(vecInt[j] > vecInt[i])
            {
                int tempInt = vecInt[j];
                std::string tempStr = vecStr[j];

                vecInt[j] = vecInt[i];
                vecInt[i] = tempInt;
                vecStr[j] = vecStr[i];
                vecStr[i] = tempStr;
            }
            if(vecInt[j] == vecInt[i] && vecStr[j] > vecStr[i])
            {
                std::string tempStr = vecStr[j];
                vecStr[j] = vecStr[i];
                vecStr[i] = tempStr;
            }
        }

    }
    
    std::string output;
    for (size_t i = 0; i < vecStr.size(); i++)
    {
        if(vecStr[i] != "")
        {
            if(i == vecStr.size() - 1)
                output += vecStr[i];
            else
                output += vecStr[i] + " ";
        }

    }
    
    return output;
}

void testFunc(std::string strng)
{
    std::vector<std::string> inputs;
    std::istringstream iss(strng);
    
    // стринг в вектор стринг
    std::copy(std::istream_iterator<std::string>(iss), 
    std::istream_iterator<std::string>(),
    std::back_inserter(inputs));

    // кастомная сортировка массива. сравнивает по 2 числа.
    std::sort(inputs.begin(), inputs.end(),
    [](const std::string& s1, const std::string& s2) {
        auto sum_func = [](const char c, int acc) { return acc + static_cast<int>(c-'0'); };
        int s1sum = std::accumulate(s1.begin(), s1.end(), 0, sum_func);
        int s2sum = std::accumulate(s2.begin(), s2.end(), 0, sum_func);
        if (s1sum == s2sum)
        return s1 < s2;
        else
        return s1sum < s2sum;
    });

}

bool isPrime(int num)
{
    if(num <= 1) { return false; }

    int count = 0;

    for (int i = 1; i < sqrt(num); i++)
    {
        if(num % i == 0)
            count ++;
    }
    
    if(count > 1)
        return false;
    else
        return true;
    
}

void zaMainB()
{
    // зд 1
    //std::vector<int> vec1 = {4, 2, 5, 5, 4};
    //int res = score(vec1);
    //std::cout << res;

    // зд 2
    //std::string str = "qwerty abc";
    //std::string result = alphabet_position(str);
    //std::cout << result;

    // зд 3
    //std::vector<int> vec1 = {1,3,5,3,9,5,1};
    //int res = findOdd(vec1);
    //std::cout << res;

    // зд 4
    //std::vector<int> vec1 = {3, 7, -99, 81, 90211, 0, 7};
    //int res = FindOutlier(vec1);
    //std::cout << res;

    // зд 5
    //WeightSort Weight;
    //std::string inputer = "2000 103   123    4444 99  ";
    //std::string result = Weight.orderWeight(inputer);
    //std::cout << result;
    //testFunc("13 20 44 100");
    
    // зд 6
    //bool res = isPrime(499);
    //std::cout << res;
};