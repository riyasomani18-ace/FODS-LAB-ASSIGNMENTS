#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int exp;
    Node* next;
};

// Create a new node
Node* createNode(int c, int e) {
    Node* temp = new Node();
    temp->coeff = c;
    temp->exp = e;
    temp->next = NULL;
    return temp;
}

// Insert term in descending order of exponent
void insertTerm(Node*& poly, int c, int e) {
    Node* newNode = createNode(c, e);

    if (poly == NULL || poly->exp < e) {
        newNode->next = poly;
        poly = newNode;
        return;
    }

    Node* temp = poly;
    while (temp->next != NULL && temp->next->exp > e) {
        temp = temp->next;
    }

    if (temp->next != NULL && temp->next->exp == e) {
        temp->next->coeff += c;
        delete newNode;
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Add two polynomials
Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp == poly2->exp) {
            insertTerm(result, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->exp > poly2->exp) {
            insertTerm(result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        }
        else {
            insertTerm(result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insertTerm(result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insertTerm(result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}

// Display polynomial
void display(Node* poly) {
    if (poly == NULL) {
        cout << "0";
        return;
    }

    while (poly != NULL) {
        cout << poly->coeff << "x^" << poly->exp;
        poly = poly->next;
        if (poly != NULL) cout << " + ";
    }
    cout << endl;
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    int n1, n2, c, e;

    cout << "Enter number of terms in first polynomial: ";
    cin >> n1;

    cout << "Enter terms (coeff exponent):\n";
    for (int i = 0; i < n1; i++) {
        cin >> c >> e;
        insertTerm(poly1, c, e);
    }

    cout << "Enter number of terms in second polynomial: ";
    cin >> n2;

    cout << "Enter terms (coeff exponent):\n";
    for (int i = 0; i < n2; i++) {
        cin >> c >> e;
        insertTerm(poly2, c, e);
    }

    cout << "\nPolynomial 1: ";
    display(poly1);

    cout << "Polynomial 2: ";
    display(poly2);

    Node* sum = addPolynomials(poly1, poly2);

    cout << "\nResultant Polynomial After Addition: ";
    display(sum);

    return 0;
}
