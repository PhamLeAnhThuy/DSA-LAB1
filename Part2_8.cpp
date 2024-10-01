#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct ListNode 
    {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };


void insertEnd(ListNode*& head, int value) 
    {
        ListNode* newNode = new ListNode(value);
        if (head == nullptr) 
            head = newNode; 
        else 
        {
            ListNode* temp = head;
            while (temp->next != nullptr) 
                temp = temp->next; 
            temp->next = newNode; 
        }
    }

ListNode* createRandomList() 
    {
        ListNode* head = nullptr;
    
        srand(static_cast<unsigned int>(time(0)));
    
        int numberOfEntries = rand() % 21 + 39; 

        for (int i = 0; i < numberOfEntries; i++) 
        {
            int randomValue = rand() % 199 - 99; 
            insertEnd(head, randomValue);
        }
    
        return head;
    }

void printList(ListNode* head) 
    {
        ListNode* temp = head;
        while (temp != nullptr) 
        {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }


int main() 
    {
        ListNode* randomList = createRandomList();

        cout << "Randomly generated linked list:" << endl;
        printList(randomList);

        ListNode* current = randomList;
        while (current != nullptr)
        {
            ListNode* nextNode = current->next;
            delete current; 
            current = nextNode;
        }
    
        return 0;
    }
