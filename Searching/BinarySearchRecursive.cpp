/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
    int guessBinarySearch(int n, int l, int r)
    {
        int mid = l + (r - l) / 2;
        int apiResponse = guess(mid);
        if (apiResponse == 0)
            return mid;
        else if (apiResponse == -1)
            return guessBinarySearch(n, l, mid - 1);
        else
            return guessBinarySearch(n, mid + 1, r);
    }
    int guessNumber(int n)
    {
        return guessBinarySearch(n, 0, n);
    }
};