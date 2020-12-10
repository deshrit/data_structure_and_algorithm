#include <iostream>
using namespace std;

class Queue
{
private:
    int maxSize, data, frnt = -1, rear = -1, arr[];

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
    if((rear+1)%maxSize == frnt) return true;
    else return false;
}

void Queue::enqueue(int data)
{
    if(isFull())
        return;
    else {
        if(frnt == -1)
            frnt = 0;
        rear = (rear+1)%maxSize;
        arr[rear] = data;
    }
}

void Queue::dequeue()
{
    if(isEmpty()) return;

    if(frnt == rear) frnt=rear= -1;
    else frnt = (frnt+1)%maxSize;
}

int Queue::Front()
{
    return arr[frnt];
}

void Queue::print()
{
    if(isEmpty()) {
        cout << "\ncircular queue empty**\n";
    }
    else {
        if(frnt <= rear) {
            cout << "\nQUEUE(" << maxSize << "): ";
            for(int i = frnt; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
        else {
            int i;
            i = frnt;
            cout << "\nQUEUE(" << maxSize << "): ";
            while(i < maxSize) {
                cout << arr[i] << " ";
                i++;
            }

            i = 0;
            while(i <= rear) {
                cout << arr[i] << " ";
                i++;
            }
            cout << "\n";
        }

    }
    if(isFull()) cout << "\ncircular queue full**\n";
}

// Choice Function
inline void showchoice()
{
    cout << "\n1. enqueue\n2. front\n3. dequeue\n4. print\n5. exit\n";
}

int main()
{
    cout << "### CIRCULAR QUEUE ###\n\n";

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
                cout << "Enter correct option**\n\n";
                break;
            }

    }while(!quit);

    return 0;
}
