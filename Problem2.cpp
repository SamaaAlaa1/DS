#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};

class SortedLinkedList{
  Node* head;
  public:
    SortedLinkedList(){
        head = NULL;
    }
    void insert(int data){
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        if(head == NULL){
            head = newNode;
        }
        else{
            Node* temp = head;
            Node* prev = NULL;
            while(temp != NULL && temp->data < data){
                prev = temp;
                temp = temp->next;
            }
            if(prev == NULL){
                newNode->next = head;
                head = newNode;
            }else{
                prev->next = newNode;
                newNode->next = temp;
            }
        }
    }

    void remove(int index) {
        if (head == NULL) {
            cout << "Error: List is empty." << endl;
            return;
        }
    
        Node* temp = head;
        int count = 0;
    
       
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
    
        if (index < 0 || index >= count) {
            cout << "Error: Index out of bounds." << endl;
            return;
        }
    
        if (index == 0) {
            temp = head;
            head = head->next;
            delete temp;
        } else {
            temp = head;
            Node* prev = NULL;
            for (int i = 0; i < index; i++) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            delete temp;
        }
    }

    friend ostream& operator<<(ostream& out, const SortedLinkedList& list) {
        Node* temp = list.head;
        while(temp != NULL){
            out << temp->data << " ";
            temp = temp->next;
        }
        return out;
    }

    int operator[](int index) const {
        Node* temp = head;
        for(int i = 0; i < index; i++){
            temp = temp->next;
        }
        return temp->data;
    }
};

int main() {
    SortedLinkedList list;
    list.insert(5);
    list.insert(3);
    list.insert(7);
    list.insert(1);
    list.insert(9);

    // Test cases
    cout << "Initial list: " << list << endl;

    // Test insertion
    list.insert(4);
    cout << "After inserting 4: " << list << endl;

    list.insert(10);
    cout << "After inserting 10: " << list << endl;

    // Test removal
    list.remove(0);
    cout << "After removing index 0: " << list << endl;

    list.remove(2);
    cout << "After removing index 2: " << list << endl;

    // Test out-of-bounds removal
    list.remove(10);
    cout << "After attempting to remove out-of-bounds index 10: " << list << endl;

    // Test operator[]
    cout << "Element at index 1: " << list[1] << endl;
    list.insert(1);
    cout << list << endl;
    list.remove(3);
    list.remove(12);
    cout << list << endl;
    return 0;
}