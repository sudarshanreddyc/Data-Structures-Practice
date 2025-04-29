class Solution
{
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int n = nums1.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<pair<int, int>> pairs;

        for (int i = 0; i < n; i++)
        {
            pairs.push_back({nums2[i], nums1[i]});
        }

        sort(pairs.begin(), pairs.end(), greater<pair<int, int>>());

        long long currentSum = 0, maxSum = 0;

        for (int i = 0; i < k; i++)
        {
            currentSum += pairs[i].second;
            pq.push(pairs[i].second);
        }

        maxSum = max(maxSum, currentSum * 1LL * pairs[k - 1].first);

        for (int i = k; i < n; i++)
        {
            int top = pq.top();
            pq.pop();
            currentSum -= top;             // We should remove one value first as we are going to consider the current value. So, before considering the new value we should remove the smallest from the heap
            currentSum += pairs[i].second; // Add the current value
            pq.push(pairs[i].second);      // Add it to the heap as well
            maxSum = max(maxSum, currentSum * 1LL * pairs[i].first);
        }

        return maxSum;
    }
};
