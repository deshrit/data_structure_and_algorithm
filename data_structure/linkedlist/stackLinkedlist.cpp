/// STACK IMPLEMENTATION OF LINKED LIST

#include <iostream>

using namespace std;

class Stack
{
private:
    struct Node {
        int data;
        Node* next;
    } *top = NULL;

private:
    Node* getNewNode(int data);

public:
    bool isEmpty();

public:
    void push(int data);
    void pop();
    void print();
    int Top();
};

Stack::Node* Stack::getNewNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

bool Stack::isEmpty()
{
    return top == NULL;
}

void Stack::push(int data)
{
    Node* newNode = getNewNode(data);
    if(top == NULL) {
        top = newNode;
        return;
    }

    newNode->next = top;
    top = newNode;
}

void Stack::pop()
{
    if(isEmpty()) return;

    Node* temp = top;
    top = top->next;
    delete temp;
}

int Stack::Top()
{
    return top->data;
}

void Stack::print()
{
    if(isEmpty()) {
        cout << "\nStack empty**\n";
        return;
    }
    Node* temp = top;
    cout << "\nSTACK: ";
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

// Choice Function
inline void showchoice()
{
    cout << "\n1. push\n2. top\n3. pop\n4. print\n5. exit\n";
}

int main()
{
    cout << "### STACK IMPLEMENTATION OF LINKED LIST ###\n\n";

    // Our Stack
    Stack mystak;

    bool quit = false;
    int choice;
    int data;

    do{
        showchoice();

        cout << "\nchoose: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            system("cls");
            cout << "Enter data: ";
            cin >> data;
            mystak.push(data);
            mystak.print();
            break;
        case 2:
            system("cls");
            if(!mystak.isEmpty()) {
                cout << "Top: " << mystak.Top() << "\n";
            }
            mystak.print();
            break;
        case 3:
            system("cls");
            mystak.pop();
            mystak.print();
            break;
        case 4:
            system("cls");
            mystak.print();
            break;
        case 5:
            quit = true;
            break;
        default:
            system("cls");
            cout << "Enter correct option**\n";
        }

    }while(!quit);

    return 0;
}
