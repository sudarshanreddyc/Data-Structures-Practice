
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find element with more appearances between two elements in an
    // array.
    int majorityWins(int arr[], int n, int x, int y)
    {
        int counterForx = 0, counterFory = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == x)
                counterForx++;
            if (arr[i] == y)
                counterFory++;
        }

        if (counterForx > counterFory)
            return x;
        else if (counterFory > counterForx)
            return y;
        else
            return min(x, y);
    }
};

int main()
{

    int t;      // Testcases
    cin >> t;   // Input the testcases
    while (t--) // Until all testcases are exhausted
    {
        int n;      // Size of array
        cin >> n;   // Input the size
        int arr[n]; // Declaring array of size n
        for (int i = 0; i < n;
             i++) // Running a loop to input all elements of arr
            cin >> arr[i];

        int x, y;      // declare x and y
        cin >> x >> y; // input x and y
        Solution obj;
        cout << obj.majorityWins(arr, n, x, y)
             << endl; // calling the function that you complete

        cout << "~" << "\n";
    }

    return 0;
}
