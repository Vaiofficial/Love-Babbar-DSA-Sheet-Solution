#include <bits/stdc++.h>
using namespace std;

void solve(int *arr, int size)
{
    int sizearr = sizeof(arr);
    cout<<*arr+1<<endl;
    cout << "size of arr inside the solve function:-" << sizearr << endl;
    cout << "printing arr inside solve function:-" << arr << endl;
    cout << "printing &arr inside solve function:-" << &arr << endl;

}

    int main()
    {
        int arr[] = {1, 2, 3};
        int size = sizeof(arr);
        cout << "size of arr inside main function:-" << size << endl;
        cout << "printing arr inside main:-" << arr << endl;
        cout << "printing &arr inside main:-" << &arr << endl;
        cout << endl;

        solve(arr, size);
        return 0;
    }