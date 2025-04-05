class Solution
{
public:
    int gMax = 0;
    void dfs(TreeNode *node, char dir, int currentMax)
    {
        if (!node)
            return;
        gMax = max(gMax, currentMax); // Update global max first
        if (dir == 'l')
        { // If direction is left then check right and increase 1 otherwise start with left from 1
            // if(node->right){
            //     dfs(node->right, 'r', currentMax+1);
            // }
            // if(node->left){
            //     dfs(node->left, 'l', 1);
            // }
            dfs(node->right, 'r', currentMax + 1);
            dfs(node->left, 'l', 1);
        }
        else if (dir == 'r')
        {
            dfs(node->left, 'l', currentMax + 1);
            dfs(node->right, 'r', 1);
            // if(node->left){
            //     dfs(node->left, 'l', currentMax+1);
            // }
            // if(node->right) dfs(node->right, 'r', 1);
        }
    }

    int longestZigZag(TreeNode *root)
    {
        if (!root)
            return 0;

        dfs(root->left, 'l', 1);
        dfs(root->right, 'r', 1);

        return gMax;
    }
};
