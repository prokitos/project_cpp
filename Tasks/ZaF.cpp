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
    //std::cout << find_even_index ({1,2,3,4,3,2,1}); 

    // зд 3  вернуть из массива пары чисел, суммы которых равны 2
    //std::vector<std::pair<int, int>> res = twos_difference({4, 1, 2, 3});
    //for(auto item : res)
    //    std::cout << item.first << "  " << item.second << std::endl;
    
    // зд 4  предложение не имеет повторяющихся букв
    //std::cout << is_isogram("moose");

    // зд 5  кот прыгает +1 или +3 шага, сколько минимально нужно прыжков
    //std::cout << Cats(2,5);

    // зд 6  Одинокие девушки и парни на острове. девушка выбирает только по внешности +, сколько парней осталось
    //std::list<int> output = guysAloneFromGroup(std::list<int>({9, 5, 9, 2, 2, 1, 9, 10, 8, 9, 1, 7, 6, 5, 6, 2, 9}), std::list<int>({4, 1, 8, 9, 8, 3, 9, 8, 3, 7, 9}));
    //for(auto i : output)
    //    std::cout << i << std::endl;

    // Зд 7 Трибоначи. как фибоначи только из 3. нужно вернуть весь массив цифр, начальные 3 числа могут меняться.
    std::vector<int> signature = { 1, 1, 1 };
    std::vector<int> result = tribonacci(signature,30);
    for(auto i : result)
        std::cout << i << std::endl;

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

std::vector<std::pair<int, int>> twos_difference(const std::vector<int> &vec) 
{
    std::vector<int> vector = vec;
    std::vector<std::pair<int, int>> result;
    std::sort(vector.begin(), vector.end());

    for (size_t i = 0; i < vector.size(); i++)
    {
        int temp = vector[i] + 2;
        if(std::find(std::begin(vector), std::end(vector), temp) != std::end(vector))
        {
            auto pos = std::find(std::begin(vector), std::end(vector), temp);
            int normPos = pos - vector.begin();
            result.push_back({vector[i],vector[normPos]});
        }
    }
    
    return result;
}

bool is_isogram(std::string str)
{
    bool result = true;
    bool mass[35] = {};

    for (size_t i = 0; i < str.length(); i++)
    {
        int index = std::tolower(str[i]) - 'a';
        if(mass[index] == false)
            mass[index] = true;
        else
            result = false;
    }
    
    return result;
}

unsigned int Cats(unsigned int start, unsigned int finish) 
{
    int temp = finish - start;
    int jump = 0;

    if(temp > 2)
    {
        jump += temp / 3;
        temp = temp % 3;
        jump += temp;
    }
    else
    {
        jump = temp;
    }

    return jump;
}




std::list<int> guysAloneFromGroup(const std::list<int> & men, const std::list<int> & women)
{
    if (women.size() == 0)
        return men;
    if (men.size() == 0)
        return men;

    std::vector<int> vMan (men.begin(), men.end());
    std::vector<int> vWoman{ std::begin(women), std::end(women) };

    std::sort(vMan.begin(), vMan.end(), std::greater<>());
    std::sort(vWoman.begin(), vWoman.end(), std::greater<>());

    int MenDating[men.size()]{};
    int WomanDating[women.size()]{};

    bool nulator = false;
    for (size_t i = 0; i < men.size(); i++)
    {
        if(nulator == true)
        {
            i = 0;
            nulator = false;
        }
        int menValue = vMan[i];
        if( (menValue < 8 && MenDating[i] == 0) || (menValue > 7 && MenDating[i] < 2) )
        for (size_t j = 0; j < women.size(); j++)
        {
            int womenValue = vWoman[j];
            
            if(menValue > 7 && MenDating[i] > 1)
            break;
            if(menValue < 8 && MenDating[i] > 0)
            break;
          
            if(womenValue <= menValue - 2 || (menValue > 7 && womenValue <= menValue))
            if(WomanDating[j] == 0)
            {
                MenDating[i] += 1;
                WomanDating[j] += 1;

                if(vMan[i + 1] < menValue)
                {
                    nulator = true;
                    break;
                }

                if(vMan[i + 1] == menValue && menValue > 7)
                break;

            }
        }
            
    }

    // получение результата
    std::vector<int> guysTemp;
    for (size_t i = 0; i < men.size(); i++)
    {
        if(MenDating[i] == 0)
            guysTemp.push_back(vMan[i]);
    } 


    std::sort(guysTemp.begin(), guysTemp.end());
    std::list<int> guysLone (guysTemp.begin(), guysTemp.end());
    
    return guysLone;
    // 8, 8, 8, 8, 8
}


std::vector<int> tribonachiNormal(std::vector<int> output, int max, int cur)
{
    if(max == cur)
    {
        return output;
    }
    else
    {
        int res = output[cur] + output[cur + 1] + output[cur + 2];
        output.push_back(res);
        return tribonachiNormal(output, max, cur + 1);
    }
}


std::vector<int> tribonacci(std::vector<int> signature, int n)
{
    if(n == 3)
    return signature;

    if(n < 3)
    {
        signature.resize(n);
        return signature;
    }

    std::vector<int> result = tribonachiNormal(signature, n - 3, 0);
    return result;
    
}