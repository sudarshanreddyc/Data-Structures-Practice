class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int r = matrix.size(), c = matrix[0].size();

        vector<vector<int>> rotated(c, vector<int>(r));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                rotated[c - j - 1][i] = matrix[i][j];
            }
        }
        matrix = rotated;
    }

    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        while (!matrix.empty())
        {
            int c = matrix[0].size();
            for (int j = 0; j < c; j++)
            {
                res.push_back(matrix[0][j]);
            }

            // Remove first row;
            matrix.erase(matrix.begin());
            // Rotate and reverse the matrix so that last column will become the first row.
            if (!matrix.empty())
                rotate(matrix);
        }

        return res;
    }
};