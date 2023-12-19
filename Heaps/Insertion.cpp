#include <bits/stdc++.h>
using namespace std;

class Heap
{

public:
    int *arr;
    int capacity;
    int size;

    Heap(int capacity)
    {
        this->arr = new int[capacity];
        this->capacity = capacity;
        this->size = 0;
    }

    void insert(int val)
    {
        if (size == capacity)
        {
            cout << "Heap Overflow" << endl;
            return;
        }

        // size increase hote jyega
        size++;
        int index = size;
        arr[index] = val;

        // value ko uske correct position par lekar jaarhe hai.
        while (index > 1)
        {
            int parentIndex = index / 2;
            if (arr[index] > arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    // printing the content of heap
    void printHeap()
    {
        for (int i = 1; i <= 5; i++)
        {
            cout << arr[i] << " ";
        }
    }

    int deleteFromHeap()
    {
        // jo top par element hai , jo ki delete hoga usko phle store kar liye hai.
        int answer = arr[1];
        // replacement
        arr[1] = arr[size];
        // last element ko delete uske original position se
        size--;
        // ab starting index se heapify karna hai
        int index = 1;

        while (index < size)
        {
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;

            // ab findout karna hai sabse bda kaun so phle largest root ko assume kiye hai.
            int largestIndex = index;

            if (leftIndex <= size && arr[largestIndex] < arr[leftIndex])
            {
                largestIndex = leftIndex;
            }
            if (rightIndex <= size && arr[largestIndex] < arr[rightIndex])
            {
                largestIndex = rightIndex;
            }
            // no change if dono hi equal hai.
            if (index == largestIndex)
            {
                break;
            }
            else
            {
                swap(arr[largestIndex], arr[index]);
                // ab jo nayi position aye , hum usko bhi dekhne nikle hai.
                index = largestIndex;
            }
        }
        return answer;
    }

    void heapify(int arr[], int n, int index)
    {
        int leftIndex = 2 * index;
        int rightIndex = 2 * index + 1;
        int largestIndex = index;

        // ab teeno mai se max find out

        if (leftIndex <= n && arr[leftIndex] > arr[largestIndex])
        {
            largestIndex = leftIndex;
        }

        if (rightIndex <= n && arr[rightIndex] > arr[largestIndex])
        {
            largestIndex = rightIndex;
        }
        /// dono condition ke baad largestIndex max value node ko point kar rha hoga.
        if (index != largestIndex)
        {
            swap(arr[index], arr[largestIndex]);
            index = largestIndex;
            heapify(arr, n, index);
        }
    }

    void BuildHeap(int arr[], int n)
    {
        // so simply hum n/2 se lekar 1 tak heapify kar rhe hai.
        for (int index = n / 2; index > 0; index--)
        {
            heapify(arr, n, index);
        }
    }

    void heapSort(int arr[], int n)
    {
        while (n != 1)
        {
            // yaha galti hoti hai , n-1 nahi karna h kyuki 1 based indexing hai.
            swap(arr[1], arr[n]);
            n--;
            // hamesaha first index pe aayga usko heapify karna hai so index hum 1 pass kiye hai.
            heapify(arr, n, 1);
        }
    }
};

int main()
{
    int n = 6;
    Heap h(n);
    int arr[] = {-1, 25, 20, 15, 5, 10, 12};
    h.BuildHeap(arr, n);

    cout << "Printing heap" << endl;
    for (int i = 1; i <= 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    h.heapSort(arr, n);

    cout << "Printing Heap"
         << " " << endl;
    for (int i = 1; i <= 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Heap h(20);
    // // insertioin
    // h.insert(10);
    // h.insert(20);
    // h.insert(5);
    // h.insert(11);
    // h.insert(6);

    // h.printHeap();

    // cout << endl;
    // int ans = h.deleteFromHeap();
    // cout << "the deleted element is :" << ans << endl;
    // h.printHeap();
}