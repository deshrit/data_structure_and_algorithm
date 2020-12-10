/// BINARY SEARCH TREE

#include <iostream>

using namespace std;

class Bst
{
private:
    struct Node
    {
        int data;
        Node* left;
        Node* right;
    } *root = NULL;

private:
    Node* getNewNode(int data);

public:
    void setRoot(Node* root);
    Node* getRoot();

    Node* Insert(int data, Node* root);

    void preOrder(Node* root);
    void postOrder(Node* root);
    void inorder(Node* root);

    bool Search(Node* root, int key);

};

void Bst::setRoot(Node* root)
{
    this->root = root;
}

Bst::Node* Bst::getRoot()
{
    return this->root;
}

Bst::Node* Bst::getNewNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right= NULL;
    return newNode;
}

Bst::Node* Bst::Insert(int data, Node* root)
{
    Node* newNode = getNewNode(data);
    if(root == NULL) {
        root = getNewNode(data);
    }

    else if(data <= root->data)
        root->left = Insert(data, root->left);
    else
        root->right = Insert(data, root->right);
    return root;
}

bool Bst::Search(Node* root, int key)
{
    if(root == NULL) return false;
    if(root->data == key) return true;
    if(root->data < key) return Search(root->right, key);
    else return Search(root->left, key);
}

void Bst::preOrder(Node* root)
{
    if(root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void  Bst::postOrder(Node* root)
{
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void Bst::inorder(Node* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

inline void showChoice()
{
    cout << "\n1. insert\n2. preorder print\n3. postorder print\n4. inorder print\n5. search\n6. exit\n";
}

int main()
{
    cout << "### BINARY SEARCH TREE ###\n\n";

    // Our binary search tree
    Bst bst;

    bool quit = false;
    int choice;
    int data, key;

    do {
        showChoice();

        cout << "\nchoose: "; cin >> choice;

        switch(choice)
        {
        case 1:
            system("cls");
            cout << "\nEnter data: "; cin >> data;
            bst.setRoot(bst.Insert(data, bst.getRoot()));
            break;
        case 2:
            system("cls");
            cout << "\npreOrder: ";
            bst.preOrder(bst.getRoot());
            cout << endl;
            break;
        case 3:
            system("cls");
            cout << "\npostOrder: ";
            bst.postOrder(bst.getRoot());
            cout << endl;
            break;
        case 4:
            system("cls");
            cout << "\ninorder: ";
            bst.inorder(bst.getRoot());
            cout  << endl;
            break;
        case 5:
            system("cls");
            cout << "\nEnter key: "; cin >> key;
            if(bst.Search(bst.getRoot(), key)) cout << "\nFound\n";
            else cout << "\nNot found\n";
            break;
        case 6:
            system("cls");
            quit = true;
            break;
        default:
            system("cls");
            cout << "\nEnter correct option**\n";
        }

    }while(!quit);

    return 0;
}
