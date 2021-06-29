/*
 * @lc app=leetcode.cn id=575 lang=cpp
 *
 * [575] 分糖果
 */

// @lc code=start
class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        int n = candyType.size();
        n >>= 1;
        unordered_set<int> st;
        for (const int num : candyType)
        {
            st.insert(num);
            if (st.size() >= n)
                return n;
        }
        return st.size();
    }
};
// @lc code=end
