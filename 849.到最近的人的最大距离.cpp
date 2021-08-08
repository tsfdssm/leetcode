/*
 * @lc app=leetcode.cn id=849 lang=cpp
 *
 * [849] 到最近的人的最大距离
 */

// @lc code=start
class Solution
{
public:
    int maxDistToClosest(vector<int> &seats)
    {

        int n = seats.size();
        set<int> st;
        for (int i = 0; i < n; ++i)
        {
            if (1 == seats[i])
                st.insert(i);
        }

        int res = max(*st.begin(), n - 1 - *st.rbegin());

        for (auto it = st.begin(); next(it) != st.end(); ++it)
        {
            res = max(res, (*next(it) - *it) / 2);
        }
        return res;
    }
};
// @lc code=end
