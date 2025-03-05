#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // You need to complete this function

    long long tohHelper(int n, int from, int to, int aux)
    {
        if (n == 1)
        {
            cout << "move disk " << n << " from rod " << from << " to rod " << to << "\n";
            return 1;
        }

        // First move n-1 rods from "from" to "aux"
        long long steps = tohHelper(n - 1, from, aux, to);

        // Move nth rod from "from" to "to"
        cout << "move disk " << n << " from rod " << from << " to rod " << to << "\n";
        steps += 1;

        // Move n-1 rods which were moved to aux in the first step from "aux" to "to"
        steps += tohHelper(n - 1, aux, to, from);
        return steps;
    }

    // avoid space at the starting of the string in "move disk....."
    long long toh(int n, int from, int to, int aux)
    {
        return tohHelper(n, from, to, aux);
    }
};

int main()
{

    int T;
    cin >> T; // testcases
    while (T--)
    {

        int N;
        cin >> N; // taking input N

        // calling toh() function
        Solution ob;

        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}