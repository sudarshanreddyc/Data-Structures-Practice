//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int knapsackRecur(int W, vector<int> &val, vector<int> &wt, int n, vector<vector<int>> &dp)
    {
        if (W == 0 || n == 0)
            return 0;
        if (dp[W][n] != -1)
            return dp[W][n];
        if (wt[n - 1] > W)
            dp[W][n] = knapsackRecur(W, val, wt, n - 1, dp);
        else
            dp[W][n] = max(val[n - 1] + knapsackRecur(W - wt[n - 1], val, wt, n - 1, dp),
                           knapsackRecur(W - wt[n - 1], val, wt, n - 1, dp));
        return dp[W][n];
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        vector<vector<int>> dp(W + 1, vector<int>(val.size() + 1, -1));
        return knapsackRecur(W, val, wt, wt.size(), dp);
    }
};

//{ Driver Code Starts.

int main()
{
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--)
    {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number)
        {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number)
        {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends