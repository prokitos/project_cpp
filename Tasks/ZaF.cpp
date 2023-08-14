#include "zaF.h"
#include <vector>
#include <algorithm>
#include <math.h>
#include <iterator>    
#include <sstream>
#include <map>
#include <iterator>    
#include <sstream>
#include <regex>




void zaMainF()
{
    // зд 1  переворот подстрок в строке
    //std::cout << reverse_words("apple apple  germers!");

    // зд 2  найти индекс где правые элементы массива равны левому
    std::cout << find_even_index ({1,2,3,4,3,2,1}); 

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
    //std::vector<long long int> vec = {7,-3,-10};
    //vec = wheatFromChaff(vec);
    //for(auto item : vec)
    //    std::cout << item << std::endl;

    // зд 7
    //std::cout << rowSumOddNumbers(4);


}

std::string reverse_words(std::string str)
{  
    std::string result = str;
    std::vector<std::string> inputs;     
    std::istringstream iss(str);
    std::copy(std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>(), std::back_inserter(inputs));

    for (size_t i = 0; i < inputs.size(); i++)
    {
        std::string temp = inputs[i];
        std::reverse(inputs[i].begin(), inputs[i].end());

        auto position = str.find(temp);
        result.replace(position,temp.length(),inputs[i]);
        str.replace(position,temp.length(),std::string(temp.length(), ' '));
    }
    
    return result;
}

int find_even_index (const std::vector <int> numbers) 
{
    int result = -1;

    for (int testResult = 1; testResult < numbers.size(); testResult++)
    {
        int sumFirst = 0;
        for (size_t i = 0; i < testResult; i++)
        {
            sumFirst += numbers[i];
        }
        
        int sumSecond = 0;
        for (size_t i = testResult + 1; i < numbers.size(); i++)
        {
            sumSecond += numbers[i];
        }

        if(sumFirst == sumSecond)
        {
            result = testResult;
            break;
        }
    }
    
    // можно через аккумулейт, и тем самым убрать циклы внутри циклов
    return result;
}