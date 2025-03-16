class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int i = 0, j = n - 1, maxWater = INT_MIN;

        while (i < j)
        {
            maxWater = max(maxWater, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return maxWater;
    }
};