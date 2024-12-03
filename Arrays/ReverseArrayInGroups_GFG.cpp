//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void reverseInGroups(vector<long long int> &arr, int k)
    {
        int n = arr.size();
        for (int i = 0; i < n; i += k)
        {
            int start = i, end = min(i + k - 1, n - 1);
            while (start < end)
            {
                swap(arr[start], arr[end]);
                start++;
                end--;
            }
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        vector<long long int> arr;
        string input;
        cin.ignore();
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        Solution ob;
        ob.reverseInGroups(arr, k);
        for (long long i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
