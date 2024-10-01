#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode 
    {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

ListNode* removeZeroSumSublists(ListNode* head) 
    {
        if (head == nullptr) 
            return nullptr; 
    
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
    
        int prefixSum = 0;
        unordered_map<int, ListNode*> sumToNode;

        ListNode* current = dummy;
        while (current != nullptr) 
        {
            prefixSum += current->val;

            if (sumToNode.count(prefixSum)) 
            {
                ListNode* startNode = sumToNode[prefixSum];
                ListNode* endNode = current;
                startNode->next = endNode->next;
            } 
            else 
                sumToNode[prefixSum] = current;
            current = current->next;
        }
        return dummy->next;
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
        
        head = removeZeroSumSublists(head);

        cout << "The modified linked list is: ";
        while (head != nullptr) 
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    
        return 0;
    }