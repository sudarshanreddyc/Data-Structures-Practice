class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        vector<int> res;
        int potionSize = potions.size();
        sort(potions.begin(), potions.end()); // Sort potions array

        // for (int spell : spells) {
        //     // Using ceil to compute the required threshold
        //     long long required = ceil((double)success / spell);

        //     // Perform binary search to find the first valid potion
        //     auto it = lower_bound(potions.begin(), potions.end(), required);

        //     // Count valid potions
        //     res.push_back(potionSize - (it - potions.begin()));
        // }

        for (int spell : spells)
        {
            int l = 0, r = potionSize - 1;
            while (l <= r)
            {
                int mid = l + (r - l) / 2;
                if ((long long)potions[mid] * spell < success)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            res.push_back(potionSize - l);
        }

        return res;
    }
};
