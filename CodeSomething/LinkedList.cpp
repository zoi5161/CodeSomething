#include <iostream>

using namespace std ;

// Node
struct Node
{
    int data;
    Node *next;
};

typedef struct Node* node;

// Make Node
node makeNode(int x)
{
    node tmp = new Node();
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}

// Empty
bool empty(node a)
{
    return a == NULL;
}

// Size
int Size(node a)
{
    int cnt = 0;
    while(a != NULL)
    {
        cnt++;
        a = a->next;
    }
    return cnt;
}

// Insert First
void insertFirst(node &a, int x)
{
    node tmp = makeNode(x);
    if(a == NULL)
        a = tmp;
    else
    {
        tmp->next = a;
        a = tmp;
    }
}

// Insert Last
void insertLast(node &a, int x)
{
    node tmp = makeNode(x);
    if(a == NULL)
        a = tmp;
    else
    {
        node p = a;
        while(p->next != NULL)
            p = p->next;
        p->next = tmp;
    }
}

// Insert Middle
void insertMiddle(node &a, int x, int pos)
{
    int n = Size(a);
    if(pos < 1 || pos > n + 1)
        cout << "Error" << endl;
    else if(pos == 1)
        insertFirst(a, x);
    else if(pos == n + 1)
        insertLast(a, x);
    else 
    {
        node p = a;
        for(int i = 1; i < pos - 1; i++)
            p = p->next;
        node tmp = makeNode(x);
        tmp->next = p->next;
        p->next = tmp;
    }
}

// Delete First
void deleteFirst(node &a)
{
    if(a == NULL)
        return;
    a = a->next;
}


// Delete Last
void deleteLast(node &a)
{
    int n = Size(a);

    if(n == 1)
    {
        delete a; 
        a = NULL;
        return;
    }

    if(a == NULL)
        return;

    node p = a;
    for(int i = 1; i < n - 1; i++)
        p = p->next;
    p->next = NULL;
}

// Delete Middle
void deleteMiddle(node &a, int pos)
{
    int n = Size(a);
    if(pos < 1 || pos > n )
        cout << "Error" << endl;
    else 
    {
        node pFront = NULL, pBehind = a;
        for(int i = 1; i < pos; i++)
        {
            pFront = pBehind;
            pBehind = pBehind -> next;
        }
        if(pFront == NULL)
            deleteFirst(a);
        else
            pFront -> next = pBehind -> next;
    }
}

void print(node a)
{
    while(a != NULL)
    {
        cout << a -> data << ' ';
        a = a -> next;
    }
    cout << endl;
}

int main()
{
    node head = NULL;
	for(int i = 0; i < 8; i++)
		insertLast(head, i);
	
	print(head);
	
	deleteLast(head);
	print(head);
    return 0;
}