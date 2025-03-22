class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int len = flowerbed.size();
        int count = 0; // Track how many flowers we can plant

        for (int i = 0; i < len; i++)
        {
            // Check if the current slot is empty and the adjacent ones are also empty or boundaries
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == len - 1 || flowerbed[i + 1] == 0))
            {
                flowerbed[i] = 1; // Plant a flower
                count++;          // Increment the count
                i++;              // Skip the next slot since adjacent planting is not allowed
            }
            if (count >= n)
                return true; // If we already planted enough flowers, return true
        }

        return count >= n; // Check if we were able to plant all required flowers
    }
};