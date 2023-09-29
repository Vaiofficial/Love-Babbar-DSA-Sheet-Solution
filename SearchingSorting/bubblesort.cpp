#include <bits/stdc++.h>
using namespace std;

//  vector<int> bubbleSort(vector<int>& nums) {
        
//         for(int i=0;i<nums.size()-1;i++)
//         {
//             for(int j=0;j<nums.size()-i-1;j++)
//             {
//                 if(nums[j]>nums[j+1])
//                 swap(nums[j], nums[j+1]);
//             }
//         }

//         return nums;
//     } 

    //  vector<int> selectionSort(vector<int>& nums) {
        
    //     for(int i=0;i<nums.size()-1;i++)
    //     {
    //         int minIndex = i;
    //         for(int j=i+1;j<nums.size();j++)
    //         {
    //             if(nums[j]>nums[minIndex]);
    //             minIndex = j;
    //         }
    //         swap(nums[i], nums[minIndex]);
    //     }

    //     return nums;
    // } 

    vector<int>insertionSort(vector<int>& nums)
    {
        for (int i = 1; i < nums.size();i++)
        {
            int key = nums[i];
            int j = i-1;

            while(j>=0 && key<nums[j])
            {
                nums[j+1] = nums[j];
                j--;
            }
            nums[j+1] = key;  // j phle out of bond ho jyga so +1 karke uske 0th index par laye aur vha minimum element put kiye hai.
        }

        return nums;
        
    }

int main()
{
    vector<int>array{44,33,55,22,11};

    // vector<int>nums = bubbleSort(array);
    // vector<int>values = selectionSort(array);

    vector<int>value = insertionSort(array);

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     cout<<nums[i]<<" ";
    // }

    cout<<endl;

    // for (int i = 0; i < values.size(); i++)
    // {
    //     cout<<values[i]<<" ";
    // }
    

    for (int i = 0; i < value.size(); i++)
    {
        cout<<value[i]<<" ";
    }
    
   return 0;
}