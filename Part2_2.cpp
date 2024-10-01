#include <iostream>
#include <unordered_map>

using namespace std;

struct Node 
    {
        int val;
        Node* next;
        Node* random;
        Node(int x) : val(x), next(nullptr), random(nullptr) {}
    };

Node* copyRandomList(Node* head) 
    {
        if (head == nullptr)
            return nullptr;
    
        unordered_map<Node*, Node*> oldToNew;
    
        Node* current = head;
        while (current != nullptr) 
        {
            oldToNew[current] = new Node(current->val);
            current = current->next;
        }
    
        current = head;
        while (current != nullptr) 
        {
            oldToNew[current]->random = oldToNew[current->random];
            current = current->next;
        }
    
        return oldToNew[head];
    }

int main() 
    {
        int n, val, randomVal;
        cout << "Enter the number of elements in the original list: ";
        cin >> n;
        Node* head = nullptr;
        Node* tail = nullptr;
        for (int i = 0; i < n; i++) 
        {
            cout << "Enter element " << i + 1 << ": ";
            cin >> val;
            Node* newNode = new Node(val);
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
    
        cout << "Enter the random pointers (0-based index):" << endl;
        for (Node* current = head; current != nullptr; current = current->next) 
        {
            cout << "Random pointer for element " << current->val << ": ";
            cin >> randomVal;
            if (randomVal != -1) 
            {
                Node* randomNode = head;
                for (int i = 0; i < randomVal; i++) 
                    randomNode = randomNode->next;
        
                current->random = randomNode;
            }
        }
    
        
        Node* copiedHead = copyRandomList(head);
    
        cout << "The copied list is: ";
        for (Node* current = copiedHead; current != nullptr; current = current->next) {
            cout << current->val << " ";
        }
        cout << endl;
    
        return 0;
    }