#include <iostream>
using namespace std;

    struct ListNode 
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) 
    {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        
    
        ListNode* pointerA = headA;
        ListNode* pointerB = headB;
    
        
        while (pointerA != pointerB) 
        {
            if (pointerA == nullptr) 
                pointerA = headB;
    
            if (pointerB == nullptr) 
                pointerB = headA;
            
            pointerA = pointerA->next;
            pointerB = pointerB->next;
        }
    
        return pointerA;
    }

int main() 
    {
        ListNode* headA = new ListNode(1);
        headA->next = new ListNode(2);
        headA->next->next = new ListNode(3);
        headA->next->next->next = new ListNode(4);
        headA->next->next->next->next = new ListNode(5);
    
        ListNode* headB = new ListNode(10);  
    
        headB->next = new ListNode(20);
        headB->next->next = new ListNode(30);
        headB->next->next->next = headA->next->next; 
    
    
        ListNode* intersectionNode = getIntersectionNode(headA, headB);
    
        if (intersectionNode != nullptr)
            std::cout << "Intersection node value: " << intersectionNode->val << std::endl;
        else 
            std::cout << "No intersection found." << std::endl;
    
        return 0;
    }
