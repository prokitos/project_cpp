#include "zaC.h"
#include <vector>
#include <algorithm>
#include <math.h>
#include <iterator>    
#include <sstream>

std::vector<int> VectorSortMerge(std::vector<int> vec1, std::vector<int> vec2)
{
    std::vector<int> vec3;
    std::merge(vec1.begin(),vec1.end(),vec2.begin(),vec2.end(),std::back_inserter(vec3));

    return vec3;
}

std::map<char, unsigned> count(const std::string& string) {
    std::map<char, unsigned> output;
    for (size_t i = 0; i < string.length(); i++)
    {
        if(output.count(string[i]) == false)
        output[string[i]] = 1;
        else
        output[string[i]] += 1;
    }

    return output;
}

long zeros(long n) 
{   
    int output = 0;
    while(n > 4)
    {
        n = n / 5;
        output += n;
    }
    return output;
}

int rekursialPins(std::vector<std::string>& result, std::vector<int>& input, int curIter, std::string temp)
{
    if(curIter == input.size())
    {
        result.push_back(temp);
        return 1;
    }
    else
    {
        int curNum = input[curIter];

        if(curNum + 3 < 10 && curNum != 0)
            rekursialPins(result, input, curIter + 1, temp + std::to_string(curNum + 3));
        if(curNum - 3 > 0)
            rekursialPins(result, input, curIter + 1, temp + std::to_string(curNum - 3));
        if(curNum != 3 && curNum != 6 && curNum != 9 && curNum != 0)
            rekursialPins(result, input, curIter + 1, temp + std::to_string(curNum + 1));
        if(curNum != 1 && curNum != 4 && curNum != 7 && curNum != 0)
            rekursialPins(result, input, curIter + 1, temp + std::to_string(curNum - 1));

        if(curNum == 8)
            rekursialPins(result, input, curIter + 1, temp + std::to_string(0));
        if(curNum == 0)
            rekursialPins(result, input, curIter + 1, temp + std::to_string(8));


        return rekursialPins(result, input, curIter + 1, temp + std::to_string(curNum));

    }
}

std::vector<std::string> get_pins(std::string observed)
{
    std::vector<std::string> output;
    std::vector<int> input;
    for (size_t i = 0; i < observed.size(); i++)
    {
        input.push_back(observed[i] - '0');
    }
    
    int iterStart = 0;
    std::string temp = "";
    rekursialPins(output, input, iterStart, temp);

    return output;
}

void zaMainC()
{
    // зд 1
    //std::vector<int> vec1 = {1,3,5,7,9};
    //std::vector<int> vec2 = {2,4,6,8,10,12,14};
    //std::vector<int> vec3 = VectorSortMerge(vec1,vec2);
    //for(const auto iter : vec3)
    //    std::cout << iter << std::endl;

    // зд 2
    //count("abasabq");

    // зд 3 factorial zero character count
    //std:: cout << zeros(6) << std::endl;
    //std:: cout << zeros(30) << std::endl;
    //std:: cout << zeros(1000000000) << std::endl;

    // зд 4 
    std::vector<std::string> vec1 = get_pins("234");

    for(const auto i : vec1)
        std::cout << i << std::endl;

}
