/*
 * @lc app=leetcode.cn id=710 lang=cpp
 *
 * [710] 黑名单中的随机数
 */

// @lc code=start
class Solution
{
public:
    int mod;
    unordered_map<int, int> mp;
    Solution(int n, vector<int> &blacklist)
    {
        mod = n - blacklist.size();

        for (int num : blacklist)
            if (num >= mod)
                mp[num] = num;
        int index = 0;
        for (int num : blacklist)
        {
            if (num < mod)
            {
                while (mp.count(mod + index))
                    ++index;
                mp[num] = mod + index;
                ++index;
            }
        }
    }

    int pick()
    {
        int res = random() % mod;
        if (mp.count(res))
            return mp[res];
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
// @lc code=end
