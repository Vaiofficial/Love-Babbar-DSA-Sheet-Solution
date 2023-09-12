#include <bits/stdc++.h>
using namespace std;

bool findElement(int arr[][3] ,int row ,int  col ,int  target)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(target == arr[i][j])
            {
                return true;
            }
        }
        
    }

    return false;
    
}

int main()
{
   int arr[][3] = {{1,2,3},{4,5,6},{7,8,9}};
   int row = 3;
   int col = 3;
   int target = 69;

   int ans = findElement(arr , row , col , target);

   if(ans==1)
   {
    cout<<"element is present";
   }
   else{
    cout<<"element is not present";
   }

   return 0;
}