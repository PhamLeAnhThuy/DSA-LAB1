#include <iostream>

using namespace std;

struct ListNode 
    {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

ListNode* swapNodes(ListNode* head, int k) 
    {
        if (head == nullptr || head->next == nullptr) 
            return head; 
        
        ListNode* kthNode1 = head;
        for (int i = 0; i < k - 1; i++)
            kthNode1 = kthNode1->next;
    
        int n = 0;
        ListNode* temp = head;
        while (temp != nullptr) 
        {
            n++;
            temp = temp->next;
        }
        int kthNode2Index = n - k + 1;
        temp = head;
        for (int i = 0; i < kthNode2Index - 1; i++) 
            temp = temp->next;
        ListNode* kthNode2 = temp;
    
        if (kthNode1 == kthNode2) 
            return head; 
        int tempVal = kthNode1->val;
        kthNode1->val = kthNode2->val;
        kthNode2->val = tempVal;
    
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
    
        head = swapNodes(head, k);

        cout << "The modified linked list is: ";
        while (head != nullptr) 
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    
        return 0;
    }