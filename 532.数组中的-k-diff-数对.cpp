/*
 * @lc app=leetcode.cn id=532 lang=cpp
 *
 * [532] 数组中的 k-diff 数对
 */

// @lc code=start
class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        int res = 0;

        unordered_set<int> st;
        unordered_set<int> rep;
        for (int num : nums)
        {
            if (!st.count(num))
                st.emplace(num);
            else
                rep.emplace(num);
        }
        if (0 == k)
            return rep.size();
        for (auto it = st.begin(); it != st.end(); ++it)
        {
            if (st.count(*it + k))
                ++res;
        }
        return res;
    }
};
// @lc code=end
