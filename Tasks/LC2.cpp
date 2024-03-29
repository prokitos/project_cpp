#include "LC2.h"

void leet2()
{

    // проверить что сумма узлов равняется корню.
    // TreeNode *node = new TreeNode;  
    // node->addNode(10);
    // node->addNode(6);
    // node->addNode(3);
    // node->addNode(1);
    // std::cout << checkTree(node);


    // даны два бинарных дерева. вернуть вектор отсортированный с самого маленького до самого большого элемента.
    // TreeNode *tree1 = new TreeNode;  
    // tree1->addNode(2);
    // tree1->addNode(1);
    // tree1->addNode(4);
    // TreeNode *tree2 = new TreeNode;  
    // tree2->addNode(1);
    // tree2->addNode(0);
    // tree2->addNode(3);
    // std::vector<int> temp = getAllElements(tree1,tree2);
    // for(auto i : temp)
    // std::cout << i << " ";

    // найти самое большее значение в каждой строке дерева.
    // TreeNode *tree1 = new TreeNode;  
    // tree1->addNode(3);
    // tree1->addNode(1);
    // tree1->addNode(4);
    // tree1->addNode(2);
    // tree1->addNode(7);
    // std::vector<int> temp = largestValues(tree1);
    // for(auto i : temp)
    // std::cout << i << " ";

    // проверить одинаковые ли деревья
    // TreeNode *tree1 = new TreeNode;  
    // tree1->addNode(2);
    // tree1->addNode(1);
    // tree1->addNode(4);
    // TreeNode *tree2 = new TreeNode;  
    // tree2->addNode(2);
    // tree2->addNode(1);
    // tree2->addNode(4);
    // std::cout << isSameTree(tree1, tree2);

    // дан вектор отсортированных цифр. найти сколько есть троек чисел, которые при вычитании дают число diff.
    std::vector<int> temp = {0,1,4,6,7,10};
    std::cout << arithmeticTriplets(temp,3); // (10 - 7 - 4) и (7 - 4 - 1) = 2 тройки

};

int arithmeticTriplets(std::vector<int> &nums, int diff)
{
    // // обычный способ, (n^2)
    // int res = 0;
    // // проходим по каждой цифре, и смотри есть ли после неё ещё 2, которые получаются при сложении с diff
    // for(int i = 0; i < nums.size(); i++)
    // {
    //     int temp = nums[i];
    //     int counter = 0;
    //     for(int j = i + 1; j < nums.size(); j++)
    //     {
    //         // если нашли вхождение, то заменяем стартовое число поиска, и говорим что на 1 вхождение больше
    //         if(nums[j] - temp == diff)
    //         {
    //             temp = nums[j];
    //             counter ++;
    //         }
    //         // если вхождения два, то значит прибавляем + 1 к результату, так как после числа i есть 2 числа с промежутком diff
    //         if(counter == 2)
    //         {
    //             res ++;
    //             break;
    //         }
    //     }
    // }
    // return res;


    // // через map, (2n)
    int res = 0;
    int last = nums.back();
    std::map<int,int> dictionary;

    // заполняем словать числами из вектора, и даем им значение 1
    for(auto i : nums)
    {
        dictionary[i] = 1;
    }

    // берем каждое число из вектора, и смотрим есть ли в словаре через diff и через diff + diff значения. если есть, значит такие числа существуют, и результат + 1
    for(auto i : nums)
    {
        if(dictionary[i + diff] > 0 && dictionary[i + diff + diff] > 0)
        {
            res ++;
        }
    }

    return res;
}

bool checkNodeSame(TreeNode* node1, TreeNode* node2)
{
    bool temp = true;

    if(node1 == NULL && node2 == NULL)
    return true;
    if(node1 == NULL || node2 == NULL)
    return false;
    if(node1->val != node2->val)
    return false;

    temp = checkNodeSame(node1->left,node2->left);
    if(temp == false)
    return false;
    
    temp = checkNodeSame(node1->right,node2->right);
    if(temp == false)
    return false;

    return true;
}

bool isSameTree(TreeNode* p, TreeNode* q)
{
    return checkNodeSame(p,q);
}

void addMaxDepth(std::vector<int> &curVec, TreeNode* curNode, int depth)
{
    if(curNode == NULL)
    return;

    // если ещё не было элемента на этой глубине, то добавляем
    if(depth >= curVec.size())
        curVec.push_back(curNode->val);
    // иначе сравниваем каждое значение ноды на этой глубине с значениев в векторе, и перезаписываем если больше
    else
        curVec[depth] = std::max(curVec[depth],curNode->val);

    addMaxDepth(curVec,curNode->left,depth + 1);
    addMaxDepth(curVec,curNode->right, depth + 1);
}

std::vector<int> largestValues(TreeNode* root)
{
    std::vector<int> result;
    addMaxDepth(result,root,0);

    return result;
}

void NodeToList(std::list<int> &curList, TreeNode *curNode)
{
    // заходим в левый узел
    if(curNode->left != NULL)
    NodeToList(curList, curNode->left);

    // добавляем текущий элемент
    curList.push_back(curNode->val);

    // заходим в правый узел
    if(curNode->right != NULL)
    NodeToList(curList, curNode->right);
}

std::vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
{
    std::list<int> firstList,secondList;
    std::vector<int> result;

    // добавляем в первый и во второй лист зачения из деревьев
    NodeToList(firstList,root1);
    NodeToList(secondList,root2);

    // добавляем по очереди значения в вектор.
    int maxSize = firstList.size() + secondList.size();
    result.reserve(maxSize);
    for(int i = 0; i < maxSize; i ++)
    {  
        // если первый лист закончился, то берем из второго листа
        if(firstList.size() == 0)
        {
            result.push_back(secondList.front());
            secondList.pop_front();
            continue;
        }
        // если второй лист закончился, то берем из первого листа
        if(secondList.size() == 0)
        {
            result.push_back(firstList.front());
            firstList.pop_front();
            continue;
        }

        // если значение в первом листе меньше, то берем из него,иначе берем из второго
        if(firstList.front() < secondList.front())
        {
            result.push_back(firstList.front());
            firstList.pop_front();
        }
        else
        {
            result.push_back(secondList.front());
            secondList.pop_front();
        }
    }

    return result;
}

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