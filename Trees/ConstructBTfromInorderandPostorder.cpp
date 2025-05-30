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
    int postorderRootIndex;

    TreeNode *buildTreeHelper(vector<int> &inorder, vector<int> &postorder, int inStart, int inEnd)
    {
        if (inStart > inEnd)
            return nullptr;

        int rootVal = postorder[postorderRootIndex--];
        int inorderRootIndex = inorderMap[rootVal];

        TreeNode *root = new TreeNode(rootVal);
        root->right = buildTreeHelper(inorder, postorder, inorderRootIndex + 1, inEnd);
        root->left = buildTreeHelper(inorder, postorder, inStart, inorderRootIndex - 1);

        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            inorderMap[inorder[i]] = i;
        }
        postorderRootIndex = postorder.size() - 1;
        return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1);
    }
};