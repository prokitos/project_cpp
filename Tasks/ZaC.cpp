#include "zaC.h"
#include <vector>
#include <algorithm>
#include <math.h>

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

}
