#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};


void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void deleteByValue(Node*& head, int value) {
    if (head == nullptr) {
        cout <<  << endl;
        return;
    }


    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout  << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
}


void displayList(Node* head) {
    if (head == nullptr) {
        cout << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << ;
        temp = temp->next;
    }
    cout << << endl;
}


int main() {
    Node* head = nullptr;  // Initialize an empty linked list


    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);

    cout << ;
    displayList(head);


    deleteByValue(head, 2);
    cout << ;
    displayList(head);

    return 0;
}
