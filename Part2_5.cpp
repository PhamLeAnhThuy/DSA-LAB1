#include <iostream>

using namespace std;

struct ListNode 
    {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

ListNode* oddEvenList(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr) 
            return head;

        ListNode* oddHead = new ListNode(0);
        ListNode* oddCurrent = oddHead;
        ListNode* evenHead = new ListNode(0);
        ListNode* evenCurrent = evenHead;  

        ListNode* current = head;
        int count = 0;
        while (current != nullptr) 
        {
            if (count % 2 == 0) 
            {
                evenCurrent->next = current;
                evenCurrent = evenCurrent->next;
            } 
            else 
            {
                oddCurrent->next = current;
                oddCurrent = oddCurrent->next;
            }
            current = current->next;
            count++;
        }

        oddCurrent->next = evenHead->next;
        evenCurrent->next = nullptr;

        return oddHead->next;
    }

int main() 
    {
        int n, val;
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

        head = oddEvenList(head);
        
        cout << "The modified linked list is: ";
        while (head != nullptr) 
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    
        return 0;
    }