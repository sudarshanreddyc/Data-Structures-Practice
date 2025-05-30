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
    unordered_map<int, int> inorderMap;
    int preOrderIndex = 0;
    TreeNode *buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int inStart, int inEnd)
    {
        if (inStart > inEnd)
            return nullptr;

        int rootVal = preorder[preOrderIndex++];
        TreeNode *root = new TreeNode(rootVal);

        int rootValIndex = inorderMap[rootVal];

        root->left = buildTreeHelper(preorder, inorder, inStart, rootValIndex - 1);
        root->right = buildTreeHelper(preorder, inorder, rootValIndex + 1, inEnd);

        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            inorderMap[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, inorder, 0, inorder.size() - 1);
    }
};