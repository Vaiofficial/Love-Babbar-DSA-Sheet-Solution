#include <bits/stdc++.h>
using namespace std;

int findOddOccuring(int arr[] , int n)
{
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<=e)
    {

        if(s==e)
        return s;

        if(mid & 1) //means jo mera mid hai vo odd hai.
        {
            if(mid-1>=0 && arr[mid] == arr[mid-1]) //agr left side hai tab k liye
            {
                s = mid+1;
            }
            else{
                e = mid-1; //agr right side hai tb k liye.
            }
        }
        else{//jab mid even ho

            if(mid+1 <n && arr[mid]==arr[mid+1]) //left side k liye.
            {
                s= mid+2;
            }
            //right side k liye.
            else{
                e = mid; //peak in a mountain ka concept lga hai yaha,
            }
        }

        mid = s + (e-s)/2;
    }
    return -1;
}



int main()
{

    int arr[] ={10,10,2,2,3,3,4,4,5,5,6,6,7,7,9};
    int n = 15;

    int indexans = findOddOccuring(arr , n);

    cout<<"the odd occurence element is :"<<arr[indexans]<<endl;
   
   return 0;
}