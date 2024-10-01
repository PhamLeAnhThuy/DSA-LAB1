#include <iostream>

using namespace std;

struct ListNode
    {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if (head == nullptr)
            return nullptr;

        int length = 0;
        ListNode* temp = head;
        while (temp != nullptr) 
        {
            length++;
            temp = temp->next;
        }

        int indexToRemove = length - n;

        if (indexToRemove == 0) 
            return head->next;
    
        temp = head;
        for (int i = 0; i < indexToRemove - 1; i++) 
            temp = temp->next;
            
        temp->next = temp->next->next;
        return head;
    }

int main() 
    {
        int n, val, k;
        cout << "Enter the number of elements in the linked list: ";
        cin >> n;
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        for (int i = 0; i < n; i++) 
        {
            cout << "Enter element " << i + 1 << ": ";
            cin >> val;
            ListNode* newNode = new ListNode(val);
            if (head == nullptr) 
            {
                head = newNode;
                tail = newNode;
            } 
            else 
            {
                tail->next = newNode;
                tail = tail->next;
            }
        }

        cout << "Enter the value of k: ";
        cin >> k;

        head = removeNthFromEnd(head, k);

        cout << "The modified linked list is: ";
        while (head != nullptr) 
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    
        return 0;
    }