#include <iostream>
#include <stack>
#include <algorithm>
#include<cmath>

using namespace std;

class Evaluate
{
private:
    bool isOperator(char);
    int performOperation(char, int, int);
    int getResult(string);

public:
    Evaluate(string);

};

/// Constructor
Evaluate::Evaluate(string exp)
{
    // Reversing the prefix expression
    reverse(exp.begin(), exp.end());

    // Calling POSTFIX conversion function on constructor
    int result = getResult(exp);
    cout << "Result: " << result << endl;
}

/// Private functions

// Check if operator
bool Evaluate::isOperator(char ch)
{
    if(ch == '*' || ch == '+' || ch == '-' || ch == '/' || ch == '^')
        return true;
    else
        return false;
}

// Performing operation on two operands stored on stack
int Evaluate::performOperation(char ch, int x, int y)
{
    switch(ch)
    {
    case '+':
        return x + y;
        break;
    case '-':
        return x - y;
        break;
    case '*':
        return x * y;
        break;
    case '/':
        return x / y;
        break;
    case '^':
        return pow(x, y);
        break;
    }
    exit(0);
}

int Evaluate::getResult(string infix)
{
    stack<int> stk;

    int result;

    for(int i = 0; i < infix.length(); i++) {
        if(isspace(infix[i]))
            continue;
        else {
            if(isdigit(infix[i])) {
                stk.push((int)infix[i] - '0');
            }
            else if(isOperator(infix[i])) {
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                int z = performOperation(infix[i], x, y);
                stk.push(z);
            }
            else {
                cout << "\n\tInvalid expression\n";
                exit(0);
            }
        }
    }
    result = stk.top();
    stk.pop();

    return result;
}

int main()
{
    cout << "### PREFIX EVALUATION ###\n\n";
    string prefix;

    int j;

    do
    {
        cout << "\nPrefix exp(*single digit): ";
        getline(cin, prefix);

        Evaluate p(prefix);
        cout << "\n\tDo you want to(0/1): ";
        cin >> j;
        cin.ignore();

    }while(j == 1);

    return 0;
}
