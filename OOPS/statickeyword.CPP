#include <bits/stdc++.h>
using namespace std;

class abc{
    public:
    static int x , y;
    void testing()
    {
        cout<<"The value of x is :"<<x<<"and the value of y is : "<<y<<endl;
    } 
};

int abc :: x;
int abc :: y;

int main()
{
    //creating a object of the class abc 
    abc obj1;
    abc obj2;

    obj1.x = 20;
    obj1.y = 40;
    obj2.x = 60;//so yaha ye obj2 ka x and y pass nahi hoga because hum static keyword use kiye hai so sabbhi object k liye same members pass honge.
    obj2.y = 30;

    obj1.testing();
    obj2.testing();
   
   return 0;
}