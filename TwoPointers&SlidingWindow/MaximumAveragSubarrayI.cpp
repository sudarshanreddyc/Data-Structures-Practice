class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        double sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        double maxSum = sum;
        for (int end = k; end < nums.size(); end++)
        {
            sum = sum + nums[end] - nums[end - k];
            maxSum = max(maxSum, sum);
        }
        return maxSum / k;
    }
};