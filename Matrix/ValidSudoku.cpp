class Solution
{
public:
    bool isValidUnit(vector<char> &unit)
    {
        unordered_set<int> st;
        for (int i = 0; i < unit.size(); i++)
        {
            if (unit[i] != '.' && st.count(unit[i]))
            {
                return false;
            }
            st.insert(unit[i]);
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>> &board)
    {

        // Check if rows are valid
        for (int row = 0; row < 9; row++)
        {
            if (!isValidUnit(board[row]))
                return false;
        }

        // Check if columns are valid
        for (int column = 0; column < 9; column++)
        {
            vector<char> oneColumn;
            for (int row = 0; row < 9; row++)
            {
                oneColumn.push_back(board[row][column]);
            }
            if (!isValidUnit(oneColumn))
                return false;
        }

        // Check if each 3X3 cell is valid;
        for (int row = 0; row < 9; row += 3)
        {
            for (int column = 0; column < 9; column += 3)
            {
                vector<char> box;
                for (int boxRow = row; boxRow < row + 3; boxRow++)
                {
                    for (int boxColumn = column; boxColumn < column + 3; boxColumn++)
                    {
                        box.push_back(board[boxRow][boxColumn]);
                    }
                }
                if (!isValidUnit(box))
                    return false;
            }
        }
        return true;
    }
};