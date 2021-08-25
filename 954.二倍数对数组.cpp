/*
 * @lc app=leetcode.cn id=954 lang=cpp
 *
 * [954] 二倍数对数组
 */

// @lc code=start
class Solution
{
public:
    bool canReorderDoubled(vector<int> &arr)
    {
        int n = arr.size();
        multiset<int> st;
        int cnt0 = 0;
        for (int i = 0; i < n; ++i)
        {
            if (arr[i] != 0)
                st.insert(arr[i]);
            else
                cnt0++;
        }
        if (cnt0 % 2 == 1)
            return false;
        for (auto it = st.begin(); it != st.end();)
        {
            int cur = *it;
            auto f = st.find(2 * cur);
            if (f == st.end())
            {
                ++it;
                continue;
            }
            st.erase(it++);
            if (it == f)
            {
                it = st.erase(f);
            }
            else
            {
                st.erase(f);
            }
        }
        return st.empty();
    }
};
// @lc code=end
