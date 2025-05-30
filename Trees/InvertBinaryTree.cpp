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
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return root;

        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);

        return root;

        // TreeNode* temp = root->left;
        // root->left = invertTree(root->right);
        // root->right = invertTree(temp);

        // TreeNode* left = invertTree(root->left);
        // TreeNode* right = invertTree(root->right);

        // root->left = right;
        // root->right = left;
    }
};