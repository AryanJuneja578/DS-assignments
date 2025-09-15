#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int findMiddle(ListNode* head) {
    if (head == NULL) {
        return -1;
    }
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow->val;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    cout << "Input: 1->2->3->4->5" << endl;
    cout << "Output: " << findMiddle(head) << endl;
    
    ListNode* current = head;
    while (current != NULL) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
    
    ListNode* head_even = new ListNode(1);
    head_even->next = new ListNode(2);
    head_even->next->next = new ListNode(3);
    head_even->next->next->next = new ListNode(4);
    head_even->next->next->next->next = new ListNode(5);
    head_even->next->next->next->next->next = new ListNode(6);

    cout << "\nInput: 1->2->3->4->5->6" << endl;
    cout << "Output: " << findMiddle(head_even) << endl;

    current = head_even;
    while (current != NULL) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
