#include "zaC.h"
#include <vector>
#include <algorithm>
#include <math.h>
#include <iterator>    
#include <sstream>
#include <map>


std::string format_duration(int seconds)
{
    std::string output {};

    if(seconds == 0)
        output = "now";

    std::vector<int> time = {seconds,0,0,0,0};
    std::vector<std::string> timeName = {"second","minute","hour","day","year"};
    std::vector<std::string> timeNames = {"seconds","minutes","hours","days","years"};

    while (time[0] >= 60)
    {
        for (size_t i = 0; i < time.size(); i++)
        {
            if(i == 0 || i == 1)
                if(time[i] >= 60)
                {
                    time[i] -= 60;
                    time[i + 1] += 1;
                }

            if(time[2] >= 24)
            {
                time[2] -= 24;
                time[3] += 1;
            }

            if(time[3] >= 365)
            {
                time[3] -= 365;
                time[4] += 1;
            }
        }
        
    }

    int counter = std::count(time.begin(), time.end(), 0);
    counter = 5 - counter;

    for (size_t i = time.size() - 1; i >= 0 ; i--)
    {
        if(time[i] > 0)
        {
            if(time[i] == 1)
                output += std::to_string(time[i]) + " " + timeName[i];
            else
                output += std::to_string(time[i]) + " " + timeNames[i];
         
            if(counter == 2)
                output += " and ";
            if(counter > 2)
                output += ", ";

            counter --;
        }
        if(i == 0)
            break;
    }

    return output;
}

std::string format_time_new(int seconds)
{
    if(seconds == 0) return "now";
    std::vector<std::string> resVector;

    auto fun_add = [&] (auto text, auto time)
    {
        if (time == 0) return;
        resVector.push_back(std::to_string(time) + text + (time > 1 ? "s" : ""));
    };

    fun_add(" year", seconds / 60 / 60 / 24 / 365);
    fun_add(" day", (seconds / 60 / 60 / 24) % 365);
    fun_add(" hour", (seconds / 60 / 60) % 24);
    fun_add(" minute", (seconds / 60) % 60);
    fun_add(" second", seconds % 60);
    
    std::string result = resVector[0];
    for (size_t i = 1; i < resVector.size() - 1; i++)
    {
        result.append(", " + resVector[i]);
    }
    return result;

}

void zaMainD()
{
    // зд 1
    //std::string res = format_duration(0);
    //std::string res = format_duration(120); 
    //res = format_time_new(100000);
    //std::cout << res;

}
