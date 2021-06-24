/*
 * @lc app=leetcode.cn id=523 lang=cpp
 *
 * [523] 连续的子数组和
 */

// @lc code=start
class Solution
{
public:
    // vector<int> tree;

    // inline int lowbit(int i)
    // {
    //     return i & -i;
    // }

    // int find(int i)
    // {
    //     int res = 0;
    //     while (i > 0)
    //     {
    //         res += tree[i];
    //         i -= lowbit(i);
    //     }
    //     return res;
    // }

    // void update(int i, int x)
    // {
    //     int n = tree.size() - 1;
    //     while (i <= n)
    //     {
    //         tree[i] += x;
    //         i += lowbit(i);
    //     }
    // }

    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        // tree.resize(n + 1, 0);
        // for (int i = 0; i < n; ++i)
        //     update(i + 1, nums[i]);

        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum = (sum + nums[i]) % k;
            if (!mp.count(sum))
                mp[sum] = i;
            else if (i - mp[sum] >= 2)
                return true;
        }
        return false;
    }
};
// @lc code=end
