/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */

// @lc code=start
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        set<int> st;
        for (int num : nums)
            st.insert(num);
        if (st.size() < 3)
            return *--st.end();
        else
            return *(------st.end());
    }
};
// @lc code=end
