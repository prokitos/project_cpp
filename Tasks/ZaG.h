#include <iostream>
#include <vector>
#include <map>
#include <list>

void zaMainG();

std::string rgb(int r, int g, int b);
std::string numberRgb(int num);

int digitSum(int chislo);
int digital_root(int n);

class PolNotationClass
{
public:
    PolNotationClass(){};
    void solveAll(std::string stroka);

private:
    std::string solveCurrent(std::string stroka);
};

bool valid_braces(std::string braces);
std::string correct_it(std::string str);
std::vector<int> deleteNth(std::vector<int> arr, int n);

template<typename Type>
std::vector<Type> uniqueInOrder(const std::vector<Type>& iterable);
std::vector<char> uniqueInOrder(const std::string& iterable);