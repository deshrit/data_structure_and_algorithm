/// PRIORITY QUEUE USING LINKED LIST

#include <iostream>

using namespace std;

class Queue
{
private:
    struct Node {
        int data;
        int priority;
        Node* next;
    } *head = NULL;

private:
    Node* getNewNode(int data, int priority);

public:
    bool isEmpty();

public:
    void enqueue(int data, int priotiry);
    void dequeue();
    void print();
    int Front();
};

Queue::Node* Queue::getNewNode(int data, int priority)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

bool Queue::isEmpty()
{
    return head == NULL;
}

void Queue::enqueue(int data, int priority)
{
    Node* newNode = getNewNode(data, priority);
    if(isEmpty()) {
        head = newNode;
        return;
    }

    Node* temp = head;
    if(head->priority > newNode->priority) {
        newNode->next = head;
        head = newNode;
    }
    else {
        while(temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

int Queue::Front()
{
    return head->data;
}

void Queue::print()
{
    if(isEmpty()) {
        cout << "\nQueue empty**\n";
        return;
    }
    Node* temp = head;
    cout << "\nQUEUE: ";
    while(temp != NULL) {
        cout << temp->data << "(" << temp->priority << ")" << "  ";
        temp = temp->next;
    }
    cout << "\n";
}

void Queue::dequeue()
{
    if(isEmpty()) return;

    Node* temp = head;
    head = head->next;
    delete temp;
}

inline void showChoice()
{
    cout << "\n1. enque\n2. front \n3. dequeue\n4. print\n5. exit\n";
}

int main()
{
    cout << "### PRIORITY QUEUE USING LINKED LIST ###\n\n";

    // Our Queue
    Queue myq;

    int quit = false;
    int choice;
    int data, priority;

    do{
        showChoice();

        cout << "\nchoose: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            system("cls");
            cout << "Enter data and priority respspectively: "; cin >> data >> priority;
            myq.enqueue(data, priority);
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
