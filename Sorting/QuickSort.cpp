class Solution
{
public:
    int partition(vector<int> &nums, int start, int end)
    {
        int pivotIndex = start;
        int pivot = nums[end];
        for (int i = start; i < end; i++)
        {
            if (nums[i] < pivot)
            {
                swap(nums[pivotIndex++], nums[i]);
            }
        }
        swap(nums[pivotIndex], nums[end]);
        return pivotIndex;
    }
    void quickSort(vector<int> &nums, int start, int end)
    {
        if (start >= end)
            return;
        int pivotIndex = partition(nums, start, end);
        quickSort(nums, start, pivotIndex - 1);
        quickSort(nums, pivotIndex + 1, end);
    }
    vector<int> sortArray(vector<int> &nums)
    {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};