#include <bits/stdc++.h>
using namespace std;

bool DisplayPrime(int num)
{
    // int i = 2;

    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int num;

    cout << "Enter the Number :";
    cin >> num;

    for (int i = 2; i <= num; i++)
    {
        bool isPrime = DisplayPrime(i);

        if (isPrime)
        {
            cout << i << " ";
        }
    }
}