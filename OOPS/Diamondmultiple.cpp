#include <bits/stdc++.h>
using namespace std;

class person
{
public:
    void walk()
    {
        cout << "walking" << endl;
    }
};
class teacher : virtual public person // twalk()
{
public:
    void teach()
    {
        cout << "teaching" << endl;
    }
};
class researcher : virtual public person // rwalk()
{
public:
    void research()
    {
        cout << "researching" << endl;
    }
};

class professor : public researcher, public teacher
{
public:
    void bore()
    {
        cout << "boring" << endl;
    }
};

int main()
{
    person obj1;
    obj1.walk();
    cout << endl;
    teacher obj2;
    obj1.walk();
    obj2.teach();
    cout << endl;
    researcher obj3;
    obj3.walk();
    obj3.research();
    cout << endl;
    professor obj4;
    // we will get an error that is :  request for member 'walk' is ambiguous.
    // obj4.walk(); // 1 .scope resolution 2 . using virtual.

    // 1. This is how we can inherit walk using scope resolution
    // obj4.teacher::walk();
    // obj4.researcher::walk();
    obj4.walk();
    obj4.research();
    obj4.teach();
    return 0;
}