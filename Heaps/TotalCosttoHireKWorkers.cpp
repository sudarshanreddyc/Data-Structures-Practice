class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        int l = 0, r = costs.size() - 1;
        long long total = 0;
        priority_queue<int, vector<int>, greater<int>> pqFirst, pqLast;
        for (int i = 0; i < candidates && l <= r; i++)
        {
            pqFirst.push(costs[l++]);
        }
        for (int i = 0; i < candidates && l <= r; i++)
        {
            pqLast.push(costs[r--]);
        }
        while (k-- > 0)
        {
            if (pqFirst.empty() && !pqLast.empty())
            {
                int top = pqLast.top();
                total += top;
                pqLast.pop();
                if (l <= r)
                    pqLast.push(costs[r--]);
            }
            else if (!pqFirst.empty() && pqLast.empty())
            {
                int top = pqFirst.top();
                total += top;
                pqFirst.pop();
                if (l <= r)
                    pqFirst.push(costs[l++]);
            }
            else
            {
                int leftTop = pqFirst.top();
                int rightTop = pqLast.top();

                if (leftTop <= rightTop)
                {
                    total += leftTop;
                    pqFirst.pop();
                    if (l <= r)
                        pqFirst.push(costs[l++]);
                }
                else
                {
                    total += rightTop;
                    pqLast.pop();
                    if (l <= r)
                        pqLast.push(costs[r--]);
                }
            }
        }
        return total;
    }

    // long long totalCost(vector<int>& costs, int k, int candidates) {
    //     int l = 0, r = costs.size() - 1;
    //     long long total = 0;
    //     priority_queue<int, vector<int>, greater<int>> pqFirst, pqLast;

    //     // Fill initial heaps
    //     for (int i = 0; i < candidates && l <= r; ++i) {
    //         pqFirst.push(costs[l++]);
    //     }
    //     for (int i = 0; i < candidates && l <= r; ++i) {
    //         pqLast.push(costs[r--]);
    //     }

    //     while (k-- > 0) {
    //         int leftTop = pqFirst.empty() ? INT_MAX : pqFirst.top();
    //         int rightTop = pqLast.empty() ? INT_MAX : pqLast.top();

    //         if (leftTop <= rightTop) {
    //             total += leftTop;
    //             pqFirst.pop();
    //             if (l <= r) pqFirst.push(costs[l++]);
    //         } else {
    //             total += rightTop;
    //             pqLast.pop();
    //             if (l <= r) pqLast.push(costs[r--]);
    //         }
    //     }

    //     return total;
    // }
};