class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        // int count = 1, top, longestSeq = 1;
        // if(!pq.empty()) top = pq.top();
        // pq.pop();
        // while(!pq.empty()){
        //     if(pq.top() == top+1){
        //         count++;
        //         longestSeq = max(longestSeq, count);
        //     }
        //     else if(pq.top() != top) count = 1; //don't reset if found duplicates
        //     top = pq.top();
        //     pq.pop();
        // }
        // return longestSeq;

        // if(nums.empty()) return 0; //nums.size()
        // set<int> st(nums.begin(), nums.end());
        // int num = *st.begin(), longestSeq = 1, count = 1;
        // for(int n : st){
        //     if(n == num+1){
        //         count++;
        //         longestSeq = max(longestSeq, count);
        //     } else if (n != num) { // Break detected (skip duplicates)
        //         count = 1;
        //     }
        //     num = n;
        // }
        // return longestSeq;

        if (nums.empty())
            return 0;

        std::unordered_set<int> numSet(nums.begin(), nums.end()); // Store numbers for quick lookup
        int longestSeq = 0;

        for (int num : numSet)
        {
            if (numSet.find(num - 1) == numSet.end())
            { // Start of a sequence
                int count = 1, curr = num;

                while (numSet.find(curr + 1) != numSet.end())
                {
                    curr++;
                    count++;
                }

                longestSeq = std::max(longestSeq, count);
            }
        }

        return longestSeq;
    }
};