#include <bits/stdc++.h>
using namespace std;

void merge(int arr[] , int s , int e)
{
    int mid = (s+e)/2;

    int lenleft = mid - s+1;
    int lenright = e - mid;

    //create left and right array ddynamically

    int *left = new int[lenleft];
    int *right = new int[lenright];

    //copy elements from original array to left array
    int k = s;
    for (int i = 0; i < lenleft; i++)
    {
        left[i] = arr[k];
        k++;
    }
    //copy elements from original array to right array.
    k = mid+1;
    for (int i = 0; i < lenright; i++)
    {
        right[i] = arr[k];
        k++;
    }

    //now actual merging take place here.
    int leftindex = 0;
    int rightindex = 0;
    int mainindex = s;

    while (leftindex<lenleft && rightindex<lenright)
    {
        if(left[leftindex] < right[rightindex] ) {

			arr[mainindex] =  left[leftindex];
			mainindex++;
			leftindex++;
		}
		else {
			arr[mainindex] =  right[rightindex];
			mainindex++;
			rightindex++;
		}
    }

    //extra two cases , we need to take care of.
    //agar right array khatam hogya and left array abhi bhi bcha hua hai tab

    while (leftindex < lenleft)
{
    arr[mainindex] = left[leftindex];
    leftindex++;
    mainindex++;
}
while (rightindex < lenright)
{
    arr[mainindex] = right[rightindex];
    mainindex++;
    rightindex++;
}
 
    
    //at the end we need to free up heap 

    delete[] left;
    delete[] right;
    
}

void mergeSort(int arr[] , int s , int e)
{

    if(s>=e)
    {
        return;
    }
    int mid = (s+e)/2;

    //calling left side array
    mergeSort(arr ,s , mid);
    //calling right side array
    mergeSort(arr , mid+1 , e);
    //merging both the array
    merge(arr , s , e);
}

int main()
{
   int arr[] = {12,32,11,5,34};
   int size = 5;
   int s = 0;
   int e = size-1;


   cout<<"Before applying merge sort"<<endl;
   for (int i = 0; i < size; i++)
   {
    cout<<arr[i]<<" ";
   }
    cout<<endl;

   mergeSort(arr , s , e);

   cout<<"After applying merge sort"<<endl;
   for (int i = 0; i < size; i++)
   {
    cout<<arr[i]<<" ";
   }
   
   
   return 0;
}