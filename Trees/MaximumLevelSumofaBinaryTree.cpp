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
    int maxLevelSum(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        int maxSum = root->val, maxLevel = 1, currentLevel = 1;
        while (!q.empty())
        {
            int levelSize = q.size(), levelSum = 0;
            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                levelSum += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            if (levelSum > maxSum)
            {
                maxLevel = currentLevel;
                maxSum = levelSum;
            }
            currentLevel++;
        }
        return maxLevel;
    }
};