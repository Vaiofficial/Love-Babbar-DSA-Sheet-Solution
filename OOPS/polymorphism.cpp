#include <bits/stdc++.h>
using namespace std;

// 1.function overloading 2.operator overloading.
class Vector
{
public:
    int x;
    int y;

    Vector(int x, int y) : x(x), y(y) {}

    void operator+(const Vector &src) // v1 = v1+v2 (condition) //here operator is a keyword.
    {
        // src is v2 that is the source.
        // this = v1 that is the destination.
        this->x = this->x + src.x; // this->+=src.x; // 1 + 4
        this->y = this->y + src.y; // 3 + 5
    }

    void operator*(const Vector &src) // v1 = v1+v2 (condition) //here operator is a keyword.
    {
        // src is v2 that is the source.
        // this = v1 that is the destination.
        this->x = this->x * src.x; // this->+=src.x; // 1 + 4
        this->y = this->y * src.y; // 3 + 5
    }

    void operator/(const Vector &src) // v1 = v1+v2 (condition) //here operator is a keyword.
    {
        // src is v2 that is the source.
        // this = v1 that is the destination.
        this->x = this->x / src.x; // this->+=src.x; // 1 + 4
        this->y = this->y / src.y; // 3 + 5
    }

    void operator++() // v1 = v1+v2 (condition) //here operator is a keyword.
    {
        this->x++;
        this->y++;
    }
    void display()
    {
        cout << "value X: " << x << " "
             << "value y: " << y << endl;
    }
};
int main()
{
    Vector v1(2, 5);
    Vector v2(4, 15);

    // v1 + v2;
    // ++v1;
    // v1 * v2;
    v2 / v1;

    v1.display();

    return 0;
}