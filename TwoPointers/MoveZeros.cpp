class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return;
        int i = 0;
        int j = 0;
        while (i < n && j < n)
        {
            if (nums[j] != 0)
            {
                nums[i++] = nums[j++];
            }
            else
                j++;
        }
        while (i < n)
        {
            nums[i++] = 0;
        }
    }
};