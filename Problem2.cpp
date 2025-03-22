#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void insertSorted(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr || head->data >= data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data < data) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// void printList(Node* head) {
//     Node* current = head;
//     while (current != nullptr) {
//         cout << current->data << " -> ";
//         current = current->next;
//     }
//     cout << "nullptr" << endl;
// }

int main() {
    

    return 0;
}