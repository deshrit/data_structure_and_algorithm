/// REVERSE A LIST USING STACK

#include <iostream>
#include <stack>

using namespace std;

struct Node {
    int data;
    Node* next;
} *top = nullptr;


void pushToStack(int data) {

    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if(top == nullptr) {
        top = newNode;
        return;
    }
    newNode->next = top;
    top = newNode;
}

void popFromStack() {
    Node* temp = top;
    stack <int> newstack;

    if (temp == nullptr) return;

    cout << "Original stack: ";
    while(temp != nullptr) {
        cout << temp->data << " ";

        newstack.push(temp->data);
        temp = temp->next;
    }
    cout << "\n";

    cout << "\nNew stack: ";
    while (!newstack.empty()) {
        cout << newstack.top() << " ";
        newstack.pop();
    }
    cout << "\n";
}

int main() {
    pushToStack(12);
    pushToStack(21);
    pushToStack(33);
    pushToStack(312);
    pushToStack(8);

    popFromStack();

    return 0;
}
