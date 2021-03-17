/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> l(n), r(n, n);

        stack<int> st;
        for (int i = 0; i < heights.size(); i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                r[st.top()] = i;
                st.pop();
            }
            l[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res = max(res, (r[i] - l[i] - 1) * heights[i]);
        }
        return res;
    }
};
// @lc code=end
