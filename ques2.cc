#include <iostream>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeSortedLists(ListNode* l1, ListNode* l2) 
{
    
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    
    
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }
    
    
    if (l1 != nullptr) {
        current->next = l1;
    } else {
        current->next = l2;
    }
    
    
    return dummy->next;
}

void printList(ListNode* head) 
{
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
 {
   
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(5);

    ListNode* l2 = new ListNode(2);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(6);

    ListNode* mergedList = mergeSortedLists(l1, l2);

    std::cout << "Merged List: ";
    printList(mergedList);

    
    while (mergedList != nullptr) 
    {
        ListNode* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}
