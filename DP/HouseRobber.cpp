class Solution
{
public:
    int recur(vector<int> &nums, int i, vector<int> &memo)
    {
        if (i >= nums.size()) // Base case: Out of bounds
            return 0;
        if (memo[i] != -1) // Memoization
            return memo[i];

        int pick = nums[i] + recur(nums, i + 2, memo); // Pick current, skip next
        int notPick = recur(nums, i + 1, memo);        // Skip current, move to next

        memo[i] = max(pick, notPick);
        return memo[i];
    }

    int rob(vector<int> &nums)
    {
        vector<int> memo(nums.size(), -1);
        return recur(nums, 0, memo); // Start from index 0 //We can start from last index too
    }

    // class Solution {
    //     public:
    //         int rob(vector<int> &nums) {
    //             int n = nums.size();
    //             if (n == 0) return 0;
    //             if (n == 1) return nums[0];

    //             vector<int> dp(n, 0);
    //             dp[0] = nums[0];  // Base case: First house
    //             dp[1] = max(nums[0], nums[1]);  // Max of first two houses

    //             for (int i = 2; i < n; i++) {
    //                 dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);  // Either rob current + dp[i-2] OR skip it
    //             }

    //             return dp[n - 1];  // Max profit for robbing till last house
    //         }
    //     };
};