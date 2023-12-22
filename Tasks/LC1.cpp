#include "LC1.h"

void leet1()
{

    // переставить числа в порядке, на которые указывают значения
    // std::vector<int> temp = buildArrayPermutation({0,2,1,5,3,4});
    // for(auto i : temp)
    //     std::cout << i << " ";

    // дан вектор значений, это изменение значения от 0. найти максимальное значение которое было.
    // std::cout << largestAltitudeGet({-5,1,5,0,-7});

    // отразить матрицу по горизонтали
    // std::vector<std::vector<int>> inpput = {{1,1,0},{1,0,1},{0,0,0}};
    // std::vector<std::vector<int>> temp = flipAndInvertImage(inpput);
    // for(auto i : temp)
    // {
    //     for(auto j : i)
    //         std::cout << j << " ";
    //     std::cout << std::endl;
    // }

    // найти сколько индексов совпадает у первого массива и сколько совпадает у второго массива
    // std::vector<int> temp = findIntersectionValues({4,3,2,3,1},{2,2,5,2,3,6});
    // for(auto i : temp)
    //     std::cout << i << " ";

    // найти первый полиндром в векторе
    //std::string temp = firstPalindrome("eget","ada","cool");
    // std::cout << temp;

    // найти сумму уникальных значений
    // int sum = sumOfUniqueElem({1,2,3,4,5,5});
    // std::cout << sum;

    // найти за O(n) единственное уникальное число в массиве, остальные встречаются 2 раза.
    std::cout << singleNumberInVec({2,2,1});

}   

int singleNumberInVec(std::vector<int> nums)
{
    int res = 0;

    for(auto i : nums)
    {
        // XOR.  0 ^ 4 = 4;   0 ^ 4 ^ 4 = 0;   0 ^ 4 ^ 4 ^ 5 = 5;
        res = res ^ i;
    }

    return res;

}

int sumOfUniqueElem(std::vector<int> nums)
{
    int sum = 0;

    for(int i = 0; i < nums.size(); i++)
    {
        if(std::count(nums.begin(), nums.end(),nums[i]) == 1)
        sum += nums[i];
    }

    return sum;
}

std::string firstPalindrome(std::vector<std::string>& words)
{
    for(auto i : words)
    {
        int len = i.length();
        bool res = true;

        for(int j = 0; j < len / 2; j++)
        {
            if(i[j] != i[len - j - 1])
            {
                res = false;
                break;
            }
        }

        if(res == true)
        return i;
    }

    return "";
}

std::vector<int> findIntersectionValues(std::vector<int> nums1, std::vector<int> nums2)
{

    int first = 0;
    int second = 0;

    for(auto i : nums1)
    {
        if(std::find(begin(nums2), end(nums2), i) != end(nums2))
        first ++;
    }
    for(auto i : nums2)
    {
        if(std::find(begin(nums1), end(nums1), i) != end(nums1))
        second ++;
    }

    return {first,second};
}

std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>> &image)
{
    // улучшенный алгоритм. скорость выполнения больше а затраты памяти меньше.
    for(auto &i : image)
    {  
        int iterators = i.size() - 1;
        int max = i.size() / 2;
        for(int j = 0; j < i.size(); j++)
        {
            if(iterators >= max)
            {
                std::swap(i[j],i[iterators]);
                iterators --;
            }

            if(i[j] == 0)
                i[j] = 1;
            else
                i[j] = 0;
        }
    }

    return image;
}

int largestAltitudeGet(std::vector<int> gain)
{
    int res = 0;
    int cur = 0;
    for(auto i : gain)
    {
        cur = cur + i;
        if(cur > res)
        res = cur;
    }
    return res;
}

std::vector<int> buildArrayPermutation(std::vector<int> nums)
{
    std::vector<int> ans;
    ans.reserve(nums.size());
    
    for(int i = 0; i < nums.size(); i++)
    {
        ans.push_back(nums[nums[i]]);
    }
    
    return ans;
}

