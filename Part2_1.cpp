#include <iostream>

using namespace std;

struct ListNode 
    {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;
    
        while (l1 != nullptr || l2 != nullptr || carry != 0) 
        {
            int x = (l1 != nullptr ? l1->val : 0);
            int y = (l2 != nullptr ? l2->val : 0);
            int sum = x + y + carry;
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr) 
                l2 = l2->next;
        }
    
        return dummy->next;
    }

int main() 
    {
        int n1, val;
        cout << "Enter the number of elements in the first linked list: ";
        cin >> n1;
        ListNode* l1 = nullptr;
        ListNode* tail1 = nullptr;
        for (int i = 0; i < n1; i++) 
        {
            cout << "Enter element " << i + 1 << ": ";
            cin >> val;
            ListNode* newNode = new ListNode(val);
            if (l1 == nullptr) 
            {
                l1 = newNode;
                tail1 = newNode;
            } 
            else 
            {
                tail1->next = newNode;
                tail1 = tail1->next;
            }
        }
    
        int n2;
        cout << "Enter the number of elements in the second linked list: ";
        cin >> n2;
        ListNode* l2 = nullptr;
        ListNode* tail2 = nullptr;
        for (int i = 0; i < n2; i++) 
        {
            cout << "Enter element " << i + 1 << ": ";
            cin >> val;
            ListNode* newNode = new ListNode(val);
            if (l2 == nullptr) 
            {
                l2 = newNode;
                tail2 = newNode;
            } 
            else 
            {
                tail2->next = newNode;
                tail2 = tail2->next;
            }
        }
    
        ListNode* result = addTwoNumbers(l1, l2);
        cout << "The sum of the two linked lists is: ";
        while (result != nullptr) 
        {
            cout << result->val << " ";
            result = result->next;
        }
        cout << endl;
        return 0;
    }