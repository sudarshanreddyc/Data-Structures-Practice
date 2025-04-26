class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> pq(nums.begin(), nums.end());
        while (!pq.empty() && --k > 0)
        {
            pq.pop();
        }
        return pq.top();

        // priority_queue<int, vector<int>, greater<int>> pq;
        // for (int num : nums) {
        //     pq.push(num);
        //     if (pq.size() > k) pq.pop();
        // }
        // return pq.top();
    }
};