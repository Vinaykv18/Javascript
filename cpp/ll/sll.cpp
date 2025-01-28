#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
void insertAtHead(Node* &head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

// Function to insert a node at the tail
void insertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

// Function to insert a node at a specific position
void insertAtPosition(Node* &tail, Node* &head, int position, int d) {
    if (position == 1) {
        insertAtHead(head, d);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while (cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    // Inserting at the last position
    if (temp->next == NULL) {
        insertAtTail(tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// Function to delete a node at a specific position
void deleteNode(int position, Node* &head) { 
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    } else {
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while (cnt < position) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

// Function to check if a list is circular
bool isCircularList(Node* head) {
    if (head == NULL) {
        return true;
    }

    Node* temp = head->next;
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }
    return (temp == head);
}

// Function to detect a loop using a map
bool detectLoop(Node* head) {
    if (head == NULL)
        return false;

    map<Node*, bool> visited;
    Node* temp = head;
    while (temp != NULL) {
        if (visited[temp] == true) {
            cout << "Present on element " << temp->data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

// Function to print the list
void print(Node* &head) {
    if (head == NULL) {
        cout << "List is empty " << endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a new node
    Node* node1 = new Node(10);

    // Head and tail point to the first node
    Node* head = node1;
    Node* tail = node1;

    // Test insertion at tail
    insertAtTail(tail, 12);
    print(head);
    
    // Test insertion at head
    insertAtHead(head, 15);
    print(head);

    // Test insertion at a specific position
    insertAtPosition(tail, head, 4, 22);
    print(head);

    // Test deletion
    deleteNode(1, head); // Delete head
    print(head);
    deleteNode(3, head); // Delete tail
    print(head);

    print(head);

    return 0;
}



//--------------------------------------
// class Node {
// public:
//     int data;         // Data of the node
//     Node* next;       // Pointer to the next node in the list
//     // Constructor for a node with both data and next node provided
//     Node(int data1, Node* next1) {
//         data = data1;
//         next = next1;
//     }
//     // Constructor for a node with only data provided, next initialized to nullptr
//     Node(int data1) {
//         data = data1;
//         next = nullptr;
//     }
// };
// // Function to print the linked list starting from the given head
// void printLL(Node* head) {
//     while (head != NULL) {
//         cout << head->data << " ";
//         head = head->next;
//     }
// }
// // Function to delete the tail node of a linked list and return the new head
// Node* deleteTail(Node* head) {
//     // If the list is empty or has only one node, return NULL
//     if (head == NULL || head->next == NULL)
//         return NULL;
//     // Initialize a temporary pointer to traverse the list
//     Node* temp = head;
//     // Traverse to the second last node in the list
//     while (temp->next->next != NULL) {
//         temp = temp->next;
//     }
//     // Delete the last node
//     delete temp->next;
//     // Set the next of the second last node to nullptr, effectively removing the last node
//     temp->next = nullptr;
//     // Return the head of the modified list
//     return head;
// }
// int main() {
//     // Initialize a vector with values for the linked list
//     vector<int> arr = {12, 5, 8, 7};
//     // Create a linked list with the values from the vector
//     Node* head = new Node(arr[0]);
//     head->next = new Node(arr[1]);
//     head->next->next = new Node(arr[2]);
//     head->next->next->next = new Node(arr[3]);
//     // Call the deleteTail function to delete the last node
//     head = deleteTail(head);
//     // Print the linked list after deletion
//     printLL(head);
// }