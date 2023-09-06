#include <bits/stdc++.h>
using namespace std;

// int greaterOfThree(int num1, int num2, int num3)
// {
//     if (num1 >= num2 && num1 >= num3)
//     {
//         cout << "Maximum Number is :" << num1 << endl;
//     }
//     else if (num2 >= num1 && num2 >= num3)
//     {
//         cout << "Maximum Number is :" << num2 << endl;
//     }
//     else
//     {
//         cout << "Maximum Number is :" << num3 << endl;
//     } 
// }

int greaterOfThree(int num1 , int num2 , int num3)
{
    int num = max(num1 , num2);
    int ans = max(num , num3);

    return ans;
}

int main()
{
    int a;
    int b;
    int c;

    cout << "Enter Three Numbers" << endl;
    cin >> a;
    cin >> b;
    cin >> c;

    cout<<"The Greater Number is : "<<greaterOfThree(a, b, c);

    return 0;
}