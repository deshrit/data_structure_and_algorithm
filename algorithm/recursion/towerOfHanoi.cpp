/// TOWER OF HANOI

#include <iostream>

using namespace std;

void hanoi(int n, char f, char v, char t)
{
    if(n == 0) return;
    else {
        hanoi(n-1, f, t, v);
        cout << "Move disk form " << f << " to " << t << endl;
        hanoi(n-1, v, f, t);
    }
}

int main()
{
    cout << "### TOWER OF HANOI ###\n\n";

    int n;
    cout << "\nEnter number of disk: "; cin >> n; cout << "\n";
    hanoi(3, 'A', 'B', 'C');

    return 0;
}
