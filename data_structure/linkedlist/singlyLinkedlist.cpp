/// SINGLY LINKED LIST

#include <iostream>

using namespace std;

class List
{
private:
    struct Node {
        int data;
        Node* next;
    } *head = NULL;

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
    return head == NULL;
}

void List::insertEnd(int data)
{
    Node* newNode = getNewNode(data);
    if(head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void List::insertBegin(int data)
{
    Node* newNode = getNewNode(data);

    Node* temp = head;
    head = newNode;
    head->next = temp;
}

void List::insertBeforeNode(int data, int refData)
{
    if(isEmpty()) return;

    Node* newNode = getNewNode(data);
    Node* temp = head;
    Node* previous = NULL;

    while(temp->data != refData) {
        previous = temp;
        temp = temp->next;
    }
    if(temp == head) {
        head = newNode;
        newNode->next = temp;
        return;
    }
    previous->next = newNode;
    newNode->next = temp;
}

void List::insertAfterNode(int data, int refData)
{
    if(isEmpty()) return;

    Node* newNode = getNewNode(data);
    Node* temp = head;

    while(temp->data != refData) {
        temp = temp->next;
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
    Node* temp = head;
    cout << "\nLIST: ";
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void List::deleteEnd()
{
    if(isEmpty()) return;

    Node* temp = head;
    Node* previous = NULL;
    while(temp->next != NULL) {
        previous = temp;
        temp = temp->next;
    }
    if(temp == head) {
        head = NULL;
        delete temp;
        return;
    }
    previous->next = NULL;
    delete temp;
}

void List::deleteBegin()
{
    if(isEmpty()) return;

    Node* temp = head;
    head = head->next;
    delete temp;
}

void List::deleteSpecificNode(int refData)
{
    if(isEmpty()) return;

    Node* temp = head;
    Node* previous = NULL;
    while(temp->data != refData) {
        previous = temp;
        temp = temp->next;
    }
    if(temp == head) {
        head = head->next;
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
    cout << "### SINGLY LINKED LIST ###\n\n";

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
