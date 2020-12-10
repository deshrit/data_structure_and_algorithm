/// STACK USING ARRAY

#include <iostream>
using namespace std;

class Stack
{
public:
    Stack(int maxSize);

private:
    const int MAXSIZE;
    int top, arr[];

public:
    bool isEmpty();
    bool isFull();

public:


    void push(int data);
    void pop();
    void print();
    int Top();
};

// Constructor
Stack::Stack(int maxSize):MAXSIZE(maxSize) {
    arr[MAXSIZE];
    this->top = -1;
}

bool Stack::isEmpty()
{
    return (top == -1);
}

bool Stack::isFull()
{
    return (top == MAXSIZE - 1);
}

void Stack::push(int data)
{
    if(isFull()) return;

    top++;
    arr[top] = data;
}

void Stack::pop()
{
    if(isEmpty()) return;
    top--;
}

int Stack::Top()
{
   return arr[top];
}

void Stack::print()
{
    if(isEmpty()) {
        cout << "\nStack empty**\n";
        return;
    }

    cout << "\nSTACK (" << MAXSIZE << "): ";
    for(int i = 0; i <= top; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    if(isFull()) cout << "\nStack full**\n";

}

// Choice Function
inline void showchoice()
{
    cout << "\n1. push\n2. top\n3. pop\n4. print\n5. exit\n";
}

int main()
{
    cout << "### ARRAY STACK ###\n\n";
    int MAXSIZE;
    cout << "Enter size of array: ";
    cin >> MAXSIZE;
    if(MAXSIZE <= 0) exit(0);

    // Our Stack
    Stack mystak(MAXSIZE);

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
            if(!mystak.isFull()) {
                cout << "Enter data: ";
                cin >> data;
                mystak.push(data);
            }
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
