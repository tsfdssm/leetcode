/*
 * @lc app=leetcode.cn id=915 lang=cpp
 *
 * [915] 分割数组
 */

// @lc code=start
class Solution
{
public:
    int partitionDisjoint(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> nxt(n);
        nxt[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            nxt[i] = min(nxt[i + 1], nums[i]);
        }
        int maxn = nums[0];
        for (int i = 1; i < n; ++i)
        {
            if (nxt[i] >= maxn)
                return i;
            else
                maxn = max(maxn, nums[i]);
        }
        return 0;
        // int n = nums.size();
        // map<int, int> mp;
        // for (int i = 0; i < n; ++i)
        //     mp[nums[i]] = i;

        // vector<int> nxt(n, INT_MAX);
        // nxt[n - 1] = nums[n - 1];
        // for (int i = n - 2; i >= 0; --i)
        // {
        //     nxt[i] = min(nxt[i + 1], nums[i]);
        // }
        // int idx = 0;
        // int maxn = nums[0];
        // int res = 0;
        // for (int i = 0; i < n; ++i)
        // {
        //     if (nums[i] < maxn)
        //     {
        //         idx = max(idx, mp[nums[i]]);
        //     }
        //     else if (nums[i] >= maxn)
        //     {
        //         if (nxt[i] >= maxn)
        //         {
        //             return max(i, 1);
        //         }
        //     }
        // }
        // return 0;
        // int n = nums.size();
        // map<int, int> mp;
        // for (int i = 0; i < n; ++i)
        //     mp[nums[i]] = i;
        // int res = 0;
        // int pivot = nums[0];
        // for (auto it = mp.begin(); it != mp.end(); ++it)
        // {
        //     if (it->first > pivot)
        //         break;
        //     else if (it->first > pivot)
        //         res = max(res, it->second);
        // }
        // return min(res + 1, n - 1);
    }
};
// @lc code=end
