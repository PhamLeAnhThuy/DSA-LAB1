/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

Node* findMiddle(Node* head) {
    if (head == NULL) return NULL;

    int count = 0;
    Node* temp = head;

    // First pass: Count the number of nodes in the list
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    // Second pass: Traverse to the middle node
    temp = head;
    for (int i = 0; i < count / 2; i++) {
        temp = temp->next;
    }

    return temp;  // Middle node
}
    
    void appendNode(Node*& head, int value) {
    if (head == NULL) {
        head = new Node(value);  // If the list is empty, create the first node
    } else {
        Node* temp = head;
        while (temp->next != NULL) {  // Traverse to the last node
            temp = temp->next;
        }
        temp->next = new Node(value);  // Add the new node at the end
    }
}

// Function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;  // Declare head as a pointer to the first node

    // Append nodes to the linked list
    appendNode(head, 1);
    appendNode(head, 2);
    appendNode(head, 3);
    appendNode(head, 4);
    appendNode(head, 5);

    // Print the list
    cout << "Linked List: ";
    printList(head);

    // Find the middle node
    Node* middle = findMiddle(head);
    if (middle != NULL) {
        cout << "Middle node: " << middle->data << endl;
    } else {
        cout << "The list is empty!" << endl;
    }

    return 0;
}
    
    
    


