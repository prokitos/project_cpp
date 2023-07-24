#include <memory>
#include <span>
#include <vector>
#include <any>
#include <algorithm>
#include <cstring>
#include <iostream>

using std::cout;
using std::string;

void consoleClear()
{

    for (short i = 0; i < 10; i++)
    {
        cout << "\t\n"; 
    }
    
}




void stringCheck(string str)
{
    bool checker = false;
    bool mass [256]{};

    for (short i = 0; i < str.length(); i++)
    {
        short curSymbol = str[i];
        if(mass[curSymbol] == false)
        {
            mass[curSymbol] = true;
        }
        else
        {
            checker = true;
        }
    }



    if(checker == true)
    {
        cout << "есть одинаковые символы";
    }
    else
    {
        cout << "нет одинаковых символов";
    }
}



struct node 
{
    int field;           // поле данных
    struct node* next;  // следующй элемент
};

class lList
{
    node* firstNode;
    node* lastNode;
public:
    lList()
    {
        firstNode = NULL;
        lastNode = NULL;
    };
    void insert(int d);
    void show(node* nod);
    void showAll();

};

void lList::insert(int d)
{
    node* tmp = new node;
    tmp->field = d;
    tmp->next = NULL;

    if(firstNode == NULL)
    {
        firstNode = tmp;
        lastNode = tmp;
    }
    else
    {
        lastNode->next = tmp;
        lastNode = tmp;
    }

};

void lList::show(node* nod)
{
    if(nod != NULL)
    {
        cout << nod->field << " ";
        show(nod->next);
    }
};

void lList::showAll()
{
    show(firstNode);
};














int main()
{
    consoleClear();

    //функция показывает есть ли повторения в строке
    //string stroka = "abvdera";
    //stringCheck(stroka);

    //связное дерево
    // lList linked;
    // linked.insert(5);
    // linked.insert(6);
    // linked.insert(1);
    // linked.insert(61);
    // linked.showAll();

    

    return 0;
}

