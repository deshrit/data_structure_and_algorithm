#include <iostream>
#include <stack>
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
    // Calling conversion function on constructor
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
                string num;
                int j = i, n;
                while( isdigit(infix[j]) && infix[j] != ' ' && j != infix.length() ) {   // To get multiple digit number
                    num += infix[j];
                    j++;
                }
                i = j;
                n = stoi(num);  // String to integer
                stk.push(n);
            }
            else if(isOperator(infix[i])) {
                int y = stk.top();
                stk.pop();
                int x = stk.top();
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
    cout << "### POSTFIX EVALUATION ###\n\n";
    string postfix;

    int j;

    do
    {
        cout << "\nPostfix exp(*space separated): ";
        getline(cin, postfix);

        Evaluate p(postfix);
        cout << "\n\tDo you want to repeate(0/1): ";
        cin >> j;
        cin.ignore();

    }while(j == 1);

    return 0;
}
