#include <iostream>
using namespace std;

struct Node 
    {
        int data;
        Node* next;
        Node(int x) : data(x), next(NULL) {}
    };

Node* findMiddle(Node* head) 
    {
        if (head == NULL) return NULL;
    
        int count = 0;
        Node* temp = head;
    
    
        while (temp != NULL) 
        {
            count++;
            temp = temp->next;
        }
    
    
        temp = head;
        for (int i = 0; i < count / 2; i++) 
            temp = temp->next;
        return temp;  
    }
    
void appendNode(Node*& head, int value) 
    {
        if (head == NULL) 
            head = new Node(value);  
        else 
        {
            Node* temp = head;
            while (temp->next != NULL) 
                temp = temp->next;
            temp->next = new Node(value);  
        }
    }


void printList(Node* head) 
    {
        Node* temp = head;
        while (temp != NULL) 
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

int main() 
    {
        Node* head = NULL;  
        int n, value;
    
        cout << "Enter the number of nodes: ";
        cin >> n;
    
        for (int i = 0; i < n; i++) 
        {
            cout << "Enter value for node " << i + 1 << ": ";
            cin >> value;
            appendNode(head, value);  
        }  
        cout << "Your linked list is: ";
        printList(head);
        
        Node* middle = findMiddle(head);
        if (middle != NULL)
            cout << "Middle node: " << middle->data << endl;
        else 
            cout << "The list is empty!" << endl;
        return 0;
    }
