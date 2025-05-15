class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {

        // I can also add the new interval, sort it again and then do the merge intervals.
        int n = intervals.size();
        vector<vector<int>> updatedIntervals, res;
        if (n == 0)
        {
            res.push_back(newInterval);
            return res;
        }

        bool newIntervalInserted = false;
        for (int i = 0; i < n; i++)
        {
            if (newInterval[0] < intervals[i][0] && !newIntervalInserted)
            {
                updatedIntervals.push_back(newInterval);
                newIntervalInserted = true;
            }
            updatedIntervals.push_back(intervals[i]);
        }
        if (!newIntervalInserted)
            updatedIntervals.push_back(newInterval);
        res.push_back(updatedIntervals[0]);
        int noOfIntervals = 0;
        for (int i = 1; i < updatedIntervals.size(); i++)
        {
            if (updatedIntervals[i][0] <= res[noOfIntervals][1])
            {
                res[noOfIntervals][1] = max(updatedIntervals[i][1], res[noOfIntervals][1]);
            }
            else
            {
                res.push_back(updatedIntervals[i]);
                noOfIntervals++;
            }
        }
        return res;
    }
};