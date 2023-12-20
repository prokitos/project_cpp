#include "LC1.h"

void leet1()
{

    std::vector<int> temp = buildArrayPermutation({0,2,1,5,3,4});
    for(auto i : temp)
        std::cout << i << " ";

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