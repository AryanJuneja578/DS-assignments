void displayCircularList(Node* head) {
    if (head == nullptr) {
        cout << "The circular linked list is empty." << endl;
        return;
    }

    cout << "Circular Linked List Nodes: ";
    
    Node* current = head;
    
    do {
        cout << current->data;

        if (current->next != head) {
            cout << " -> ";
        }
        current = current->next;
    } while (current != head);
    cout << " -> " << head->data <<  endl;
}
