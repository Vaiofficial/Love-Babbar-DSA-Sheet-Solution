#include <bits/stdc++.h>
using namespace std;

void subsequence(string str, string output, int index)
{
    if(index>=str.size())
    {
        cout<<output<<endl;
        return;
    }

    //include
    output.push_back(str[index]);
    subsequence(str , output , index+1);

    output.pop_back();
    subsequence(str , output , index+1);

}

int main()
{
    string str = "abc";
    string output;
    int index = 0;

    subsequence(str, output, index);

    return 0;
}