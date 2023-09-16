#include <bits/stdc++.h>
using namespace std;

// SABHI ELEMENTS KO UNKE RESPECTIVE INDEX PAR BHEJ RHE HAI AUR PHIR CHECK KAR RHE HAI AISA KAUN SA INDEX HAI JHA USKI CORRESPONDING VALUE NAHI AAYI HAI
// JHA NAHI AAYI HAI US INDEX KO i+1 RETURN KAR DENGE KYUKI , Elements 1-N hai AND INDEX 0 - N HAI.

void missingElement(int arr[], int n)
{
    int i = 0;
    while (i < n)
    {
        int index = arr[i] - 1;
        if (arr[i] != arr[index])
        {
            swap(arr[i], arr[index]);
        }
        else
        {
            ++i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
        {
            cout << i + 1 << " ";
        }
    }
}

int main()
{
    int arr[] = {1, 3, 5, 3, 3};
    int n = 5;

    missingElement(arr, n);

    return 0;
}