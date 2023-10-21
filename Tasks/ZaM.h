#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <forward_list>

void zaMainM();

std::string incrementString(const std::string &str);

std::string interpreter(const std::string &code, const std::string &tape);

std::string missing_alphabets(const std::string &s);

std::string range_extraction(std::vector<int> args);

std::string seriesSum(int n);

std::vector<unsigned int> removeSmallest(const std::vector<unsigned int>& numbers);

std::string autoMorphic (int number);

std::pair<int,int> findMostFrequent(std::forward_list<int> l);

bool solution(const std::vector<std::string>& words);

std::string sum_strings(const std::string& a, const std::string& b);

std::pair<std::string, std::string> capitalize(const std::string &s);

std::string encrypt(std::string text, int n);
std::string decrypt(std::string encryptedText, int n);