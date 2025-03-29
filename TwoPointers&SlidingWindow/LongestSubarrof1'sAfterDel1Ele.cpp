class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int l = 0, totalMax = 0, n = nums.size(), zeroCount = 0;
        for (int r = 0; r < n; r++)
        {
            if (nums[r] == 0)
                zeroCount++;
            while (zeroCount > 1)
            {
                if (nums[l] == 0)
                    zeroCount--;
                l++;
            }
            totalMax = max(totalMax, r - l);
        }
        return totalMax;
    }
};