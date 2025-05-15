class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> res;
        if (nums.size() == 0)
            return res;
        int l = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1] + 1)
            {
                if (i - l == 1)
                {
                    res.push_back(to_string(nums[l]));
                }
                else
                {
                    res.push_back(to_string(nums[l]) + "->" + to_string(nums[i - 1]));
                }
                l = i;
            }
        }

        // Add last range
        res.push_back(l == nums.size() - 1 ? to_string(nums[l])
                                           : to_string(nums[l]) + "->" + to_string(nums[nums.size() - 1]));
        return res;
    }
};