#include "zaB.h"
#include <vector>
#include <algorithm>
#include <numeric>


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

void zaMainB()
{
    std::string str = "qwerty abc";
    std::string result = alphabet_position(str);
    std::cout << result;
};