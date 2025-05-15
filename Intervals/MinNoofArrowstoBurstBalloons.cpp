class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        vector<vector<int>> res;
        sort(points.begin(), points.end());

        res.push_back(points[0]);

        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] <= res.back()[1])
            {
                res.back()[1] = min(res.back()[1], points[i][1]);
            }
            else
            {
                res.push_back(points[i]);
            }
        }

        return res.size();
    }
};