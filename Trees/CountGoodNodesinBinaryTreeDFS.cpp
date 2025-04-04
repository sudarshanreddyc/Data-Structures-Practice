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
    int dfs(TreeNode *node, int currentMax)
    {
        if (!node)
            return 0;

        int count = 0;
        if (node->val >= currentMax)
        {
            count++;
        }
        currentMax = max(currentMax, node->val);
        int leftCount = dfs(node->left, currentMax);   // we can do count += dfs();
        int rightCount = dfs(node->right, currentMax); // we can do count += dfs();

        return count + leftCount + rightCount; // Return count
    }

    int goodNodes(TreeNode *root)
    {
        if (!root)
            return 0; // Edge case: Empty tree
        return dfs(root, root->val);
    }
};