int DLL_size(DoublyNode* head) {
    int count = 0;
    DoublyNode* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

int CLL_Size(CircularNode* head) {
    if (head == nullptr) {
        return 0;
    }
    int count = 0;
    CircularNode* current = head;
    do {
        count++;
        current = current->next;
    } while (current != head);


    return count;
}
