#include "zaE.h"
#include <vector>
#include <algorithm>
#include <math.h>
#include <iterator>    
#include <sstream>
#include <map>
#include <iterator>    
#include <sstream>
#include <regex>


std::string likes(const std::vector<std::string> &names)
{
    std::string output {};

    switch (names.size())
    {
    case 0:
        output = "no one likes this";
        break;
    case 1:
        output = names[0] + " likes this";
        break;
    case 2:
        output = names[0] + " and " + names[1] + " like this";
        break;
    case 3:
        output = names[0] + ", " + names[1] + " and " + names[2] + " like this";
        break;
    
    default:
        output = names[0] + ", " + names[1] + " and " + std::to_string(names.size() - 2) + " others like this";
        break;
    }

    return output; 
}

std::vector<int> sortArray(std::vector<int> array)
{
    std::vector<int> tempOdd;

    for (auto item : array)
        if(item % 2 == 1)
            tempOdd.push_back(item);
    
    std::sort(tempOdd.begin(),tempOdd.end());

    for (size_t i = 0, j = 0; i < array.size(); i++)
    {
        if(array[i] % 2 == 1)
        {
            array[i] = tempOdd[j];
            j ++;
        }
    }
    
    return array;
}

std::string highestScoringWord(const std::string &str)
{
    std::vector<std::string> inputs;     
    std::istringstream iss(str);
    std::copy(std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>(), std::back_inserter(inputs));

    std::string output {};
    int max = 0;
    for (auto items : inputs)
    {
        int temp = 0;
        for (size_t i = 0; i < items.length(); i++)
        {
            temp += items[i] - 'a';
        }

        if(temp >= max)
        {
            max = temp;
            output = items;
        }
        
    }
    
    return output;
}

std::vector<std::string> towerBuilder(unsigned nFloors) 
{
    std::vector<std::string> output {};
    int starCount = 1;
    int spaceCount = nFloors;

    if(nFloors > 0)
    for (size_t i = 0; i < nFloors; i++)
    {
        std::string floor = std::string(spaceCount, ' ') + std::string(starCount, '*') + std::string(spaceCount, ' ');
        output.push_back(floor);
        starCount += 2;
        spaceCount --;
    }

    return output;
}

int persistence(long long n)
{
    int result = 0;
    int tempInt = 0;
    std::string stroka;

    while(n > 9)
    {
        stroka = std::to_string(n);
        tempInt = stroka[0] - '0';
        for (int i = 1; i < stroka.length(); i++)
        {
            tempInt = tempInt * (stroka[i] - '0');
        }
        result ++;
        n = tempInt;
    }

    return result;
}


std::vector <long long int> wheatFromChaff (std::vector <long long int> values)
{

    int i = 0;
    int j = values.size() - 1;
    while (i != j)
    {
        if(values[i] < 0)
            i++;
        else
        {
            if(values[j] > 0)
                j--;
            else
                std::swap(values[i], values[j]);
        }

    }
    
    return values;
}


void zaMainE()
{
    // зд 1
    //std::cout << highestScoringWord("man i need a taxi up to ubud");

    // зд 2
    //std::vector<int> input = {3, 2, 3, 6, 4, 1, 2, 3, 2, 1, 2, 3};
    //std::vector<std::string> temp = towerBuilder(3);
    //for(auto items : temp)
    //    std::cout << items << std::endl;

    // зд 3
    //std::vector<int> input = {0,5,2,3,1,4,7,8};
    //input = sortArray(input);
    //for(auto items : input)
    //    std::cout << items << std::endl;

    
    // зд 4  через регекс лучше
    //std::vector<std::string> input = { "Max", "John", "Mark" }; 
    //std::cout << likes(input);

    // зд 5
    //std::cout << persistence(999);

    // зд 6
    std::vector<long long int> vec = {7,-3,-10};
    vec = wheatFromChaff(vec);
    for(auto item : vec)
        std::cout << item << std::endl;


}
