class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        string res = "";
        int increment;
        int size = s.length();
        for (int r = 0; r < numRows; r++)
        {
            increment = 2 * (numRows - 1);
            for (int j = r; j < size; j += increment)
            {
                res += s[j];
                if (r > 0 && r < numRows - 1 && (j + increment - 2 * r) < size)
                {
                    res += s[j + increment - 2 * r];
                }
            }
        }
        return res;
    }
};