class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // Transpose the matrix first
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse each row of the matrix
        for (int i = 0; i < n; i++)
        {
            int left = 0;
            int right = n - 1;
            while (left < right)
            {
                swap(matrix[i][left++], matrix[i][right--]);
            }
        }
    }
};