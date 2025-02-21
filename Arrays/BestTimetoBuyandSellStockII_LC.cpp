class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<int> localMax;
        vector<int> localMin;

        if (prices.size() == 1)
            return 0;
        bool findLocalMin = true;
        for (int i = 0; i < prices.size(); i++)
        {
            if (i == 0)
            {
                if (prices[i] <= prices[i + 1])
                {
                    localMin.push_back(prices[i]);
                    findLocalMin = false;
                }
            }
            else if (i == prices.size() - 1)
            {
                if (prices[i] >= prices[i - 1])
                {
                    localMax.push_back(prices[i]);
                }
            }
            else
            {
                if (findLocalMin && (prices[i] <= prices[i + 1] && prices[i] <= prices[i - 1]))
                {
                    localMin.push_back(prices[i]);
                    findLocalMin = false;
                }
                else if (!findLocalMin && (prices[i] >= prices[i + 1] && prices[i] >= prices[i - 1]))
                {
                    localMax.push_back(prices[i]);
                    findLocalMin = true;
                }
            }
        }

        int totalProfit = 0;
        int n = min(localMax.size(), localMin.size());

        for (int i = 0; i < n; i++)
        {
            totalProfit += localMax[i] - localMin[i];
        }

        return totalProfit;
    }
};