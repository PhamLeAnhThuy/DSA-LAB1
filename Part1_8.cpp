#include <iostream>
#include <vector>  
using namespace std;

struct Node 
    {
        int data;
        Node* next;
    };

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

vector<Node*> searchValue(Node* head, int X) 
    {
        vector<Node*> result;
        Node* temp = head;
    
        while (temp != nullptr) 
        {
            if (temp->data == X) 
                result.push_back(temp);  
                temp = temp->next;
        }
    
        if (result.empty()) 
            return {};  
        return result;  
    }


void displayList(Node* head) 
    {
        Node* temp = head;
        while (temp != nullptr) 
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }


void createLinkedList(Node*& head) 
    {
        int n;
        cout << "The number of elements in the linked list: ";
        cin >> n;
    
        cout << "The linked list: " << endl;
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
    
        cout << "Linked list: ";
        displayList(head);
    
        int X;
        cout << "Enter value to search: ";
        cin >> X;
    
        vector<Node*> foundNodes = searchValue(head, X);
    
        if (!foundNodes.empty()) 
        {
            cout << "Nodes with value " << X << " found at addresses:" << endl;
        for (Node* node : foundNodes) 
            cout << node << " (Node with value: " << node->data << ")" << endl;
        }
        else 
            cout << "No nodes with value " << X << " found." << endl;
        
        return 0;
    }
