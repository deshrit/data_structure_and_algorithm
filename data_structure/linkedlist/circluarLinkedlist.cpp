/// CIRCULAR LINKED LIST

#include <iostream>

using namespace std;

class List
{
private:
    struct Node {
        int data;
        Node* next;
    } *tail = NULL;

private:
    Node* getNewNode(int data);

public:
    bool isEmpty();

public:
    void insertEnd(int data);
    void insertBegin(int data);
    void insertBeforeNode(int data, int refData);
    void insertAfterNode(int data, int refData);

    void print();

    void deleteEnd();
    void deleteBegin();
    void deleteSpecificNode(int refData);
};

List::Node* List::getNewNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

bool List::isEmpty()
{
    return tail == NULL;
}

void List::insertEnd(int data)
{
    Node* newNode = getNewNode(data);
    if(tail == NULL) {
        tail = newNode;
        tail->next = tail;
        return;
    }
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
}

void List::insertBegin(int data)
{
    Node* newNode = getNewNode(data);
    if(tail == NULL) {
        tail = newNode;
        tail->next = tail;
        return;
    }
    newNode->next = tail->next;
    tail->next = newNode;
}

void List::insertBeforeNode(int data, int refData)
{
    if(isEmpty()) return;

    Node* newNode = getNewNode(data);
    Node* temp = tail->next;
    Node* previous = NULL;
    while(temp->data != refData) {
        previous = temp;
        temp = temp->next;
    }
    if(temp == tail->next) {
        newNode->next = tail->next;
        tail->next = newNode;
        return;
    }
    previous->next = newNode;
    newNode->next = temp;

}

void List::insertAfterNode(int data, int refData)
{
    if(isEmpty()) return;

    Node* newNode = getNewNode(data);
    Node* temp = tail->next;

    while(temp->data != refData) {
        temp = temp->next;
    }
    if(temp == tail) {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void List::print()
{
    if(isEmpty()) {
        cout << "\nList empty**\n";
        return;
    }
    Node* temp = tail->next;
    cout << "\nLIST: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != tail->next);
    cout << "\n";
}

void List::deleteEnd()
{
    if(isEmpty()) return;

    Node* temp = tail->next;
    Node* previous = NULL;
    while(temp != tail) {
        previous = temp;
        temp = temp->next;
    }
    if(temp->next == tail) {
        tail = NULL;
        delete temp;
        return;
    }
    if(temp == tail->next) {
        tail->next = temp->next;
        delete temp;
        return;
    }
    previous->next = tail->next;
    tail = previous;
    delete temp;

}

void List::deleteBegin()
{
    if(isEmpty()) return;

    Node* temp = tail;
    Node* head = tail->next;
    if(head == tail) {
        tail = NULL;
        delete head;
        return;
    }
    tail->next = head->next;
    delete head;
}

void List::deleteSpecificNode(int refData)
{
    if(isEmpty()) return;

    Node* temp = tail->next;
    Node* previous = NULL;

    while(temp->data != refData) {
        previous = temp;
        temp = temp->next;
    }
    if(temp == tail && temp->next == tail) {
        tail = NULL;
        delete temp;
        return;
    }
    if(temp == tail) {
        previous->next = tail->next;
        tail = previous;
        delete temp;
        return;
    }
    if(temp == tail->next) {
        tail->next = temp->next;
        delete temp;
        return;
    }
    previous->next = temp->next;
    delete temp;
}

inline void showChoice()
{
    cout << "\n1. insert\n2. insertBegin\n3. insertBeforeNode\n4. insertAfterNode\n5. print\n6. delete\n7. deleteBegin\n8. deleteSpecificNode\n9. exit\n";
}

int main()
{
    cout <<  "### CIRCULAR LINKED LIST ###\n\n";

    // Our  List
    List mylist;

    int choice;
    bool quit = false;
    int data, refData;

    while(!quit) {

        showChoice();

        cout << "\nchoose: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            system("cls");
            cout << "\nEnter data: ";
            cin >> data;
            mylist.insertEnd(data);
            mylist.print();
            break;
        case 2:
            system("cls");
            cout << "\nEnter data: ";
            cin >> data;
            mylist.insertBegin(data);
            mylist.print();
            break;
        case 3:
            system("cls");
            if(!mylist.isEmpty()) {
                cout << "\nEnter data: ";
                cin >> data;
                mylist.print();
                cout << "\nEnter reference node data: ";
                cin >> refData;
                mylist.insertBeforeNode(data, refData);
            }
            mylist.print();
            break;
        case 4:
            system("cls");
            if(!mylist.isEmpty()) {
                cout << "\nEnter data: ";
                cin >> data;
                mylist.print();
                cout << "\nEnter reference node data: ";
                cin >> refData;
                mylist.insertAfterNode(data, refData);
            }
            mylist.print();
            break;
        case 5:
            system("cls");
            mylist.print();
            break;
        case 6:
            system("cls");
            mylist.deleteEnd();
            mylist.print();
            break;
        case 7:
            system("cls");
            mylist.deleteBegin();
            mylist.print();
            break;
        case 8:
            system("cls");
            if(!mylist.isEmpty()) {
                mylist.print();
                cout << "\nEnter reference node data: ";
                cin >> refData;
                mylist.deleteSpecificNode(refData);
            }
            mylist.print();
            break;
        case 9:
            system("cls");
            quit = true;
            break;
        default:
            system("cls");
            cout << "\nEnter correct option**\n";
        }
    }

    return 0;
}
