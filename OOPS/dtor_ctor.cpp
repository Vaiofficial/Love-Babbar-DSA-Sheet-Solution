#include <bits/stdc++.h>
using namespace std;

class lifecycle
{

public:
    int x;
    int *y;

    lifecycle(int _x, int _y) : x(_x), y(new int(_y)) {}

    void print()
    {
        cout << "the value of a and b is: " << x <<" & "<< *y << endl;
    }

    ~lifecycle()
    {
        delete y;
    }
};

int main()
{
    lifecycle obj1(5, 20);
    obj1.print();

    return 0;
}