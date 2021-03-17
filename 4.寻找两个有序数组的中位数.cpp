/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 */

// @lc code=start
class Solution
{
public:
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     int n1=nums1.size();
    //     int n2=nums2.size();
    //     if(n1<n2)swap(nums1,nums2);
    //     nums1.insert(nums1.end(),nums2.begin(),nums2.end());
    //     sort(nums1.begin(),nums1.end());
    //     return ((double)nums1[(n1+n2-1)/2]+nums1[(n1+n2)/2])/2.0;
    // }
    int kth(int *a, int m, int *b, int n, int k)
    {
        if (m < n)
            return kth(b, n, a, m, k);
        if (n == 0)
            return a[k - 1];
        if (k == 1)
            return min(a[0], b[0]);

        int j = min(n, k / 2);
        int i = k - j;
        if (a[i - 1] > b[j - 1])
            return kth(a, i, b + j, n - j, k - j);
        return kth(a + i, m - i, b, j, k - i);
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int k = (n1 + n2) / 2;
        int m1 = kth(nums1.data(), n1, nums2.data(), n2, k + 1);
        if ((n1 + n2) % 2 == 0)
        {
            int m2 = kth(nums1.data(), n1, nums2.data(), n2, k);
            return ((double)m1 + m2) / 2.0;
        }
        return m1;
    }
};
// @lc code=end
