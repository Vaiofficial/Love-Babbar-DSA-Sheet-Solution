#include <bits/stdc++.h>
using namespace std;

class gettersetter
{

private: //we can access private as well as public member using getter and setter.
    int x;
    int *y;

public:
    gettersetter(int _x, int _y) : x(_x), y(new int(_y)) {}

    void print()
    {
        cout << "the value of x and y is : " << x << " & " << y << endl;
    }

    int getX()
    {
        return x;
    }

    void setX(int _valx)
    {
        x = _valx;
    }

    int getY()
    {
        return *y;
    }

    void setY(int _valy)
    {
        *y = _valy;
    }

    ~gettersetter() // deallocating memory from the heap which was allocated to the y member , just to avoid memory leak.
    {
        delete y;
    }
};

int main()
{
    // accessing private members using objects.
    //  gettersetter obj1; //agr humne constructor bna kar rkha hai to aise access nahi kar skte members ko , it need default constructor to do that.

    // obj1.x = 30;//not work , value in inaccessible error.

    // gettersetter obj1(30, 60);
    // obj1.print(); //here we are accessing it within the class , thats why here it is printed, As we know the print class is inside the class.

    // cout<<obj1.x; //here we are not able to access private members using constructor also.

    gettersetter obj1(0, 0);
    obj1.setX(40);
    obj1.setY(30);
    cout << "the value of x and y is :" << obj1.getX() << " & " << obj1.getY() << endl;

    return 0;
}