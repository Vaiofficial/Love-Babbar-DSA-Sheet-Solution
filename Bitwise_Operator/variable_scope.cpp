// why gloabl variable defination is considered as the bad practice

#include <bits/stdc++.h>
using namespace std;

int num = 34;
int main()
{
    string name = "Vaibhav";

    if (name == "Vaibhav")
    {
        num = 56;
        cout << num << endl;
    }

    cout << num << endl;
    cout << num;

    return 0;
}