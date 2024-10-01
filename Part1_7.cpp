#include <iostream>
#include <vector> 
using namespace std;

struct Node 
    {
        int data;
        Node* next;
    };

bool isPalindrome(Node* head) 
    {
        if (head == nullptr || head->next == nullptr) 
            return true;  
    
        vector<int> values;  
    
        Node* temp = head;
        while (temp != nullptr) 
        {
            values.push_back(temp->data);
            temp = temp->next;
        }
    
        int n = values.size();
        for (int i = 0; i < n / 2; ++i) 
        {
            if (values[i] != values[n - 1 - i]) 
                return false;  
        }
        return true;  
    }


void insertNode(Node*& head, int value) 
    {
        Node* newNode = new Node{value, nullptr};
        if (head == nullptr) 
            head = newNode;
        else 
        {
            Node* temp = head;
            while (temp->next != nullptr) 
                temp = temp->next;
                temp->next = newNode;
        }
    }

void createLinkedList(Node*& head) 
    {
        int n;
        cout << "Enter the number of elements in the linked list: ";
        cin >> n;
        
        cout << "Enter the elements: " << endl;
        for (int i = 0; i < n; ++i) 
        {
            int value;
            cin >> value;
            insertNode(head, value);
        }
    }
    

int main() 
    {
        Node* head = nullptr;
    
        createLinkedList(head);
    
        if (isPalindrome(head))
            cout << "The linked list is a palindrome." << endl;
        else 
            cout << "The linked list is not a palindrome." << endl;
    
        return 0;
    }
