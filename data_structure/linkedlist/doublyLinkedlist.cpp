/// DOUBLY LINKED LIST

#include <iostream>

using namespace std;

class List
{
private:
    struct Node {
        int data;
        Node *previous, *next;
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
    void printReverse();

    void deleteEnd();
    void deleteBegin();
    void deleteSpeceficNode(int refData);
};

List::Node* List::getNewNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->previous = NULL;
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
    newNode->previous = temp;
    temp->next = newNode;
}

void List::insertBegin(int data)
{
    Node* newNode = getNewNode(data);
    if(head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    head->previous = newNode;
    newNode->next = head;
    head = newNode;
}

void List::insertBeforeNode(int data, int refData)
{
    if(isEmpty()) return;

    Node* newNode = getNewNode(data);
    Node* temp = head;

    while(temp->data != refData) {
        temp = temp->next;
    }
    if(temp == head) {
        head->previous = newNode;
        newNode->next = head;
        head = newNode;
        return;
    }
    temp->previous->next = newNode;
    newNode->previous = temp->previous;
    newNode->next = temp;
    temp->previous = newNode;
}

void List::insertAfterNode(int data, int refData)
{
    if(isEmpty()) return;

    Node* newNode = getNewNode(data);
    Node* temp = head;

    while(temp->data != refData) {
        temp = temp->next;
    }
    if(temp->next == NULL) {
        temp->next = newNode;
        newNode->previous = temp;
        return;
    }
    newNode->next = temp->next;
    temp->next->previous = newNode;
    temp->next = newNode;
    newNode->previous = temp;
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

void List::printReverse()
{
    if(isEmpty()) {
        cout << "\nList empty**\n";
        return;
    }

    Node* temp = head;
    while(temp->next != NULL) temp = temp->next;

    cout << "\nLIST REVERSE: ";
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->previous;
    }
    cout << "\n";
}

void List::deleteEnd()
{
    if(isEmpty()) return;

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    if(temp == head) {
        head = NULL;
        delete temp;
        return;
    }
    temp->previous->next = NULL;
    delete temp;
}

void List::deleteBegin()
{
    if(isEmpty()) return;

    Node* temp = head;
    if(head->next == NULL) {
        head = NULL;
        delete temp;
        return;
    }
    head = head->next;
    head->previous = NULL;
    delete temp;
}

void List::deleteSpeceficNode(int refData)
{
    if(isEmpty()) return;

    Node* temp = head;
    while(temp->data != refData) {
        temp = temp->next;
    }
    if(temp == head) {
        head = head->next;
        head->previous = NULL;
        delete temp;
        return;
    }
    if(temp->next == NULL) {
        temp->previous->next = NULL;
        delete temp;
        return;
    }
    temp->previous->next = temp->next;
    temp->next->previous = temp->previous;
    delete temp;
}

inline void showChoice()
{
    cout << "\n0. insert\n1. insertBegin\n2. insertBeforeNode\n3. insertAfterNode\n4. print\n5. print reverse\n6. delete\n7. deleteBegin\n8. deleteSpecificNode\n9. exit\n";
}

int main()
{
    cout << "### DOUBLY LINKED LIST ###\n\n";

    // Our List
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
        case 0:
            system("cls");
            cout << "\nEnter data: ";
            cin >> data;
            mylist.insertEnd(data);
            mylist.print();
            break;
        case 1:
            system("cls");
            cout << "\nEnter data: ";
            cin >> data;
            mylist.insertBegin(data);
            mylist.print();
            break;
        case 2:
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
        case 3:
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
        case 4:
            system("cls");
            mylist.print();
            break;
        case 5:
            system("cls");
            mylist.printReverse();
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
                mylist.deleteSpeceficNode(refData);
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
