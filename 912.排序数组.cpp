/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution
{
public:
    int partition(vector<int> &nums, int l, int r)
    {
        int pivot = nums[r];
        int i = l;
        for (int j = l; j < r; ++j)
        {
            if (nums[j] <= pivot)
            {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[r]);
        return i;
        // int tmp = r;
        // int pivot = nums[r];
        // while (l < r)
        // {
        //     while (l < r && nums[l] < pivot)
        //         ++l;
        //     while (l < r && nums[r] >= pivot)
        //         --r;
        //     if (l == r)
        //         break;
        //     swap(nums[l], nums[r]);
        // }
        // swap(nums[l], nums[tmp]);
        // return l;
    }
    int random_partition(vector<int> &nums, int l, int r)
    {
        int i = random() % (r - l + 1) + l;
        swap(nums[r], nums[i]);
        return partition(nums, l, r);
    }
    void quik_sort(vector<int> &nums, int l, int r)
    {
        if (l >= r)
            return;
        int pos = random_partition(nums, l, r);
        quik_sort(nums, l, pos - 1);
        quik_sort(nums, pos + 1, r);
    }
    vector<int> sortArray(vector<int> &nums)
    {
        quik_sort(nums, 0, nums.size() - 1);
        return nums;
        // sort(nums.begin(), nums.end());
        // return nums;
    }
};
// @lc code=end
