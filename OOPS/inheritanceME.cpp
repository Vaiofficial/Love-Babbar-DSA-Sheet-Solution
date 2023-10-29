#include <bits/stdc++.h>
using namespace std;

// parent/base/super class.
class dogs
{

public:
    void bark()
    {
        cout << "he is barking" << endl;
    }
    void legs()
    {
        cout << "he has four legs" << endl;
    }
    void tail()
    {
        cout << " he has one tail" << endl;
    }
};

class lebra : public dogs
{
public:
    void size()
    {
        cout << "lebra dogs are bigger in size" << endl;
    }
};

class german : public dogs
{
public:
    void aggressive()
    {
        cout << "german sephards are aggresive in nature" << endl;
    }
};

int main()
{
    dogs obj1;
    obj1.bark();
    obj1.legs();
    obj1.tail();
    cout << endl;
    lebra obj2;
    obj2.bark();
    obj2.legs();
    obj2.tail();
    obj2.size();
    cout << endl;
    german obj3;
    obj3.bark();
    obj3.legs();
    obj3.tail();
    obj3.aggressive();
    return 0;
}