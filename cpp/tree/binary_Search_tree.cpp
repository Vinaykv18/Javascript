#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
TreeNode *insert(TreeNode *root, int value)
{
    if (root == nullptr)
        return new TreeNode(value);
    if (value < root->data)
      root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}
void inorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
vector<vector<int>> solve_level(TreeNode *root)
{
    vector<vector<int>> res;
    if (root == NULL)
        return res;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int sz = q.size();
        vector<int> v;
        for (int i = 0; i < sz; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
            v.push_back(node->data);
        }
        res.push_back(v);
    }
    return res;
}
int main()
{
    TreeNode *root = nullptr;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 12);
    insert(root, 18);

    cout << "In-order Traversal: ";
    inorderTraversal(root);

    cout << "level order Traversal: ";
    cout << endl;
    vector<vector<int>> ans = solve_level(root);
    for (auto it : ans)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
