/// CHECK PARENTHESIS OF ALGEBRIC EXPRESSION

#include <iostream>
#include <stack>

using namespace std;

bool isBalanced(string exp) {
    stack <char> st;

    for(int i = 0; i < exp.length(); i++) {
        if(exp[i] == '[' || exp[i] == '{'|| exp[i] == '(') {
            st.push(exp[i]);
        }
    }

    for(int i = 0; i < exp.length(); i++) {

        if(exp[i] == ']' || exp[i] == '}'|| exp[i] == ')') {

            if(st.empty()) return false;

            switch(exp[i])
            {
            case ']':
                if(st.top() == '[') st.pop();
                else return false;
                break;
            case '}':
                if(st.top() == '{') st.pop();
                else return false;
                break;
            case ')':
                if(st.top() == '(') st.pop();
                else return false;
                break;
            }
        }
    }
    if(!st.empty()) return false;
    return true;
}

int main() {

    string exp = "(1-2+[3 + {1 + 2}])";

    // Checking the value return by the function
    if(isBalanced(exp))
        cout << exp << " is balanced\n";
    else
        cout << exp << " is not balanced\n";

    return 0;
}
