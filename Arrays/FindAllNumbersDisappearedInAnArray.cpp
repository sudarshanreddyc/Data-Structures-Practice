class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> resultArray;
        for (int i = 0; i < nums.size(); i++)
        {
            int currentAbsoluteIndex = abs(nums[i]) - 1;
            nums[currentAbsoluteIndex] = abs(nums[currentAbsoluteIndex]) * -1;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                resultArray.push_back(i + 1);
        }
        return resultArray;
    }
};