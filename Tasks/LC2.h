#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
#include <bitset>
#include <set>

void leet2();

class TreeNode 
{
public:
    void addNode(int val);
    int val;
    bool TreeNull = false;
    TreeNode *left;
    TreeNode *right;
};

bool checkTree(TreeNode* root);
int sumTree(TreeNode* node);

std::vector<int> getAllElements(TreeNode* root1, TreeNode* root2);
void NodeToList(std::list<int> &curList, TreeNode *curNode);

std::vector<int> largestValues(TreeNode* root);
bool isSameTree(TreeNode* p, TreeNode* q);

int arithmeticTriplets(std::vector<int> &nums, int diff);