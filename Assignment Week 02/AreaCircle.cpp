#include <bits/stdc++.h>
using namespace std;

float AreaCircle(int r, float pi)
{

    float area = pi * (r * r);

    return area;
}

int main()
{
    float pi = 3.14;
    int radius;
    cout << "enter the radius of the circle" << endl;
    cin >> radius;

    float ans = AreaCircle(radius, pi);

    cout << "The area of the Circle is :" << ans;

    return 0;
}