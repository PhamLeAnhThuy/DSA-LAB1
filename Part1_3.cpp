#include <iostream>
using namespace std;

struct ListNode 
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        while (list1 != nullptr && list2 != nullptr) 
        {
            if (list1->val < list2->val) 
            {
                current->next = list1;
                list1 = list1->next;
            } 
            else 
            {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        if (list1 != nullptr) 
            current->next = list1;

        if (list2 != nullptr)
            current->next = list2;
      
        return dummy->next;
    }

ListNode* createLinkedList() 
    {
        int n, val;
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        std::cout << "Enter the number of elements in the list: ";
        std::cin >> n;

        for (int i = 0; i < n; ++i) 
        {
            std::cout << "Enter value " << (i + 1) << ": ";
            std::cin >> val;
            ListNode* newNode = new ListNode(val);
        
            if (head == nullptr) 
            {
                head = newNode;  
                tail = head;
            } 
            else 
            {
                tail->next = newNode;  
                tail = newNode;        
            }
        }
        return head;
    }


void printList(ListNode* head) 
    {
        ListNode* current = head;
        while (current != nullptr) 
        {
            std::cout << current->val << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

int main() 
    {
        std::cout << "Create first sorted linked list:\n";
        ListNode* list1 = createLinkedList();

        std::cout << "Create second sorted linked list:\n";
        ListNode* list2 = createLinkedList();

        ListNode* mergedList = mergeTwoLists(list1, list2);

        std::cout << "Merged sorted linked list: ";
        printList(mergedList);
    
        return 0;
    }