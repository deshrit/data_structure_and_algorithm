/// QUEUE IMPLEMENTATION OF LINKED LIST

#include <iostream>

using namespace std;

class Queue
{
private:
    struct Node {
        int data;
        Node* next;
    } *frnt = NULL, *rear = NULL;

private:
    Node* getNewNode(int data);

public:
    bool isEmpty();

public:
    void enqueue(int data);
    void dequeue();
    void print();
    int Front();
};

Queue::Node* Queue::getNewNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

bool Queue::isEmpty()
{
    return (frnt == NULL || rear == NULL);
}

void Queue::enqueue(int data)
{
    Node* newNode = getNewNode(data);
    if(frnt == NULL && rear == NULL) {
        frnt = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

int Queue::Front()
{
    return frnt->data;
}

void Queue::print()
{
    if(isEmpty()) {
        cout << "\nQueue empty**\n";
        return;
    }
    Node* temp = frnt;
    cout << "\nQUEUE: ";
    while(temp != NULL) {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << "\n";
}

void Queue::dequeue()
{
    if(isEmpty()) return;

    Node* temp = frnt;
    frnt = frnt->next;
    delete temp;
}

inline void showChoice()
{
    cout << "\n1. enque\n2. front \n3. dequeue\n4. print\n5. exit\n";
}

int main()
{
    cout << "### QUEUE USING LINKED LIST ###\n\n";

    // Our Queue
    Queue myq;

    int quit = false;
    int choice;

    // User Input
    int data;

    do{
        showChoice();

        cout << "\nchoose: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            system("cls");
            cout << "Enter data: "; cin >> data;
            myq.enqueue(data);
            myq.print();
            break;
        case 2:
            system("cls");
            if(!myq.isEmpty()) {
                cout << "Front: " << myq.Front() << "\n";
            }
            myq.print();
            break;
        case 3:
            system("cls");
            myq.dequeue();
            myq.print();
            break;
        case 4:
            system("cls");
            myq.print();
            break;
        case 5:
            quit = true;
            break;
        default:
            system("cls");
            cout << "Enter correct option**\n";
        }
    } while(!quit);

    return 0;
}
