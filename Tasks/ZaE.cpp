#include "zaE.h"
#include <vector>
#include <algorithm>
#include <math.h>
#include <iterator>    
#include <sstream>
#include <map>
#include <iterator>    
#include <sstream>



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

void zaMainE()
{
    // зд 1
    //std::cout << highestScoringWord("man i need a taxi up to ubud");

    // зд 2
    //std::vector<int> input = {3, 2, 3, 6, 4, 1, 2, 3, 2, 1, 2, 3};
    std::vector<std::string> temp = towerBuilder(3);
    for(auto items : temp)
        std::cout << items << std::endl;

    // зд 3
    //Mix classess;
    //std::cout << classess.mix("Are they here", "yes, they are here");
    
    // зд 4  через регекс лучше
    //std::vector<std::string> input = { ":)", ";(", ";}", ":-D"}; 
    //std::cout << countSmileys(input); 

    // зд 5
    //std::cout << disemvowel("This website is for losers LOL!");

    // зд 6
    //std::cout << longest("aretheyhere", "yestheyarehere");


}
