/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // for (int i = 0; i < n; i++)
        //     nums1[m + i] = nums2[i];
        // sort(nums1.begin(), nums1.end());
        nums1.resize(m + n);
        int i = m - 1, j = n - 1;
        int cur = m + n - 1;
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[cur] = nums1[i];
                i--;
            }
            else
            {
                nums1[cur] = nums2[j];
                j--;
            }
            cur--;
        }
        while (j >= 0)
            nums1[cur--] = nums2[j--];
    }
};
// @lc code=end
