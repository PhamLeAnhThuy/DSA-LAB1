#include <iostream>

using namespace std;

struct Node 
    {
        int data;
        Node* next;
    };

bool detectCycle(Node* head)
    {
        if (head == nullptr || head->next == nullptr) 
            return false;

        Node* slow = head;
        Node* fast = head;
    
        while (fast != nullptr && fast->next != nullptr) 
        {
            slow = slow->next;
            fast = fast->next->next;
    
            if (slow == fast)
                return true; 
        }
        return false;
    }

int main() 
    {
        Node* head = new Node{1, nullptr};
        head->next = new Node{2, nullptr};
        head->next->next = new Node{3, nullptr};
        head->next->next->next = new Node{4, nullptr};
        head->next->next->next->next = head; 
    
        if (detectCycle(head))
            cout << "Cycle detected in the linked list." << endl;
        else
            cout << "No cycle found in the linked list." << endl;
        return 0;
    }