/*
 * @lc app=leetcode.cn id=1906 lang=cpp
 *
 * [1906] 查询差绝对值的最小值
 */

// @lc code=start
class Solution
{
public:
    vector<int> minDifference(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        const int k = 101;
        vector<vector<int>> all(n, vector<int>(k, 0));
        all[0][nums[0]]++;
        for (int i = 1; i < n; ++i)
        {
            all[i] = all[i - 1];
            all[i][nums[i]]++;
        }
        int m = queries.size();
        vector<int> res(m, 0);
        for (int i = 0; i < m; ++i)
        {
            auto &q = queries[i];
            auto tmp = all[q[1]];
            if (q[0] != 0)
                for (int j = 1; j < k; ++j)
                    tmp[j] -= all[q[0] - 1][j];
            int resk = k;
            int st = 0;
            while (st < k && (tmp[st] == 0))
                ++st;
            while (st < k)
            {
                int ed = st + 1;
                while (ed < k && (tmp[ed] == 0))
                    ++ed;
                if (ed == k)
                    break;
                resk = min(resk, ed - st);
                st = ed;
            }
            res[i] = resk == k ? -1 : resk;
        }
        return res;
    }
};
// @lc code=end
