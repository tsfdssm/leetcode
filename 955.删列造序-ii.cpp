/*
 * @lc app=leetcode.cn id=955 lang=cpp
 *
 * [955] 删列造序 II
 */

// @lc code=start
class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int n = strs.size();
        int m = strs[0].size();
        int res = 0;
        unordered_set<int> st;
        for (int i = 0; i < m; ++i)
        {
            int flag = 1;
            unordered_set<int> tmp;
            for (int j = 1; j < n; ++j)
            {
                if (st.count(j))
                    continue;
                if (strs[j - 1][i] < strs[j][i])
                {
                    tmp.insert(j);
                }
                else if (strs[j - 1][i] > strs[j][i])
                {
                    tmp.clear();
                    flag = -1;
                    break;
                }
                else
                {
                    flag = 0;
                }
            }
            st.insert(tmp.begin(), tmp.end());
            if (1 == flag)
                break;
            else if (-1 == flag)
                ++res;
        }
        return res;
    }
};
// @lc code=end
