class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int n = nums.size();
        int first = INT_MAX, second = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > second)
            {
                return true; // Found the triplet
            }
            else if (nums[i] < first)
            {
                first = nums[i]; // Update the smallest number
            }
            else if (nums[i] > first && nums[i] < second)
            {
                second = nums[i]; // Update the second smallest number
            }
        }
        return false;
    }
};