#include <iostream>
#define M 15

using namespace std;

struct Node
{
	int data;
	Node* next;
};

bool empty(Node* pHead)
{
	return pHead == NULL;
}

int sizeList(Node* pHead)
{
	int cnt = 0;
	while(pHead != NULL)
	{
		cnt++;
		pHead = pHead -> next;
	}
	return cnt;
}

Node* createNode(int x)
{
	Node* tmp = new Node;
	tmp -> data = x;
	tmp -> next = NULL;
	return tmp;
}

int HashFuction(int x) 
{
	return x % M;	
}

void init(Node *bucket[]) 
{
	for (int i = 0; i < M; i++) 
		bucket[i] = NULL;
}

void insertNode(Node *bucket[], int x) 
{
	int idx = HashFuction(x);
	Node *tmp = createNode(x);

	if (bucket[idx] == NULL) 
		bucket[idx] = tmp;
	else
	{
		tmp -> next = bucket[idx];
		bucket[idx] = tmp;
	}
}

bool search(int a[], int n, int x)
{
	return a[x%n] == x;
}

void printList(Node* bucket[])
{
	for(int i = 0; i < M; i++)
	{
		Node* p = bucket[i];
		cout << i << ": ";
		while(p != NULL)
		{
			cout << p -> data << ' ';
			p = p -> next;	
		}
		cout << endl;
	}
}

int main() 
{
	int n, x;
	Node* Table[M];

	init(Table);
	cin >> n;
    for(int i = 0; i < n; i++)
	{
		cin >> x;
		insertNode(Table, x);
	}

	printList(Table);
	return 0;
}

