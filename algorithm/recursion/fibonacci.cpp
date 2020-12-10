/// FIBONACCI SERIES SUM UPTO N TERMS

#include <iostream>

using namespace std;

int fibonacci(int n)
{
    if(n <= 1) return n;
    else
        return (fibonacci(n-1) + fibonacci(n-2));
}

int main()
{
    cout << "### FIBONACCI SERIES UPTO N TERMS ###\n\n";

    int n;
    cout << "\nEnter the nth term: "; cin >> n;
    cout << "\nFibonacci series: ";
    for(int i = 0; i <= n; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << "\n";

    return 0;
}
