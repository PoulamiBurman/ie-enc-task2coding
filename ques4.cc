#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode* current = head;

    
    while (current != nullptr && current->next != nullptr) {
        if (current->val == current->next->val) {
            
            ListNode* duplicate = current->next;
            current->next = current->next->next;
            delete duplicate;
        } else {
        
            current = current->next;
        }
    }

    return head;
}


void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);

    std::cout << "Original List: ";
    printList(head);

    ListNode* newList = deleteDuplicates(head);

    std::cout << "List after removing duplicates: ";
    printList(newList);


    while (newList != nullptr) {
        ListNode* temp = newList;
        newList = newList->next;
        delete temp;
    }

    return 0;
}
