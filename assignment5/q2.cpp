#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

void insertEnd(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = newNode;
}

void countAndDelete(Node*& head, int key) {
    int count = 0;
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->data == key) {
            count++;
            if (prev == nullptr) {
                Node* temp = current;
                current = current->next;
                head = current;
                delete temp;
            } else {
                // If the key is in the middle or at the end
                Node* temp = current;
                prev->next = current->next;
                current = current->next;
                delete temp;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }

    cout << "Count: " << count << endl;
}

int main() {
    Node* head = nullptr;

    // Build the linked list: 1->2->1->2->1->3->1
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 1);
    insertEnd(head, 3);
    insertEnd(head, 1);

    int key = 1;

    cout << "Original Linked List: ";
    printList(head);

    countAndDelete(head, key);

    cout << "Updated Linked List: ";
    printList(head);

    return 0;
}
