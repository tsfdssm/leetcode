/*
 * @lc app=leetcode.cn id=771 lang=cpp
 *
 * [771] 宝石与石头
 */

// @lc code=start
class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        set<char> st;
        for (char c : jewels)
            st.insert(c);
        int res = 0;
        for (char c : stones)
            if (st.count(c))
                res++;
        return res;
    }
};
// @lc code=end
