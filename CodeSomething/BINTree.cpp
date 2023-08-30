#include <iostream>

using namespace std;

struct NODE
{
    int data;
    NODE* pLeft;
    NODE* pRight;
};

typedef struct NODE* Node;

struct Tree
{
    int Count;
    Node pRoot;
};

Node CreateNode(int x)
{
    Node tmp = new NODE;
    tmp -> data = x;
    tmp -> pLeft = nullptr;
    tmp -> pRight = nullptr;
    return tmp;
}

void InitBinaryTree(Tree &Bin)
{
    Bin.Count = 0;
    Bin.pRoot = CreateNode(0);

    Node n1 = CreateNode(1);
    Node n2 = CreateNode(2);
    Node n3 = CreateNode(3);
    Node n4 = CreateNode(4);
    Node n5 = CreateNode(5);
    Node n6 = CreateNode(6);
    Node n7 = CreateNode(7);

    Bin.pRoot -> pLeft = n1;
    Bin.pRoot -> pRight = n2;

    n1 -> pLeft = n3;
    n1 -> pRight = n4;

    n2 -> pRight = n5;

    n4 -> pLeft = n6;
    n4 -> pRight = n7;

    Bin.Count = 7;
}

void NLR(Node pCur)
{
    if(pCur == nullptr)
        return;
    cout << pCur -> data << ' ';
    NLR(pCur -> pLeft);
    NLR(pCur -> pRight);
}

void LNR(Node pCur)
{
    if(pCur == nullptr)
        return;
    LNR(pCur -> pLeft);
    cout << pCur -> data << ' ';
    LNR(pCur -> pRight);
}

void LRN(Node pCur)
{
    if(pCur == nullptr)
        return;
    LRN(pCur -> pLeft);
    LRN(pCur -> pRight);
    cout << pCur -> data << ' ';
}

bool Insert(Node &pCur, int x)
{
    if(pCur == nullptr)
    {
        pCur = CreateNode(x);
        return true;
    }
    
    if(pCur -> data > x)
        return Insert(pCur -> pLeft, x);
    else if(pCur -> data < x)
        return Insert(pCur -> pRight, x);
    else return false;
}

bool Search(Node pCur, int x)
{
    if(pCur == NULL)
        return false;
    
    if(pCur -> data > x)
        return Search(pCur -> pLeft, x);
    else if(pCur -> data < x)
        return Search(pCur -> pRight, x);
    else 
        return true;
}

Node SearchStandFor(Node &p, Node pCur)
{
    if(p -> pRight != nullptr)
        return SearchStandFor(p -> pRight, pCur);
    
    pCur -> data = p -> data;
    Node tmp = p;
    p = p -> pLeft;
    return tmp;
}

bool Delete(Node &pCur, int x)
{
    if(pCur == NULL)
        return false;
    if(pCur -> data > x)
        return Delete(pCur -> pLeft, x);
    else if(pCur -> data < x)
        return Delete(pCur -> pRight, x);
    
    Node tmp = pCur;
    if(pCur -> pRight == nullptr)
        pCur = pCur -> pLeft;
    else if(pCur -> pLeft == nullptr)
        pCur = pCur -> pRight;
    else
        tmp = SearchStandFor(pCur -> pLeft, pCur);
    delete tmp;
    return true;
}

int main()
{
    Tree Bin;
    Bin.Count = 0;
    Bin.pRoot = NULL;

    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        if(Insert(Bin.pRoot, x))
            Bin.Count++;
    }
    cout << Bin.Count << endl;
    NLR(Bin.pRoot);
    cout << endl << endl;
    Delete(Bin.pRoot, 10);
    NLR(Bin.pRoot);
    return 0;
}

/* Binary Tree (Init)
                0
            1       2
         3     4       5
             6   7
*/

/* Binary Search Tree (N = 10): 10 5 15 3 12 7 9 18 2 4
                10
            5       15
          3   7   12  18
         2 4   9    
*/