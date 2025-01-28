#include <iostream>
using namespace std;

// Node structure
class TreeNode {
public:
    int data; // Node data
    TreeNode* left; // Pointer to the left child
    TreeNode* right; // Pointer to the right child

    // Constructor to create a new node
    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Binary Tree class
class BinaryTree {
public:
    TreeNode* root; // Root of the binary tree

    // Constructor to initialize the tree
    BinaryTree() {
        root = nullptr;
    }

    // Function to insert a node in the tree
    void insert(int val) {
        root = insertNode(root, val);
    }

    // In-order traversal (left, root, right)
    void inorderTraversal(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

private:
    // Helper function to insert a node in the tree
    TreeNode* insertNode(TreeNode* node, int val) {
        // If the tree is empty, return a new node
        if (node == nullptr) {
            return new TreeNode(val);
        }

        // Otherwise, recur down the tree
        if (val < node->data) {
            node->left = insertNode(node->left, val);
        } else if (val > node->data) {
            node->right = insertNode(node->right, val);
        }

        // Return the (unchanged) node pointer
        return node;
    }
};

int main() {
    BinaryTree tree;
    // Insert nodes into the tree
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(2);
    tree.insert(7);

    // In-order traversal
    cout << "In-order Traversal: ";
    tree.inorderTraversal(tree.root);

    return 0;
}
