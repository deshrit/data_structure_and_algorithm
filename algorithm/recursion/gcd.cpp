/// GREATEST COMMON DIVISION GCD OF TWO INTEGERS

#include <iostream>

using namespace std;

int gcd(int x, int y)
{
    if(x == y) return x;
    if(x % y == 0) return y;
    if(y % x == 0) return x;
    if(x > y) return gcd(x % y, y);
    else return gcd(x, y % x);;
}

int main()
{
    cout << "### GCD OF TWO INTEGERS ###\n\n";

    int x, y;
    cout << "\nEnter two integers x and y: "; cin >> x >> y;
    cout << "\nGCD of x and y: " << gcd(x,y) << endl;

    return 0;
}
