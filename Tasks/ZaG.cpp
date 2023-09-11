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


#define isParenthesized() false

bool (isParenthesized)() {
  return true;
}

void zaMainG()
{
    // зд 1  перевод 0-255 в 00-FF
    //std::cout << rgb(148,0,211);  // 94 00 D3
    //    быстрый способ
    //    char result[10];
    //    std::sprintf(result, "%02X", num)

    // зд 2  суммирование цифр, пока не станет одна цифра
    //std::cout << digital_root(942);

    // зд 3  польская нотация?  (3+6) * (1*2*3)
    // std::string text = "(*(+3 6)(*1 2 3))";
    // PolNotationClass test;
    // test.solveAll(text);

    // Зд 4 вернет правильный ли порядок скобок в строке.
    //std::cout << valid_braces("([{}])");

    // зд 5 вернуть 0 если в функция вызывается из скобок.
    // компилятор игнорит если в скобках?
    //bool first =  isParenthesized();
    //bool second = (isParenthesized)();
    //std::cout << first << "   " << second;

    // зд 6 убрать множественные пробелы, сделать большие буквы и добавить точки.
    //std::string stroka = "David holds a kite.  the salaryman kept the wallet.you   sell a chair You want end this.  ";
    //std::cout << correct_it(stroka) << "!!";    // проверка на пробелы в конце строки

    // зд 7 повторение числа в массиве только N раз.
    // std::vector<int> temp;
    // temp = deleteNth({1,1,3,3,7,2,2,2,2}, 3);
    // for(auto i : temp)
    //     std::cout << i << " ";

    // зд 8 получить только по одной букве/цифре из стоящих рядом одинаковых букв/цифр. вводятся строки и вектора.
    //std::vector<int> input = {1,22,3,3};
    //std::vector<int> vec = uniqueInOrder(input);
    std::vector<char> vec = uniqueInOrder("AAAABBBCCDAABBB");
    for(auto i : vec)
        std::cout << i << " ";


};


// для строк
std::vector<char> uniqueInOrder(const std::string& iterable)
{
    std::vector<char> vec {};

    for(auto i : iterable)
        if(vec.size() == 0 || vec.back() != i)
            vec.push_back(i);

    return vec;
}

// для векторов
template<typename Type>
std::vector<Type> uniqueInOrder(const std::vector<Type>& iterable)
{
    std::vector<Type> vec {};

    for(auto i : iterable)
        if(vec.size() == 0 || vec.back() != i)
            vec.push_back(i);

    return vec;
}


std::vector<int> deleteNth(std::vector<int> arr, int n)
{
    std::map<char,int> slovar = {};
    std::vector<int> newVec = {}; // через erase долго удаляется, поэтому новым вектором.

    for (auto i : arr)
    {
        if(slovar[i] < n)
        {
            slovar[i] ++;
            newVec.push_back(i);
        }
    }

    return newVec;
}

std::string correct_it(std::string str) 
{
    std::string newString {};

    // добавить точки перед большими буквами
    std::regex vowels("([A-Z])");
    str = std::regex_replace(str, vowels, ".$1");
    // убрать пробелы перед точками
    vowels = ("( +)\\.");
    str = std::regex_replace(str, vowels, ".");
    // убрать пробелы после точек
    vowels = ("\\.( +)");
    str = std::regex_replace(str, vowels, ".");
    // убрать множественные точки
    vowels = ("\\.+");
    str = std::regex_replace(str, vowels, ".");

    // добавить большие буквы после точек
    for (size_t i = 0; i < str.length(); i++)
    {
        if(str[i] == '.')
        {   
            newString += str[i];
            newString += std::toupper(str[i + 1]);
            i ++;
            continue;
        }
        newString += str[i];
    }

    // убираем множественные пробелы,
    vowels = (" +");
    newString = std::regex_replace(newString, vowels, " ");

    // Добавляем пробел перед точками
    vowels = ("(\\.)");
    newString = std::regex_replace(newString, vowels, "$1 ");

    //убрать точку в начале строки
    vowels = ("^.");
    newString = std::regex_replace(newString, vowels, "");
    //убрать пробел в начале строки
    vowels = ("^ ");
    newString = std::regex_replace(newString, vowels, "");
    //убрать пробел в конце строки
    vowels = ("..$");
    newString = std::regex_replace(newString, vowels, "");

    return newString;
}

bool valid_braces(std::string braces)
{
    bool result = true;

    int len = 3;
    char massOpen[len] = {'(','{','['};
    char massClos[len] = {')','}',']'};

    // перебо по всем символам, и сравнение со скобками
    for (size_t i = 1; i < braces.length(); i++)
    {
        for (size_t j = 0; j < 3; j++)
        {   
            //если две скобки рядом, то убрать их, и потом начать цикл заново
            if(braces[i - 1] == massOpen[j] && braces[i] == massClos[j])
            {
                braces.replace(i - 1,2,"");
                i = 0;
                break;
            }
        }
        

        
    }
    
    // если в итоговой строке остались скобки, то фолс
    if(braces.length() > 0)
        result = false;

    return result;
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


// сумма всех цифр в числе
int digitSum(int chislo)
{
    int result = 0;
    std::string stroka = std::to_string(chislo);

    for (size_t i = 0; i < stroka.length(); i++)
    {
        result += stroka[i] - '0';
    }
    
    return result;
};

// основная функция, постоянно вызывает пересчет цифр если их больше 1
int digital_root(int n)
{
    int result = n;

    while(result > 9)
    {
        result = digitSum(result);
    }

    return result;
};




// вычисление всех скобок
void PolNotationClass::solveAll(std::string stroka)
{   

std::string result {};

// позиции первой и второй скобки
int fBracket = -1;
int sBracket = -1;

// если в строке есть скобки то перебираем дальше
while (sBracket == -1)
{
    sBracket = 0;
    // перебор всей строки
    for (size_t i = 0; i < stroka.length(); i++)
    {

        // нахождение позиции первой и второй скобки (внутренние)
        if(stroka[i] == '(')
            fBracket = i;
        if(stroka[i] == ')')
        {
            sBracket = i;
            
            // получаем строку внутренней скобки
            std::string temp = stroka.substr(fBracket,sBracket - fBracket + 1);
            result = solveCurrent(temp);

            // замена строки
            stroka.replace(fBracket,sBracket - fBracket + 1, result);

            sBracket = -1;
            break;
        }

    }

}

std::cout << stroka;

};


// вычисление одной скобки.
std::string PolNotationClass::solveCurrent(std::string stroka)
{
    // получение чисел и знака
    std::string newString {};
    char znak = stroka[1];
    newString = stroka.substr(2, stroka.length() - 3);
    
    // отдельно числа в вектор
    std::vector<std::string> chisla;  
    std::istringstream iss(newString);
    std::copy(std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>(), std::back_inserter(chisla));

    // перевод в инт и вычисление
    int result = std::stoi(chisla[0]);

    for (size_t i = 1; i < chisla.size(); i++)
    {
        if(znak == '+')
            result = result + std::stoi(chisla[i]);
        if(znak == '-')
            result = result - std::stoi(chisla[i]);
        if(znak == '*')
            result = result * std::stoi(chisla[i]);
    }
    
    return " " + std::to_string(result) + " ";
};