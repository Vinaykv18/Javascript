#include <iostream>
#include <queue>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize the node
    Node(int d) {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};
// Function to build the tree recursively
Node* buildTree(Node* root) {
    cout << "Enter the data: ";
    int data;
    cin >> data;

    // Base case for recursion
    if (data == -1) {
        return nullptr;
    }

    // Creating the new node
    root = new Node(data);

    // Recursively building the left subtree
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);

    // Recursively building the right subtree
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

// Function for level-order traversal (BFS)
void levelOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(nullptr); // Marker for the end of the current level

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == nullptr) {
            // The current level is complete
            cout << endl;
            if (!q.empty()) {
                // Add a new marker for the next level
                q.push(nullptr);
            }
        } else {
            cout << temp->data << " ";
            // Push left child to the queue if it exists
            if (temp->left) {
                q.push(temp->left);
            }
            // Push right child to the queue if it exists
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}
int main() {
    Node* root = nullptr;

    // Building the tree
    root = buildTree(root);

    // Performing level-order traversal
    cout << "Level Order Traversal: " << endl;
    levelOrderTraversal(root);

    return 0;
}
