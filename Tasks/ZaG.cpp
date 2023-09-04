#include "zaG.h"
#include <vector>
#include <algorithm>
#include <math.h>
#include <iterator>    
#include <sstream>
#include <map>
#include <iterator>    
#include <sstream>
#include <regex>
#include <numeric>

void zaMainG()
{
    // зд 1  перевод 0-255 в 00-FF
    std::cout << rgb(148,0,211);  // 94 00 D3
    //    быстрый способ
    //    char result[10];
    //    std::sprintf(result, "%02X", num)

    


};

// превращение из 10 системы в 16
std::string rgb(int r, int g, int b)
{
    std::string result {};

    if(r > 255 || g > 255 || b > 255)
        return result;

    if(r < 0 || g < 0 || b < 0)
        return result;

    result += numberRgb(r);
    result += numberRgb(g);
    result += numberRgb(b);

    return result;
};

// обход каждого числа
std::string numberRgb(int num)
{
    std::string result {};
    int first = 0;
    int second = 0;

    // словарь со всеми обозначениями для перевода в hex
    std::map<int,std::string> hexx;
    hexx[0] = "0"; hexx[1] = "1"; hexx[2] = "2"; hexx[3] = "3"; hexx[4] = "4"; hexx[5] = "5";
    hexx[6] = "6"; hexx[7] = "7"; hexx[8] = "8"; hexx[9] = "9"; hexx[10] = "A"; hexx[11] = "B";
    hexx[12] = "C"; hexx[13] = "D"; hexx[14] = "E"; hexx[15] = "F";

    while (num != 0)
    {
        if(num > 15)
        {
            first ++;
            num -= 16;
        }
        else if(num > 0)
        {
            second ++;
            num --;
        }
    }

    if(first > 15)
        first = 15;
    if(second > 15)
        second = 15;
    
    result += hexx[first];
    result += hexx[second];



    return result;
};