class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        if (n <= 1)
            return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int noOfIntervals = 0;
        res.push_back({intervals[0][0], intervals[0][1]});
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] <= res[noOfIntervals][1])
            {
                res[noOfIntervals][1] = max(res[noOfIntervals][1], intervals[i][1]);
            }
            else
            {
                res.push_back({intervals[i][0], intervals[i][1]});
                noOfIntervals++;
            }
        }
        return res;
    }
};