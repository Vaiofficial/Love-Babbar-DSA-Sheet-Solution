#include <bits/stdc++.h>
using namespace std;

int main() {
   int n = 10101010;
   int decimal = 0;
   int base = 1;

   while (n > 0) {
        int bit = n & 1;
        decimal = decimal + bit * base;
        n = n >> 1;
        base = base * 2;
   }

   cout << "The decimal number is: " << decimal;
   return 0;
}
