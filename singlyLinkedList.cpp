


#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};

void insertEnd(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;

    if (*head == nullptr) {
        *head = newNode;
    }
    else {
        Node* last = *head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = newNode;
    }
}

void displayList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

void deleteNode(Node** head, int position) {
    if (*head == nullptr) return;

    Node* temp = *head;

    if (position == 0) {
        *head = temp->next;
        delete temp;
        return;
    }

    for (int i = 0; temp != nullptr && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) return;

    Node* next = temp->next->next;
    delete temp->next;
    temp->next = next;
}

int main() {
    cout << "\nWelcome to Linked Lists!\n";

    Node* head = nullptr;

    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);

    displayList(head);

    deleteNode(&head, 2);

    cout << "\nList after deleting third node:\n";
    displayList(head);

    return 0;
}
