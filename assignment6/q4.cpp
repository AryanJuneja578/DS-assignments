bool isPalindrome(Node* head) {
    if (!head) {
        return true;
    }
    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    Node* front = head;
    Node* back = tail;

    while (front != back && front->prev != back) {
        if (front->data != back->data) {
            return false;
        }
        front = front->next;
        back = back->prev;
    }
    return true;
}
