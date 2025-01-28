#include <iostream>
#include <queue>
using namespace std;

// Definition of a Tree Node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to insert a node in a binary tree (level-order)
TreeNode* insert(TreeNode* root, int value) {
    TreeNode* newNode = new TreeNode(value);
    if (root == nullptr) {
        return newNode;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        if (temp->left == nullptr) {
            temp->left = newNode;
            break;
        } else {
            q.push(temp->left);
        }

        if (temp->right == nullptr) {
            temp->right = newNode;
            break;
        } else {
            q.push(temp->right);
        }
    }
    return root;
}

// Function to perform in-order traversal
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
vector<vector<int>>solve_level(TreeNode* root)
{
  vector<vector<int>>res;
  if(root==NULL)
  {
    return res;
  }
  queue<TreeNode*>q;
  q.push(root);
  while(!q.empty())
  {
    int sz = q.size();
    vector<int>v;
    for(int i=0;i<sz;i++)
    {
      TreeNode* node = q.front();
      q.pop();
      if(node->left)
        q.push(node->left);
      if(node->right)
        q.push(node->right);
      v.push_back(node->data);
    }
    res.push_back(v);
  }
  return res;
}
// Main function
int main() {
    TreeNode* root = nullptr;

    root = insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);
    insert(root, 6);
    insert(root, 7);

    cout << "In-order Traversal: ";
    inorderTraversal(root);

    cout<<"level order Traversal: ";
    cout<<endl;
    vector<vector<int>>ans = solve_level(root);
    for(auto it : ans)
    {
       for(auto i : it)
       {
           cout<<i<<" ";
       }
       cout<<endl;
    }

    return 0;
}
