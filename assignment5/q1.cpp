#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        cout << "Node " << data << " inserted at the beginning." << endl;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            cout << "Node " << data << " inserted at the end." << endl;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        cout << "Node " << data << " inserted at the end." << endl;
    }

    void insertAfter(int target, int data) {
        Node* current = head;
        while (current != nullptr && current->data != target) {
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Target node " << target << " not found." << endl;
        } else {
            Node* newNode = new Node(data);
            newNode->next = current->next;
            current->next = newNode;
            cout << "Node " << data << " inserted after " << target << "." << endl;
        }
    }

    void insertBefore(int target, int data) {
        if (head == nullptr) {
            cout << "List is empty. Cannot insert before a node." << endl;
            return;
        }
        if (head->data == target) {
            insertAtBeginning(data);
            return;
        }
        Node* current = head;
        while (current->next != nullptr && current->next->data != target) {
            current = current->next;
        }
        if (current->next == nullptr) {
            cout << "Target node " << target << " not found." << endl;
        } else {
            Node* newNode = new Node(data);
            newNode->next = current->next;
            current->next = newNode;
            cout << "Node " << data << " inserted before " << target << "." << endl;
        }
    }

    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << "Node " << temp->data << " deleted from the beginning." << endl;
        delete temp;
    }

    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        if (head->next == nullptr) {
            cout << "Node " << head->data << " deleted from the end." << endl;
            delete head;
            head = nullptr;
            return;
        }
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = nullptr;
        cout << "Node " << temp->data << " deleted from the end." << endl;
        delete temp;
    }

    void deleteNode(int target) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        if (head->data == target) {
            Node* temp = head;
            head = head->next;
            cout << "Node " << temp->data << " deleted." << endl;
            delete temp;
            return;
        }
        Node* current = head;
        while (current->next != nullptr && current->next->data != target) {
            current = current->next;
        }
        if (current->next == nullptr) {
            cout << "Node " << target << " not found." << endl;
        } else {
            Node* temp = current->next;
            current->next = temp->next;
            cout << "Node " << temp->data << " deleted." << endl;
            delete temp;
        }
    }

    void searchNode(int target) {
        Node* current = head;
        int position = 1;
        while (current != nullptr && current->data != target) {
            current = current->next;
            position++;
        }
        if (current == nullptr) {
            cout << "Node " << target << " not found in the list." << endl;
        } else {
            cout << "Node " << target << " found at position " << position << "." << endl;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* current = head;
        cout << "Current List: ";
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
};



int main() {
    LinkedList list;
    int choice, data, target;

    do {
        cout << "\n--- Singly Linked List Menu ---" << endl;
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Insert after a specific node" << endl;
        cout << "4. Insert before a specific node" << endl;
        cout << "5. Delete from the beginning" << endl;
        cout << "6. Delete from the end" << endl;
        cout << "7. Delete a specific node" << endl;
        cout << "8. Search for a node" << endl;
        cout << "9. Display all nodes" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                list.insertAtBeginning(data);
                break;
            case 2:
                cout << "Enter data to insert: ";
                cin >> data;
                list.insertAtEnd(data);
                break;
            case 3:
                cout << "Enter target node data: ";
                cin >> target;
                cout << "Enter new node data: ";
                cin >> data;
                list.insertAfter(target, data);
                break;
            case 4:
                cout << "Enter target node data: ";
                cin >> target;
                cout << "Enter new node data: ";
                cin >> data;
                list.insertBefore(target, data);
                break;
            case 5:
                list.deleteFromBeginning();
                break;
            case 6:
                list.deleteFromEnd();
                break;
            case 7:
                cout << "Enter node data to delete: ";
                cin >> target;
                list.deleteNode(target);
                break;
            case 8:
                cout << "Enter node data to search: ";
                cin >> target;
                list.searchNode(target);
                break;
            case 9:
                list.display();
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
