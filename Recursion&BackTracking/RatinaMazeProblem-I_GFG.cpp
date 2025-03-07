//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function template for C++

class Solution
{
public:
    vector<string> res;
    vector<vector<int>> visited;
    bool isSafe(int i, int j, vector<vector<int>> &mat)
    {
        int n = mat.size();
        return i >= 0 && j >= 0 && i < n && j < n && mat[i][j] == 1 && visited[i][j] != 1;
    }
    void findPathRecur(int i, int j, vector<vector<int>> &mat, string s)
    {
        int n = mat.size();
        if (i == n - 1 && j == n - 1)
        {
            res.push_back(s);
            s = "";
            return;
        }
        visited[i][j] = 1;
        if (isSafe(i + 1, j, mat))
            findPathRecur(i + 1, j, mat, s + "D");
        if (isSafe(i, j + 1, mat))
            findPathRecur(i, j + 1, mat, s + "R");
        if (isSafe(i - 1, j, mat))
            findPathRecur(i - 1, j, mat, s + "U");
        if (isSafe(i, j - 1, mat))
            findPathRecur(i, j - 1, mat, s + "L");
        visited[i][j] = 0;
        return;
    }
    vector<string> findPath(vector<vector<int>> &mat)
    {
        visited.resize(mat.size(), vector<int>(mat.size(), 0));
        findPathRecur(0, 0, mat, "");
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input)
        {
            if (c == '[')
            {
                if (isInsideArray)
                {
                    innerArray.clear();
                }
                isInsideArray = true;
            }
            else if (c == ']')
            {
                if (isInsideArray && !innerArray.empty())
                {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num)
                    {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            }
            else if (isInsideArray)
            {
                if (!isspace(c))
                {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends