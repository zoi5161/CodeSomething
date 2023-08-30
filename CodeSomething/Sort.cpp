#include <iostream>
#include <cstdlib>
#include <queue>
#include <cmath>

using namespace std;

// Support Function
void Print(string s, int a[], int n)
{
    cout << s;
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl << endl;
}

void Random(int a[], int n)
{
    cout << "Input: ";
    for(int i = 0; i < n; i++)
    {
        a[i] = rand()%20+1;
        cout << a[i] << ' ';
    }
    cout << endl;
}

// Sort Function
// Bubble Sort
void BubbleSort(int a[], int n)
{
    for(int i = 1; i < n - 1; i++)
        for(int j = n - 1; j >= i; j--)
            if(a[j] < a[j-1])
                swap(a[j], a[j-1]);
}

// Insertion Sort
void InsertionSort(int a[], int n)
{
    int j, val;
    for(int i = 1; i < n; i++)
    {
        j = i - 1;
        val = a[i];
        while(j >= 0 && a[j] > val) //*
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = val;
    }
}

// Selection Sort
void SelectionSort(int a[], int n)
{
    int idx, val;
    for(int i = 0; i < n - 1; i++)
    {
        idx = i; 
        val = a[i];
        for(int j = i + 1; j < n; j++)
            if(a[j] < val)
            {
                idx = j;
                val = a[j];
            }
        swap(a[i], a[idx]);
    }
}

// Interchange Sort
void InterchangeSort(int a[], int n)
{
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if(a[i] > a[j])
                swap(a[i], a[j]);
}

// Shaker Sort
void ShakerSort(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n - 1; j++)
            if(a[j] > a[j+1])
                swap(a[j], a[j+1]);
        n--;
        
        for(int j = n - 1; j > 0; j--)
            if(a[j] < a[j-1])
                swap(a[j], a[j-1]);
        i++;
    }
}

// Heap Sort
void Heapify(int a[], int n, int i) //*
{
    int l = 2*i + 1, r = 2*i + 2, largest = i;
    if(l < n && a[l] > a[largest])
        largest = l;
    if(r < n && a[r] > a[largest])
        largest = r;
    if(largest != i)
    {
        swap(a[i], a[largest]);
        Heapify(a, n, largest);
    }
}

void HeapSort(int a[], int n)
{
    for(int i = (n-1)/2; i >= 0; i--)
        Heapify(a, n, i); 
    
    for(int i = n-1; i >= 1; i--)
    {
        swap(a[0], a[i]);
        Heapify(a, i, 0); //*
    }
}

// Quick Sort
void QuickSort(int a[], int l, int r)
{
    int i = l, j = r, pilot = (r+l)/2;
    while(i <= j)
    {
        while(a[i] < a[pilot])
            i++;
        while(a[j] > a[pilot])
            j--;
        if(i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if(i < r)
        QuickSort(a, i, r);
    if(j > l)
        QuickSort(a, l, j);
}

// Merge Sort
void Merge(int a[], int l, int r, int m)
{
    int n1 = m, n2 = r - m + 1, i = 0, j = 0;
    int b[n1], c[n2];

    for(int i = 0; i < n1; i++)
        b[i] = a[i];
    for(int i = 0; i < n2; i++)
        c[i] = a[i + n1];

    while(i < n1 && j < n2)
    {
        if(b[i] < c[j])
        {
            a[i+j] = b[i];
            i++;
        }
        else
        {
            a[i+j] = c[j];
            j++;
        }
    }

    while(i < n1)
    {
        a[i+n2] = b[i];
        i++;
    }

    while(j < n2)
    {
        a[j+n1] = c[j];
        j++;
    }
}

void MergeSort(int a[], int l, int r)
{
    if(l < r)
    {
        int m = l + (r-l)/2; //*
        MergeSort(a, l, m);
        MergeSort(a, m+1, r);
        Merge(a, l, r, m);
    }
}

// Radix Sort
int GetMax(int a[], int n)
{
    int mx = a[0];
    for(int i = 1; i < n; i++)
        if(a[i] > mx)
            mx = a[i];
    return log10(mx)+1;
}

int GetNum(int a, int mx, int x)
{
    int tmp = 0, k = mx - x + 1;
    while(k > 0)
    {
        tmp = a % 10;
        a /= 10;
        k--;
    }
    return tmp;
}

void RadixSort(int a[], int n)
{
    int d = GetMax(a, n), mx = d, cnt;
    queue <int> b[10];
    while(d > 0)
    {
        for(int i = 0; i < n; i++)
            b[GetNum(a[i], mx, d)].push(a[i]);
        
        cnt = 0;
        for(int i = 0; i < 10; i++)
            while(!b[i].empty())
            {
                a[cnt++] = b[i].front();
                b[i].pop();
            }
        d--;
    }
}

// Search Function
// Linear Search
void PrintSearch(string s, bool check)
{
    cout << s;
    if(check)
        cout << "True" << endl;
    else
        cout << "False" << endl;
}

bool LinearSearch(int a[], int n, int x)
{
    for(int i = 0; i < n; i++)
        if(a[i] == x)
            return true;
    return false;
}

bool BinarySearch(int a[], int n, int x)
{
    int l = 0, r = n - 1, m;
    while(l <= r)
    {
        m = (l+r)/2;
        if(a[m] > x)
            r = m - 1;
        else if(a[m] < x)
            l = m + 1;
        else 
            return true;
    }
    return false;
}

int main()
{
    srand(time(0));
    int n;
    int a[100];

    cout << "Enter the number of elements: ";
    cin >> n;

    Random(a, n);
    BubbleSort(a, n);
    Print("Bubble sort: ", a, n);

    Random(a, n);
    InsertionSort(a, n);
    Print("Insertion sort: ", a, n);

    Random(a, n);
    SelectionSort(a, n);
    Print("Selection sort: ", a, n);

    Random(a, n);
    InterchangeSort(a, n);
    Print("Interchange sort: ", a, n);

    Random(a, n);
    ShakerSort(a, n);
    Print("Shaker sort: ", a, n);

    Random(a, n);
    HeapSort(a, n);
    Print("Heap sort: ", a, n);

    Random(a, n);
    QuickSort(a, 0, n); //*
    Print("Quick sort: ", a, n);

    Random(a, n);
    MergeSort(a, 0, n-1); //*
    Print("Merge sort: ", a, n);

    Random(a, n);
    RadixSort(a, n);
    Print("Radix sort: ", a, n);
    return 0;
}