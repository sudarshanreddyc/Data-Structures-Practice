class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int i = 0, k, j;
        while (i < n - 2)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                i++;
                continue;
            } // To avoid duplicates.
            j = i + 1;
            k = n - 1;
            while (j < k)
            {
                int currentSum = nums[i] + nums[j] + nums[k];
                if (currentSum == 0)
                {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])
                        j++; // to avoid duplicates, move until you find the different element.
                    while (k > j && nums[k] == nums[k + 1])
                        k--;
                }
                else if (currentSum < 0)
                    j++;
                else
                    k--;
            }
            i++;
        }

        return result;
    }
};