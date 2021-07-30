/*
 * @lc app=leetcode.cn id=805 lang=cpp
 *
 * [805] 数组的均值分割
 */

// @lc code=start
class Solution
{
public:
    bool splitArraySameAverage(vector<int> &nums)
    {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < n; ++i)
        {
            nums[i] *= n;
            nums[i] -= sum;
        }
        sum = accumulate(nums.begin(), nums.begin() + n / 2, 0);
        if ((n >= 2) && sum == 0)
            return true;
        set<int> st1 = solve(nums.begin(), nums.begin() + n / 2);
        set<int> st2 = solve(nums.begin() + n / 2, nums.end());
        st1.insert(sum);
        for (auto num : st1)
        {
            if (st2.count(-num))
                return true;
        }
        return false;
    }

    set<int> solve(vector<int>::iterator l, vector<int>::iterator r)
    {
        int len = r - l;
        const int inf = 0x3f3f3f3f;
        vector<int> dp(1 << len, inf);
        dp[0] = 0;
        for (int i = 0; i < (1 << len) - 1; ++i)
        {
            for (int j = 0; j < len; ++j)
            {
                if (i & (1 << j))
                    continue;
                int k = i + (1 << j);
                if (dp[k] != inf)
                    continue;
                dp[k] = dp[i] + *(l + j);
            }
        }
        set<int> st;
        for (int i = 1; i < (1 << len) - 1; ++i)
        {
            st.insert(dp[i]);
        }
        return st;
    }
};
// @lc code=end
