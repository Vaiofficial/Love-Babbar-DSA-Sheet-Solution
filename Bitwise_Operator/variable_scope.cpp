// why gloabl variable defination is considered as the bad practice

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num = 34;
    string name = "Vaibhav";

    if(name=="Vaibhav")
    {
        num = 56;
        cout<<num<<endl;
    }

    cout <<num<<endl;
    cout<<num;

    return 0;
}