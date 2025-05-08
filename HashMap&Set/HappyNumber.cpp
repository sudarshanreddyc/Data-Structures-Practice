class Solution
{
public:
    long sumOfSquares(int n)
    {
        int sum = 0;
        while (n != 0)
        {
            sum = sum + (n % 10) * (n % 10);
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n)
    {
        unordered_set<int> seen;

        while (n != 1)
        {
            n = sumOfSquares(n);
            if (seen.count(n))
            {
                return false;
            }
            seen.insert(n);
        }

        return true;
    }
};