#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int x_deg;
    struct Node *next;
};

// Create Polynomial One Node On One Call
void createPolynomial(int coeff, int x_deg, struct Node **polyHead)
{
    struct Node* newNode = new Node;
    newNode->coeff = coeff;
    newNode->x_deg = x_deg;
    newNode->next = NULL;

    if(*polyHead == NULL) {
        *polyHead = newNode;
        return;
    }

    struct Node* temp = *polyHead;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

}

// Display Polynomial
void displayPolynomial(struct Node *polyHead)
{
    while(polyHead != NULL) {
        cout << polyHead->coeff << "X^" << polyHead->x_deg;
        if(polyHead->next != NULL) cout << " + ";
        polyHead = polyHead->next;
    }
}

// Add Polynomial
void add(struct Node* poly1, struct Node* poly2, struct Node** polySum)
{
    if(poly1 == NULL) {
        *polySum = poly2;
        return;
    }
    else if(poly2 == NULL) {
        *polySum = poly1;
        return;
    }
    else {
        struct Node* newNode = NULL;

        while(poly1 && poly2) {

            if(poly1->x_deg > poly2->x_deg) {
                createPolynomial(poly1->coeff, poly1->x_deg, &newNode);
                poly1 = poly1->next;
            }
            else if(poly2->x_deg > poly1->x_deg){
                createPolynomial(poly2->coeff, poly2->x_deg, &newNode);
                poly2 = poly2->next;
            }
            else {
                int coeff = poly1->coeff + poly2->coeff;
                int x_deg = poly1->x_deg;

                createPolynomial(coeff, x_deg, &newNode);

                poly1 = poly1->next;
                poly2 = poly2->next;
            }
        }

        while(poly1 || poly2) {
            if(poly1) {
                createPolynomial(poly1->coeff, poly1->x_deg, &newNode);
                poly1 = poly1->next;
            }
            if(poly2) {
                createPolynomial(poly2->coeff, poly2->x_deg, &newNode);
                poly2 = poly2->next;
            }
        }

        *polySum = newNode;
    }
}

// Subtract Polynomial
void subtract(struct Node* poly1, struct Node* poly2, struct Node** polySum)
{
    if(poly1 == NULL) {
        *polySum = poly2;
        return;
    }
    else if(poly2 == NULL) {
        *polySum = poly1;
        return;
    }
    else {
        struct Node* newNode = NULL;
        while(poly1 && poly2) {

            if(poly1->x_deg > poly2->x_deg) {
                createPolynomial(poly1->coeff, poly1->x_deg, &newNode);
                poly1 = poly1->next;
            }
            else if(poly2->x_deg > poly1->x_deg){
                createPolynomial(-poly2->coeff, poly2->x_deg, &newNode);
                poly2 = poly2->next;
            }
            else {
                int coeff = poly1->coeff - poly2->coeff;
                int x_deg = poly1->x_deg;

                createPolynomial(coeff, x_deg, &newNode);

                poly1 = poly1->next;
                poly2 = poly2->next;
            }
        }

        while(poly1 || poly2) {
            if(poly1) {
                createPolynomial(poly1->coeff, poly1->x_deg, &newNode);
                poly1 = poly1->next;
            }
            if(poly2) {
                createPolynomial(-poly2->coeff, poly2->x_deg, &newNode);
                poly2 = poly2->next;
            }
        }
        *polySum = newNode;
    }
}

int main()
{
    struct Node *poly1 = NULL, *poly2 = NULL, *polySum = NULL;
    // Poly 1
    createPolynomial(1, 1, &poly1);
    createPolynomial(2, 2, &poly1);
    createPolynomial(3, 3, &poly1);
    createPolynomial(-3, -5, &poly1);
    createPolynomial(-3, -3, &poly1);

    // Poly 2
    createPolynomial(4, 1, &poly2);
    createPolynomial(5, 2, &poly2);
    createPolynomial(6, 3, &poly2);
    createPolynomial(7, 5, &poly2);

    cout << "Poly1: "; displayPolynomial(poly1);
    cout << endl;
    cout << "Poly2: "; displayPolynomial(poly2);

    cout << endl << endl;

    add(poly1, poly2, &polySum);
    cout << "Add (poly1 + poly2): "; displayPolynomial(polySum);
    cout << endl;
    subtract(poly1, poly2, &polySum);
    cout << "Sub (poly1 - poly2): "; displayPolynomial(polySum);

    cout << endl << endl;

    return 0;
}
