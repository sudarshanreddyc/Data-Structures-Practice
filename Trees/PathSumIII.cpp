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
    int dfs(TreeNode *node, long currentSum, int targetSum)
    {
        if (!node)
            return 0;
        long value = node->val, count = 0;
        long updatedValue = currentSum + value;
        if (updatedValue == targetSum)
            count++;

        // Include the current node.
        count += dfs(node->left, updatedValue, targetSum);
        count += dfs(node->right, updatedValue, targetSum);

        return count;
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return 0;
        int count = dfs(root, 0, targetSum); // from root node

        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);
        return count;
    }
};