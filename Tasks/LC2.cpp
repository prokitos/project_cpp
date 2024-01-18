#include "LC2.h"

void leet2()
{

    // проверить что сумма узлов равняется корню.
    TreeNode *node = new TreeNode;  
    node->addNode(10);
    node->addNode(6);
    node->addNode(3);
    node->addNode(1);
    std::cout << checkTree(node);




};

void TreeNode::addNode(int val)
{
    if(TreeNull == false)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;        
        TreeNull = true;
        return;
    }

    TreeNode* element = new TreeNode;
    element->val = val;
    element->left = NULL;
    element->right = NULL;

    TreeNode* temp = this;

    while(true)
    {
        if(val > temp->val)
        {
            if(temp->right == NULL)
            {
                temp->right = element;
                return;
            }
            else
            {
                temp = temp->right;
            }
        }
        else
        {
            if(temp->left == NULL)
            {
                temp->left = element;
                return;
            }
            else
            {
                temp = temp->left;
            }
        }
    }

}

bool checkTree(TreeNode* root)
{
    int first = root->val;
    int second = sumTree(root) - first;

    if(second == first)
    return true;
    else
    return false;
};

int sumTree(TreeNode* node)
{
    int sum = node->val;

    if(node->left != NULL)
    sum += sumTree(node->left);

    if(node->right != NULL)
    sum += sumTree(node->right);

    return sum;
};