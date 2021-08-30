/*
 * @lc app=leetcode.cn id=985 lang=cpp
 *
 * [985] 查询后的偶数和
 */

// @lc code=start
class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        int q = queries.size();
        int sum = 0;
        vector<int> res(q);
        for (int i = 0; i < n; ++i)
            if (!(nums[i] & 1))
                sum += nums[i];
        for (int i = 0; i < q; ++i)
        {
            int val = queries[i][0];
            int idx = queries[i][1];
            int cur = nums[idx];
            if (!(cur & 1))
                sum -= cur;
            cur += val;
            nums[idx] = cur;
            if (!(cur & 1))
                sum += cur;
            res[i] = sum;
        }
        return res;
    }
};
// @lc code=end
