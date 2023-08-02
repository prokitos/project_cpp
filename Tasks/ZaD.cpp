#include "zaD.h"
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

struct PeakData 
{
  std::vector<int> pos, peaks;
};

PeakData pick_peaks(const std::vector<int> &v) 
{
    PeakData result;

    bool longPick = false;
    int longPickCount = 0;
    for (size_t i = 1; i < v.size() - 1; i++)
    {
            // normal pick
            if(v[i] > v[i-1] && v[i] > v[i+1])
            {
                result.peaks.push_back(v[i]);
                result.pos.push_back(i);
            }

            // long pick
            if(longPick == true)
            {
                if(v[i] == v[i + 1])
                    longPickCount ++;
                if(v[i] > v[i + 1])
                {
                    longPick = false;
                    result.peaks.push_back(v[i - longPickCount]);
                    result.pos.push_back(i - longPickCount);
                    longPickCount = 0;
                }
                if(v[i] < v[i + 1])
                {
                    longPick = false;
                    longPickCount = 0;
                }
            }
            if(v[i] > v[i - 1] && v[i] == v[i + 1])
            {
                longPick = true;
                longPickCount ++;
            }
    }
    
  return result;
};

std::string Mix::mix(const std::string &s1, const std::string &s2)
{
    std::string count1[26] = {};
    std::string count2[26] = {};
    std::vector<std::string> result;

    // добавление строк в массивы
    for (size_t i = 0; i < s1.length(); i++)
    {
        int charCode = s1[i] - 'a';
        if(charCode >= 0 && charCode < 26)
            count1[charCode] += s1[i];
    }

    for (size_t i = 0; i < s2.length(); i++)
    {
        int charCode = s2[i] - 'a';
        if(charCode >= 0 && charCode < 26)
            count2[charCode] += s2[i];
    }

    // добавление всех строк в один вектор + форматирование
    for (size_t i = 0; i < std::size(count1); i++)
    {
        if(count1[i].length() == count2[i].length() && count1[i].length() > 1)
        {
            result.push_back("=:" + count1[i]);
        }
        else if(count1[i].length() > 1 && count1[i].length() > count2[i].length())
        {
            result.push_back("1:" + count1[i]);
        }
        else if(count2[i].length() > 1)
        {
            result.push_back("2:" + count2[i]);
        }
    }
    
    std::sort(result.begin(), result.end());
    std::sort(result.begin(), result.end(), [](std::string& s1, std::string& s2) {return s1.length() > s2.length();});

    std::string output {};
    for (size_t i = 0; i < result.size(); i++)
    {
        if(i == 0)
            output += result[i];
        else
            output += "/" + result[i];
    }
    
    return output;
}


std::string disemvowel(const std::string& str)
{
    std::string output {};
    char mass[] = {'a','e','u','o','a','i'};

    for (size_t j = 0; j < str.length(); j++)
    {
        bool cheker = false;
        for (size_t i = 0; i < std::size(mass); i++)
        {
            if(std::tolower(str[j]) == mass[i])
                cheker = true;
        }
        
        if(cheker == false)
        output += str[j];
    }
    return output;

    //std::regex vowels("[aeiouAEIOU]");
    //return std::regex_replace(str, vowels, "");
}

std::string longest(const std::string &s1, const std::string &s2)
{
    char mass[26] = {};
    std::string multiSting = s1 + s2;
    std::string str = {};

    for(auto item : multiSting)
    {
        int charnum = item - 'a';
        if(mass[charnum] == 0)
            mass[charnum] = item;
    }
    
    for(auto item : mass)
        if(item != 0)
        str += item;

    return str;
}

void zaMainD()
{
    // зд 1
    //std::string res = format_duration(0);
    //std::string res = format_duration(120); 
    //res = format_time_new(100000);
    //std::cout << res;

    // зд 2
    //std::vector<int> input = {3, 2, 3, 6, 4, 1, 2, 3, 2, 1, 2, 3};
    //PeakData output = pick_peaks(input);
    //for(auto i : output.peaks)
    //    std::cout << i << "  ";
    //std::cout << std::endl;
    //for(auto i : output.pos)
    //    std::cout << i << "  ";

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
