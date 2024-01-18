#include <iostream>
#include <vector>
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