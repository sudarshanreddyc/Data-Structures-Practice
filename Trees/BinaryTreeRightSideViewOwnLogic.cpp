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
    vector<int> rightSideView(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> res;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            res.push_back(node->val);
            while (q.front() != NULL)
            {
                node = q.front();
                if (node->right)
                    q.push(node->right);
                if (node->left)
                    q.push(node->left);
                q.pop();
            }
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        return res;
    }
};