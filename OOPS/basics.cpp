#include <bits/stdc++.h>
using namespace std;
class student
{
public:
//these are the variables of the classss.
    int attendance;
    int age;
    int marks;
    string name;
    char grade;

    student(int _attendance, int _age, int _marks, string _name, char _grade = 'A')//:(attendance)(_attendance) , (age)(_age) , (marks)(_marks),(name)(_name),(grade)(_grade)
    {
        attendance = _attendance;
        age = _age;
        marks = _marks;
        name = _name;
        grade = _grade;
    }

//here we have declared getter and setterrrr.
    int getAge()
    {
        return age;
    }

    void setAge(int _val) //const  - if we do this means our method became constant method , means we can not change the value anymore.
    {
        age = _val;
    }


//these are the methods of the class studentssss.
    void study()
    {
        cout << name << " study well" << endl;
    }

    void playing()
    {
        cout << "he is good in sports" << endl;
    }

    void score()
    {
        cout << name << " scores highest in the class , that is " << marks << endl;
    }

    void grading()
    {
        cout << name << " scores " << grade << " in his class"
             << " which is the highest" << endl;
    }

    void experience()
    {
        cout << name << " age is " << age << " which is the lowest in the class " << endl;
    }
};

int main()
{

    // we are calling constructor here:-
    student s1(50, 15, 90, "marcus");

    s1.experience(); //these are objects of the classss.
    s1.grading();
    s1.score();
    s1.playing();
    s1.study();
    s1.setAge(17);
    cout<<"the age after setting from setter is "<<s1.getAge()<<endl; //we have completed getter and setter alsooooo.

    //   student s1;
    //   s1.name = "vaibhav";
    //   s1.marks = 90;
    //   s1.study();
    //   s1.score();

    return 0;
}