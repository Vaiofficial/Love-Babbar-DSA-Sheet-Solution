#include <bits/stdc++.h>
using namespace std;

bool validRedundant(string &str)
{
    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        char it = str[i];

        if (it == '(' || it == '+' || it == '-' || it == '/' || it == '*')
        {
            st.push(it);
        }
        else if (it == ')')
        {
            int operatorCount = 0;

            while (st.top() != '(' && !st.empty())
            {
                char temp = st.top();

                if (temp == '+' or temp == '-' or temp == '/' or temp == '*')
                {
                    operatorCount++;
                }
                st.pop();
            }
            // yaha mai tab pahuchunga jab stack ke top mai opening bracket hoga.
            st.pop();

            if (operatorCount == 0)
            {
                return true;
            }
        }
    }
    // agr mai yaha tak pahucha hu , mtlab har ak bracket ke bich mai operator mila hoga mtlb ye redundant nahi hai and return false kardo.
    return false;
}

int main()
{
    string str = "((a+b)*(c+d))";

    bool ans = validRedundant(str);

    if (ans == true)
    {
        cout << "redundant" << endl;
    }
    else
    {
        cout << "not redundant" << endl;
    }

    return 0;
}