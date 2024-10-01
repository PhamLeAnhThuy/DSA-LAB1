#include <iostream>
using namespace std;

struct ListNode 
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == nullptr) 
            return head;
    
        ListNode* current = head;
        while (current->next != nullptr) 
        {
            if (current->val == current->next->val)
                current->next = current->next->next;
            else 
                current = current->next;
        }
    
        return head;
    }

int main() 
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(1);
        head->next->next = new ListNode(2);
        head->next->next->next = new ListNode(3);
        head->next->next->next->next = new ListNode(3); 
    
        head = deleteDuplicates(head);
    
        ListNode* current = head;
        while (current != nullptr) 
        {
            std::cout << current->val << " ";
            current = current->next;
        }
        std::cout << std::endl;
    
        return 0;
    }
