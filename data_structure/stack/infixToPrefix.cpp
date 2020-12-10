#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Prefix
{
private:
    bool isOperator(char);
    bool isOperand(char);
    bool equalOrHigher(char, char);
    int getPrecedence(char);
    string convert(string);

public:
    Prefix(string);

};

// Constructor
Prefix::Prefix(string exp)
{
    // Reversing the expression
    reverse(exp.begin(), exp.end());

    // After reversing replacing '(' with ')' and ')' with '('
    for(int i = 0; i < exp.length(); i++) {
        if(exp[i] == '(') {
            exp[i] = ')';
        }
        else if(exp[i] == ')') {
            exp[i] = '(';
        }
    }

    // Main conversion function for "POSTFIX" expression
    exp = convert(exp);

    // Again reversing the converted postfix expression
    // to get prefix expression
    reverse(exp.begin(), exp.end());

    cout << "Prefix: " << exp << endl;
}

bool Prefix::isOperator(char c)
{
    if(c == '+' || c == '-' || c == '/' || c == '*' || c == '^') return true;
    else return false;
}

bool Prefix::isOperand(char c)
{
    if(c >= '0' && c <= '9') return true;
    if(c >= 'A' && c <= 'Z') return true;
    if(c >= 'a' && c <= 'z') return true;
    return false;
}

int Prefix::getPrecedence(char c)
{
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    if(c == '^') return 3;
    return 0;
}

bool Prefix::equalOrHigher(char op1, char op2)
{
    int p1 = getPrecedence(op1);
    int p2 = getPrecedence(op2);
    if(p1 == p2) {
        if(op1 == '^') return false;
        return true;
    }
    return (p1 > p2) ? true : false;
}

string Prefix::convert(string infix)
{
    stack<char> s;
    string Prefix ="";

    char ch;

    s.push('(');
    infix += ')';

    for(int i = 0; i < infix.length(); i++) {
        ch = infix[i];

        if(ch == ' ') continue;
        else if(ch == '(')
            s.push(ch);
        else if(isOperand(ch))
            Prefix += ch;
        else if(isOperator(ch)) {
            while(!s.empty() && equalOrHigher(s.top(), ch)) {
                Prefix += s.top();
                s.pop();
            }
            s.push(ch);
        }
        else if(ch == ')') {
            while(!s.empty() && s.top() != '(') {
                Prefix += s.top();
                s.pop();
            }
            s.pop();
        }
        else {
            cout << "\n\tInvalid expression(only *, /, +, -, ^)\n";
            exit(0);
        }
    }

    return Prefix;
}


int main()
{
    cout << "### INFIX TO PREFIX ###\n\n";

    string infix;
    int j;

    do {
        cout << "\nInfix: ";
        getline(cin, infix);

        Prefix p(infix);

        cout << "\n\tDo you want to repeat(0/1): ";
        cin >> j;
        cin.ignore();
    } while(j == 1);

    return 0;
}
