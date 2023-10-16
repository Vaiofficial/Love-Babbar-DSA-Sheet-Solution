#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 10;
    char c = 'k';
    long lt = 54343;
    int *ptr = &a;
    char *ch = &c;
    long *machi = &lt;

    cout << "value of a  :" << a << endl;
    cout << "address of a:" << &a << endl;
    cout << "ptr is :" << ptr << endl;
    cout << "*ptr is :" << *ptr << endl;
    cout << "&ptr is :" << &ptr << endl;
    cout << "size of ptr :" << sizeof(ptr) << endl;
    cout << "size of lt :" << sizeof(lt) << endl;
    cout << "size of ch :" << sizeof(ch) << endl;

    return 0;
}