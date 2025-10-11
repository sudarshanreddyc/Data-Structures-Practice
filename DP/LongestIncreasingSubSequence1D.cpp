class Solution
{
public:
    int recur(int ind, int prevInd, vector<int> &nums, vector<vector<int>> &dp)
    {
        // if(ind == nums.size() - 1){
        //     if(prevInd == -1 || nums[ind] > nums[prevInd]) return 1;
        //     return 0;
        // }

        // base condition
        if (ind == nums.size())
            return 0;

        // We are doing coordinate shifting as prevInd starts from -1
        if (dp[ind][prevInd + 1] != -1)
            return dp[ind][prevInd + 1];

        int len = 0 + recur(ind + 1, prevInd, nums, dp);
        if (prevInd == -1 || nums[ind] > nums[prevInd])
        {
            len = max(len, 1 + recur(ind + 1, ind, nums, dp));
        }

        return dp[ind][prevInd + 1] = len;
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return recur(0, -1, nums, dp);
    }
};

// Time complexity just recursion = 2 options
// Take or not take 2 X 2 X 2.... = 2^n
// memo = n X n  space = (nXn) + auxilary space for stack