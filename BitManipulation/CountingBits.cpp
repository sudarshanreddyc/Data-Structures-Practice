class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> res;
        for (int i = 0; i <= n; i++)
        {
            int num = i;
            int count = 0;
            while (num != 0)
            {
                if ((num & 1) == 1)
                    count++;
                num >>= 1;
            }
            res.push_back(count);
        }
        return res;
    }
};