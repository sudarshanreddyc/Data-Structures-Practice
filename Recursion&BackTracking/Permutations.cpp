class Solution
{
public:
    vector<int> temp;
    void recurPermute(vector<int> &nums, vector<vector<int>> &result)
    {
        if (temp.size() == nums.size())
        {
            result.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (find(temp.begin(), temp.end(), nums[i]) != temp.end())
                continue;
            temp.push_back(nums[i]);
            recurPermute(nums, result);
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        recurPermute(nums, result);
        return result;
    }
};