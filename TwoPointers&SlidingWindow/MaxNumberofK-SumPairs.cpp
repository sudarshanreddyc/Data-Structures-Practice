#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end()); // Step 1: Sort the array
        int left = 0, right = nums.size() - 1;
        int res = 0;

        // Step 2: Two-pointer technique
        while (left < right)
        {
            int sum = nums[left] + nums[right];

            if (sum == k)
            {
                res++;   // Found a valid pair
                left++;  // Move left pointer inward
                right--; // Move right pointer inward
            }
            else if (sum < k)
            {
                left++; // Increase sum by moving left pointer
            }
            else
            {            // sum > k
                right--; // Decrease sum by moving right pointer
            }
        }

        return res; // Return the total number of pairs
    }
};