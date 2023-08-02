#include <iostream>
#include <vector>
#include <map>


struct PeakData;
PeakData pick_peaks(const std::vector<int> &v);

class Mix
{
public:
  static std::string mix(const std::string &s1, const std::string &s2);
};

int countSmileys(std::vector<std::string> arr);

std::string disemvowel(const std::string& str);

std::string longest(const std::string &s1, const std::string &s2);

std::string format_duration(int seconds);
void zaMainD();
