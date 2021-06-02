/*
 * @lc app=leetcode.cn id=363 lang=cpp
 *
 * [363] 矩形区域不超过 K 的最大数值和
 */

// @lc code=start
class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        int res = INT_MIN;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> tmp(n);
        set<int> st;
        for (int i = 0; i < m; ++i)
        {
            fill(tmp.begin(), tmp.end(), 0);
            for (int j = i; j < m; ++j)
            {
                for (int k = 0; k < n; ++k)
                    tmp[k] += matrix[j][k];
                st.clear();
                st.insert(0);
                int sum = 0;
                for (int colomn : tmp)
                {
                    sum += colomn;
                    auto it = st.lower_bound(sum - k);
                    if (it != st.end())
                    {
                        res = max(res, sum - *it);
                    }
                    st.insert(sum);
                }
            }
        }
        return res;
    }
};
// @lc code=end
