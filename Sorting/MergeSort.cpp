class Solution
{
public:
    void merge(vector<int> left, vector<int> right, vector<int> &nums)
    {
        int i = 0, j = 0, k = 0;

        while (i < left.size() && j < right.size())
        {
            if (left[i] <= right[j])
            {
                nums[k++] = left[i++];
            }
            else
            {
                nums[k++] = right[j++];
            }
        }
        while (i < left.size())
        {
            nums[k++] = left[i++];
        }
        while (j < right.size())
        {
            nums[k++] = right[j++];
        }
    }
    void mergeSort(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return;

        int mid = n / 2;
        vector<int> left(mid);
        vector<int> right(n - mid);
        for (int i = 0; i < mid; i++)
        {
            left[i] = nums[i];
        }

        for (int i = mid; i < n; i++)
        {
            right[i - mid] = nums[i];
        }
        mergeSort(left);
        mergeSort(right);

        merge(left, right, nums);
    }
    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(nums);
        return nums;
    }
};