#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyCircularLinkedList {
private:
    Node* head;
    Node* searchNode(int value) {
        if (!head) return nullptr;

        Node* current = head;
        do {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        } while (current != head);

        return nullptr;
    }

public:
    DoublyCircularLinkedList() : head(nullptr) {}


    void insertAtBeginning(int newData) {
        Node* newNode = new Node{newData, nullptr, nullptr};

        if (!head) {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
        } else {
            Node* tail = head->prev; 
            
            newNode->next = head;
            newNode->prev = tail;
            
            head->prev = newNode;
            tail->next = newNode;
            
            head = newNode; 
        }
        cout << "Node " << newData << " inserted at the beginning." << endl;
    }

    void insertAtEnd(int newData) {
        Node* newNode = new Node{newData, nullptr, nullptr};

        if (!head) {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
        } else {
            Node* tail = head->prev; 
            newNode->next = head;
            newNode->prev = tail;
            
            tail->next = newNode;
            head->prev = newNode;
        }
        cout << "Node " << newData << " inserted at the end." << endl;
    }

    void insertAfterNode(int newData, int targetValue) {
        Node* targetNode = searchNode(targetValue);

        if (!targetNode) {
            cout << "Node with value " << targetValue << " not found. Insertion failed." << endl;
            return;
        }

        Node* newNode = new Node{newData, nullptr, nullptr};
        
        newNode->next = targetNode->next;
        newNode->prev = targetNode;
        
        targetNode->next->prev = newNode;
        targetNode->next = newNode;

        cout << "Node " << newData << " inserted after node " << targetValue << "." << endl;
    }

    void insertBeforeNode(int newData, int targetValue) {
        Node* targetNode = searchNode(targetValue);

        if (!targetNode) {
            cout << "Node with value " << targetValue << " not found. Insertion failed." << endl;
            return;
        }

        if (targetNode == head) {
            insertAtBeginning(newData);
            return;
        }

        Node* newNode = new Node{newData, nullptr, nullptr};
        Node* prevNode = targetNode->prev;
        
        newNode->next = targetNode;
        newNode->prev = prevNode;
        
        prevNode->next = newNode;
        targetNode->prev = newNode;

        cout << "Node " << newData << " inserted before node " << targetValue << "." << endl;
    }
    
    void deleteNode(int deleteValue) {
        if (!head) {
            cout << "List is empty. Deletion failed." << endl;
            return;
        }

        Node* toDelete = searchNode(deleteValue);

        if (!toDelete) {
            cout << "Node with value " << deleteValue << " not found. Deletion failed." << endl;
            return;
        }

        if (toDelete == head && toDelete->next == head) {
            delete toDelete;
            head = nullptr;
            cout << "Node " << deleteValue << " deleted. List is now empty." << endl;
            return;
        }

        toDelete->prev->next = toDelete->next;
        toDelete->next->prev = toDelete->prev;

        if (toDelete == head) {
            head = toDelete->next;
        }

        delete toDelete;
        cout << "Node " << deleteValue << " deleted successfully." << endl;
    }
   
    void search(int searchValue) {
        Node* found = searchNode(searchValue);
        if (found) {
            cout << "Node with value " << searchValue << " **found** in the list." << endl;
        } else {
            cout << "Node with value " << searchValue << " **not found** in the list." << endl;
        }
    }
    void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        
        cout << "Doubly Circular Linked List: ";
        Node* current = head;
        do {
            cout << current->data;
            if (current->next != head) {
                cout << " <-> ";
            }
            current = current->next;
        } while (current != head);
        cout << " (-> head)" << endl;
    }
    ~DoublyCircularLinkedList() {
        if (!head) return;
        
        Node* current = head->next;
        Node* temp = nullptr;
        
        head->prev->next = nullptr; // Break the circular link
        
        while (current != nullptr) {
            temp = current;
            current = current->next;
            delete temp;
        }
        delete head;
        head = nullptr;
    }
};
void displayMenu() {
    cout << "\n--- Doubly Circular Linked List Operations ---" << endl;
    cout << "1. Insertion" << endl;
    cout << "2. Deletion of a Specific Node" << endl;
    cout << "3. Search for a Node" << endl;
    cout << "4. Display List" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

void insertionMenu(DoublyCircularLinkedList& list) {
    int subChoice, data, target;
    cout << "\n--- Insertion Menu ---" << endl;
    cout << "1. Insert as First Node" << endl;
    cout << "2. Insert as Last Node" << endl;
    cout << "3. Insert After a Specific Node" << endl;
    cout << "4. Insert Before a Specific Node" << endl;
    cout << "Enter your choice: ";
    cin >> subChoice;

    cout << "Enter the data value to insert: ";
    cin >> data;

    switch (subChoice) {
        case 1:
            list.insertAtBeginning(data);
            break;
        case 2:
            list.insertAtEnd(data);
            break;
        case 3:
            cout << "Enter the value of the node *after* which to insert: ";
            cin >> target;
            list.insertAfterNode(data, target);
            break;
        case 4:
            cout << "Enter the value of the node *before* which to insert: ";
            cin >> target;
            list.insertBeforeNode(data, target);
            break;
        default:
            cout << "Invalid insertion choice." << endl;
    }
}

int main() {
    DoublyCircularLinkedList list;
    int choice, data, target;

    do {
        list.display(); 
        displayMenu();
        cin>>choice;

        switch (choice) {
            case 1:
                insertionMenu(list);
                break;
            case 2:
                cout << "Enter the value of the node to **delete** (e.g., 60): ";
                cin >> target;
                list.deleteNode(target);
                break;
            case 3:
                cout << "Enter the value of the node to **search**: ";
                cin >> target;
                list.search(target);
                break;
            case 4:
                // Display already called before menu, but here for explicit call option
                list.display();
                break;
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
