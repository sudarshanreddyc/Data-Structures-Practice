#include <iostream>
using namespace std;

class Solution
{
public:
    int addDigitsHelper(int num, int result = 0)
    {
        if (num <= 0)
        {
            return result > 0 && result % 9 == 0 ? 9 : result % 9;
        }
        result += num % 10;
        return addDigitsHelper(num / 10, result);
    }

    int addDigits(int num)
    {
        return addDigitsHelper(num);
    }
};

int main()
{
    Solution solution;
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int result = solution.addDigits(num);
    cout << "The result of adding the digits is: " << result << endl;

    return 0;
}
