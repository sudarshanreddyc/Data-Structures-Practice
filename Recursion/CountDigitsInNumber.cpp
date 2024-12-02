#include <iostream>
using namespace std;

class Solution
{
public:
    // Complete this function
    int countDigits(int n)
    {
        if (n <= 0)
            return 0;
        return 1 + countDigits(n / 10);
    }
};

int main()
{
    int T;

    // taking testcases
    cin >> T;
    while (T--)
    {
        int n;

        // taking number n
        cin >> n;

        // calling countDigits
        Solution obj;
        cout << obj.countDigits(n) << endl;
    }
    return 0;
}
