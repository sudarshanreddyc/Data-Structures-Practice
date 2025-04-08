class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int s = 1, e = *max_element(piles.begin(), piles.end());
        long minBananas = INT_MAX;
        while (s <= e)
        {
            long mid = (s + e) / 2;
            long count = 0;
            for (int &pile : piles)
            {
                count += ((long long)pile + mid - 1) / mid;
            }
            if (count <= h)
            {
                minBananas = min(mid, minBananas);
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return minBananas;
    }
};