#include <iostream>
#include <vector>

using namespace std;

struct ListNode 
    {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        int length = 0;
        ListNode* temp = head;
        while (temp != nullptr) 
        {
            length++;
            temp = temp->next;
        }
        
        int partSize = length / k;
        int extraParts = length % k;
    
        vector<ListNode*> parts(k, nullptr);
        temp = head;
    
        for (int partIndex = 0; partIndex < k; ++partIndex) 
        {
            if (temp != nullptr) 
            {
                parts[partIndex] = temp; 

                int currentPartSize = partSize + (partIndex < extraParts ? 1 : 0);

                for (int count = 0; count < currentPartSize - 1; ++count) 
                {
                    if (temp != nullptr) 
                        temp = temp->next; 
                }
    
                if (temp != nullptr) 
                {
                    ListNode* nextPartHead = temp->next; 
                    temp->next = nullptr; 
                    temp = nextPartHead;
                }
            }
        }
        return parts;
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
    
        vector<ListNode*> parts = splitListToParts(head, k);
    
        cout << "The divided linked list parts are:" << endl;
        for (int i = 0; i < parts.size(); i++) 
        {
            cout << "Part " << i + 1 << ": ";
            ListNode* temp = parts[i];
            while (temp != nullptr) 
            {
                cout << temp->val << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        
        return 0;
    }
