/// FACTORIAL OF A NUMBER

#include <iostream>

using namespace std;

int factorial(int x)
{
    if(x == 1) return 1;
    else return x*factorial(x - 1);
}

int main()
{
    cout << "### FACTORIAL OF A NUMBER ###\n\n";

    int n;
    cout << "\nEnter a number: "; cin >> n;
    cout << "\nFactorial: " << factorial(n) << "\n";


    return 0;
}
