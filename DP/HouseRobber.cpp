class Solution
{
public:
    int recur(vector<int> &nums, int i, vector<int> &memo)
    {
        if (i < 0)
            return 0;
        if (memo[i] != -1)
            return memo[i];
        int pick = nums[i] + recur(nums, i - 2, memo);
        int notPick = recur(nums, i - 1, memo);
        memo[i] = max(pick, notPick);
        return memo[i];
    }
    int rob(vector<int> &nums)
    {
        vector<int> memo(nums.size(), -1);
        return recur(nums, nums.size() - 1, memo);
    }
};