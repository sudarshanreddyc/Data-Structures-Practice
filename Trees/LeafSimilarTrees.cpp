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
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> seq1, seq2;
        treeLeaves(root1, seq1);
        treeLeaves(root2, seq2);
        return seq1 == seq2;
    }

private:
    void treeLeaves(TreeNode *root, vector<int> &seq)
    {
        if (!root)
            return;
        else if (!root->left && !root->right)
        {
            seq.push_back(root->val);
            return;
        }
        treeLeaves(root->left, seq);
        treeLeaves(root->right, seq);
    }
};