#include <bits/stdc++.h>
using namespace std;

int main()
{
   int arr[6] = {1,2,3,4,5,6};
   int target = 9;
   bool flag = 0; //not found(false)

//    for (int i = 0; i < 6; i++)
//    {
//         if(target == arr[i])
//         cout<<target<<" "<<"found at index"<<" "<<i;
//         break;
//    }

    for (int i = 0; i < 6; i++)
    {
        if(arr[i]==target)
        {
            flag = 1; //element found(true)
            break;
        }
    }

    if(flag==1)
    cout<<"element is found"<<endl;

    else{
        cout<<"element is not found"<<endl;
    }
    
   
   return 0;
}