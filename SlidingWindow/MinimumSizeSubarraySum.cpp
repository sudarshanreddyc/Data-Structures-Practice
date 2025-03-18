class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int start = 0, end = 0, minLength = INT_MAX;
        long long currentSum = 0; // Use long long to prevent overflow for large sums

        while (end < n)
        {
            // Expand the window by adding nums[end]
            currentSum += nums[end];

            // Shrink the window if the current sum meets or exceeds the target
            while (currentSum >= target)
            {
                minLength = min(minLength, end - start + 1);
                currentSum -= nums[start]; // Shrink window from the left
                start++;
            }

            // Move end to expand the window
            end++;
        }

        return minLength != INT_MAX ? minLength : 0;
    }
};
