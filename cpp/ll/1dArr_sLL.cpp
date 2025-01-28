#include <iostream>
#include <vector>
using namespace std;

// Definition of the Node
class Node {
  public:
    int data;
    Node* next;

    //Node(int val) : data(val), next(nullptr) {}
    Node(int val)
    {
      this->data=val;
      this->next=NULL;
    }
};

// Function to convert vector to linked list
Node* convertToLinkedList(const vector<int>& vec) {
    if (vec.empty()) return nullptr;

    Node* head = new Node(vec[0]);
    Node* current = head;

    for (int i = 1; i < vec.size(); ++i) {
        current->next = new Node(vec[i]);
        current = current->next;
    }

    return head;
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

// Main function
int main() {
    vector<int> vec = {10, 20, 30, 40, 50};
    //Node* node;
    
    Node* head = convertToLinkedList(vec);

    printLinkedList(head);

    return 0;
}


//----------------------------------------

// #include <iostream>
// #include <vector>
// using namespace std;

// // Definition of the LinkedList and Node
// class LinkedList {
// private:
//     class Node {
//     public:
//         int data;
//         Node* next;

//         // Constructor
//         Node(int val) : data(val), next(nullptr) {}
//     };

//     Node* head;

// public:
//     // Constructor
//     LinkedList() : head(nullptr) {}

//     // Method to convert a vector to a linked list
//     void convertFromVector(const vector<int>& vec) {
//         if (vec.empty()) return;

//         head = new Node(vec[0]);
//         Node* current = head;

//         for (size_t i = 1; i < vec.size(); ++i) {
//             current->next = new Node(vec[i]);
//             current = current->next;
//         }
//     }

//     // Method to print the linked list
//     void printList() const {
//         Node* temp = head;
//         while (temp) {
//             cout << temp->data << " -> ";
//             temp = temp->next;
//         }
//         cout << "nullptr" << endl;
//     }
// };

// int main() {
//     vector<int> vec = {10, 20, 30, 40, 50};

//     LinkedList linkedList;
//     linkedList.convertFromVector(vec);

//     linkedList.printList();

//     return 0;
// }

//--------------------------------------------------using___ struct-------

// #include <iostream>
// #include <vector>
// using namespace std;

// // Definition of the Node
// struct Node {
//     int data;
//     Node* next;

//     Node(int val) : data(val), next(nullptr) {}
// };

// // Function to convert vector to linked list
// Node* convertToLinkedList(const vector<int>& vec) {
//     if (vec.empty()) return nullptr;

//     Node* head = new Node(vec[0]);
//     Node* current = head;

//     for (size_t i = 1; i < vec.size(); ++i) {
//         current->next = new Node(vec[i]);
//         current = current->next;
//     }

//     return head;
// }

// // Function to print the linked list
// void printLinkedList(Node* head) {
//     Node* temp = head;
//     while (temp) {
//         cout << temp->data << " -> ";
//         temp = temp->next;
//     }
//     cout << "nullptr" << endl;
// }

// // Main function
// int main() {
//     vector<int> vec = {10, 20, 30, 40, 50};
    
//     Node* head = convertToLinkedList(vec);

//     printLinkedList(head);

//     return 0;
// }
