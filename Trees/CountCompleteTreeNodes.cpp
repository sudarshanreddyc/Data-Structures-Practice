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
    int countNodesHelper(TreeNode *root, int count)
    {
        if (!root)
            return count;
        return 1 + countNodesHelper(root->left, count) + countNodesHelper(root->right, count);
    }
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        return countNodesHelper(root, 0);
    }
};