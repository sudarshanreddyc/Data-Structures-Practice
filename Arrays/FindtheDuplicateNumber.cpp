class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int absoluteNumber = abs(nums[i]);
            if (nums[absoluteNumber - 1] < 0)
                return absoluteNumber;
            nums[absoluteNumber - 1] *= -1;
        }

        return -1;
    }
};