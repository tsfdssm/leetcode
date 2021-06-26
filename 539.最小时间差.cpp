/*
 * @lc app=leetcode.cn id=539 lang=cpp
 *
 * [539] 最小时间差
 */

// @lc code=start
class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        set<int> st;
        int res = INT_MAX;
        for (const string &s : timePoints)
        {
            int n = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
            if (st.count(n))
                return 0;
            st.insert(n);
        }
        auto it1 = st.begin();
        auto it2 = st.begin();
        ++it1;
        while (it1 != st.end())
        {
            res = min(res, *it1 - *it2);
            ++it1;
            ++it2;
        }
        res = min(res, 1440 + *st.begin() - *st.rbegin());
        return res;
    }
};
// @lc code=end
