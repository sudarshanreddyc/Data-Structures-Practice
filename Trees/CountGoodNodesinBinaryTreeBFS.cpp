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
    int goodNodesCount(TreeNode *root, int max)
    {
        queue<pair<TreeNode *, int>> q; // Pair of node and its max value along the path
        q.push({root, max});
        int count = 0;

        while (!q.empty())
        {
            auto [node, currentMax] = q.front();
            q.pop();

            int value = node->val;
            if (value >= currentMax)
            {
                count++;
                currentMax = value;
            }

            if (node->left)
                q.push({node->left, currentMax});
            if (node->right)
                q.push({node->right, currentMax});
        }

        return count;
    }

    int goodNodes(TreeNode *root)
    {
        if (!root)
            return 0;  // Edge case for an empty tree
        int count = 1; // Include the root itself as it's always "good"
        if (root->left)
            count += goodNodesCount(root->left, root->val);
        if (root->right)
            count += goodNodesCount(root->right, root->val);
        return count;
    }
};