class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        // int currentZeros = 0, maxCount = 0;
        // int l = 0, r = 0;
        // while(r < nums.size()){
        //     if(nums[r++] == 0) currentZeros++; //Count zeros
        //     while(currentZeros > k){ //If count > k then shrink the window from left untile count comes less than or equal to k again
        //         if(nums[l] == 0){
        //             currentZeros--;
        //         }
        //         l++;
        //     }
        //     maxCount = max(maxCount, r-l);
        // }
        // return maxCount;

        int currentZeros = 0, maxCount = 0;
        int l = 0, r = 0;
        while (r < nums.size())
        {
            if (nums[r] == 0)
                currentZeros++;
            if (currentZeros <= k)
            { // Check if count of zeros in the current window is less than k, then only update maxCount
                maxCount = max(maxCount, r - l + 1);
            }
            // Shrink the window from left, if found zeros please decrease it from currentZeros
            else if (nums[l++] == 0)
                currentZeros--;
            r++;
        }
        return maxCount;
    }
};