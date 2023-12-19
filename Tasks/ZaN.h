#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>
#include <iterator>
#include <sstream>
#include <map>
#include <set>
#include <regex>

void zaMainN();


class operatorTest
{
public:
    operatorTest(std::string name)
    {
        this->name = name;
    };

    operatorTest(const operatorTest &src); // копирование
    operatorTest& operator = (operatorTest &src); // присваивание копированием

    operatorTest(operatorTest &&src); // перемещение
    operatorTest& operator = (operatorTest &&src); // присваивание перемещением

    void print();   // вывод name
private:
    std::string name = "null";
};


void massMerge();
void massSpecPrint();

std::string longestStringRet(const std::vector<std::string> &strarr, std::string stroka);

double posAverage(const std::string &s);

bool scramble(const std::string& s1, const std::string& s2);

void algorithmTest();
void regexTest();
void testInt();

int solutionMultiplier(int number);

std::pair<std::size_t, std::size_t> two_sumss(const std::vector<int>& numbers, int target);
std::string reverse_wordss(const std::string& str);
std::vector<std::string> numberFun(const std::vector<std::string> &lines);
int sumOfDeviders(int number);

bool loonAlgorithmCheck(int number);

std::string abbreveatureName(std::string name);
std::vector<unsigned long long> partsSum(const std::vector<unsigned long long>& ls);

int chooseBestSum(int t, int k, std::vector<int>& ls);