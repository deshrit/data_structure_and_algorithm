/// LINEAR QUEUE

#include <iostream>

using namespace std;

class Queue
{
private:
    int maxSize, frnt = -1, rear = -1, arr[];

public:
    bool isFull();
    bool isEmpty();

public:
    Queue(int maxSize);

    void enqueue(int data);
    void dequeue();
    void print();
    int Front();

};

// Constructor
Queue::Queue(int maxSize)
{
    this->maxSize = maxSize;
    arr[maxSize];
}

bool Queue::isEmpty()
{
    if(frnt == -1 && rear == -1) return true;
    else return false;
}

bool Queue::isFull()
{
    if(rear == maxSize-1) return true;
    else return false;
}

void Queue::enqueue(int data)
{
    if(isFull()) return;

    if(frnt == -1)
        frnt = 0;
    rear++;
    arr[rear] = data;
}

void Queue::dequeue()
{
    if(isEmpty()) return;

    if(frnt == rear) frnt = rear = -1;
    else frnt++;
}

int Queue::Front()
{
    return arr[frnt];
}

void Queue::print()
{
    if(isEmpty()) {
        cout << "\nlinear queue empty**\n";
        return;
    }

    cout << "\nQUEUE(" << maxSize << "): ";
    for(int i = frnt; i <= rear; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    if(isFull()) cout << "\nlinear queue full**\n";

}

// Choice Function
inline void showchoice()
{
    cout << "\n1. enqueue\n2. front\n3. dequeue\n4. print\n5. exit\n";
}

int main()
{
    cout << "### LINEAR QUEUE ###\n\n";
    int maxSize;
    cout << "Enter size of queue: ";
    cin >> maxSize;
    if(maxSize <= 0) exit(0);

    // Our Queue
    Queue myq(maxSize);

    // Menu Driving
    bool quit = false;
    int choice;

    // User input data
    int data;

    do{
            showchoice();

            cout << "\nchoose: ";
            cin >> choice;

            switch(choice)
            {
            case 1:
                system("cls");
                if(!myq.isFull()) {
                    cout << "Enter data: ";
                    cin >> data;
                    myq.enqueue(data);
                }
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
                break;
            }

    }while(!quit);

    return 0;
}
