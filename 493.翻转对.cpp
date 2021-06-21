/*
 * @lc app=leetcode.cn id=493 lang=cpp
 *
 * [493] 翻转对
 */

// @lc code=start
class Solution
{
public:
    vector<int> tree;
    inline int lowbit(int i)
    {
        return i & (-i);
    }

    int get(int i)
    {
        int res = 0;
        while (i)
        {
            res += tree[i];
            i -= lowbit(i);
        }
        return res;
    }

    void update(int i, int x)
    {
        int n = tree.size();
        while (i < n)
        {
            tree[i] += x;
            i += lowbit(i);
        }
    }
    int reversePairs(vector<int> &nums)
    {
        set<long long> st;
        unordered_map<long long, int> mp;
        for (const int num : nums)
        {
            st.insert((long long)num);
            st.insert((long long)num * 2);
        }
        int idx = 0;
        for (const auto num : st)
            mp[num] = ++idx;

        int n = st.size();
        tree.resize(n + 1, 0);
        int res = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            res += get(n) - get(mp[(long long)nums[i] * 2]);
            update(mp[nums[i]], 1);
        }
        return res;
        // int n = nums.size();
        // vector<int> dp(n, 0);

        // for (int j = 1; j < n; ++j)
        // {
        //     dp[j] += dp[j - 1];
        //     for (int i = j - 1; i >= 0; --i)
        //     {
        //         if (((long)nums[i] + 1) / 2 > nums[j])
        //             dp[j]++;
        //         if (nums[i] <= nums[j])
        //         {
        //             dp[j] += dp[i];
        //             break;
        //         }
        //     }
        // }
        // return dp[n - 1];
    }
};
// @lc code=end
