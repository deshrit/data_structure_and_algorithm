#include <iostream>
#include <stack>

using namespace std;

class Postfix
{
private:
    bool isOperator(char);
    bool isOperand(char);
    bool equalOrHigher(char, char);
    int getPrecedence(char);
    string convert(string);

public:
    Postfix(string);

};

// Constructor
Postfix::Postfix(string exp)
{
    // Conversion of Infix To Postfix in constructor
    exp = convert(exp);

    cout << "Postfix: " << exp << endl;
}

bool Postfix::isOperator(char c)
{
    if(c == '+' || c == '-' || c == '/' || c == '*' || c == '^') return true;
    else return false;
}

bool Postfix::isOperand(char c)
{
    if(c >= '0' && c <= '9') return true;
    if(c >= 'A' && c <= 'Z') return true;
    if(c >= 'a' && c <= 'z') return true;
    return false;
}

int Postfix::getPrecedence(char c)
{
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    if(c == '^') return 3;
    return 0;
}

bool Postfix::equalOrHigher(char op1, char op2)
{
    int p1 = getPrecedence(op1);
    int p2 = getPrecedence(op2);
    if(p1 == p2) {
        if(op1 == '^') return false;
        return true;
    }
    return (p1 > p2) ? true : false;
}

string Postfix::convert(string infix)
{
    stack<char> s;
    string postfix ="";

    char ch;

    s.push('(');
    infix += ')';

    for(int i = 0; i < infix.length(); i++) {
        ch = infix[i];

        if(ch == ' ') continue;
        else if(ch == '(')
            s.push(ch);
        else if(isOperand(ch))
            postfix += ch;
        else if(isOperator(ch)) {
            while(!s.empty() && equalOrHigher(s.top(), ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
        else if(ch == ')') {
            while(!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else {
            cout << "\n\tInvalid expression(only *, /, +, -, ^)\n";
            exit(0);
        }
    }

    return postfix;
}


int main()
{
    cout << "### INFIX TO POSTFIX ###\n\n";

    string infix;
    int j;

    do {
        cout << "\nInfix: ";
        getline(cin, infix);

        Postfix p(infix);

        cout << "\n\tDo you want to repeat(0/1): ";
        cin >> j;
        cin.ignore();
    } while(j == 1);

    return 0;
}
