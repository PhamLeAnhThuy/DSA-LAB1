#include <iostream>

struct ListNode 
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

ListNode* reverseList(ListNode* head) 
    {
        if (head == nullptr || head->next == nullptr)
            return head;
    
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
    
        while (curr != nullptr) 
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    
        return prev;
    }

int main() 
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        head->next->next->next->next = new ListNode(5);
    
        head = reverseList(head);
    
        ListNode* current = head;
        while (current != nullptr) 
        {
            std::cout << current->val << " ";
            current = current->next;
        }
        std::cout << std::endl;
    
        return 0;
    }