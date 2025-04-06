/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return root;

        if (root->val == key)
        {
            return helper(root);
        }
        else if (key < root->val)
            root->left = deleteNode(root->left, key);
        else
            root->right = deleteNode(root->right, key);
        return root;
    }

    TreeNode *helper(TreeNode *root)
    {
        if (!root->left && !root->right)
            return NULL;
        if (root->left == NULL)
            return root->right;
        else if (root->right == NULL)
            return root->left;
        else
        {
            TreeNode *lastRight = findLastRight(root->left); // Find last right or max from left subtree
            lastRight->right = root->right;
            return root->left; // New root will be root->left as root should be deleted
        }
    }

    TreeNode *findLastRight(TreeNode *root)
    {
        while (root->right)
        {
            root = root->right;
        }
        return root;
    }
};