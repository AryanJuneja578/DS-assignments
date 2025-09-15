#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* current = head;
    ListNode* next_node = NULL;
    
    while (current != NULL) {
        next_node = current->next;
       
        current->next = prev;
        prev = current;
        current = next_node;
    }
    return prev;
}

void printList(ListNode* node) {
    while (node != NULL) {
        cout << node->val << "->";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    cout << "Input: ";
    printList(head);

    ListNode* reversed_head = reverseList(head);

    cout << "Output: ";
    printList(reversed_head);
    
    ListNode* current = reversed_head;
    while (current != NULL) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
