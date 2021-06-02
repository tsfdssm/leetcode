/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_set<int> st;
        set<int> res;
        for (int &num : nums1)
            st.insert(num);
        for (int &num : nums2)
            if (st.count(num))
                res.insert(num);
        // if (n1 > n2)
        // {
        //     for (int num : nums1)
        //         st.insert(num);
        //     for (int num : nums2)
        //         if (st.count(num))
        //             res.insert(num);
        // }
        // else
        // {
        //     for (int num : nums2)
        //         st.insert(num);
        //     for (int num : nums1)
        //         if (st.count(num))
        //             res.insert(num);
        // }
        return vector<int>(res.begin(), res.end());
    }
};
// @lc code=end
