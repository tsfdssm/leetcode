/*
 * @lc app=leetcode.cn id=888 lang=cpp
 *
 * [888] 公平的糖果棒交换
 */

// @lc code=start
class Solution
{
public:
    vector<int> fairCandySwap(vector<int> &a, vector<int> &b)
    {
        //swap(a, b);
        int diff = accumulate(a.begin(), a.end(), 0) - accumulate(b.begin(), b.end(), 0);
        diff >>= 1;
        unordered_set<int> st(b.begin(), b.end());
        for (int aa : a)
        {
            if (st.count(aa - diff))
                return {aa, aa - diff};
        }
        return {0, 0};
    }
};
// @lc code=end
