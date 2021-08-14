/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
class Solution
{
public:
    int totalFruit(vector<int> &a)
    {
        unordered_map<int, int> mp; //fruit,num;
        int n = a.size();
        int res = 0;
        int l = 0, r = 0;
        for (; r < n; ++r)
        {
            int f = a[r];
            if (mp.count(f))
                mp[f]++;
            else
            {
                if (mp.size() >= 2) //窗口滑动
                {
                    res = max(res, r - l);
                    while (mp.size() >= 2)
                    {
                        mp[a[l]]--;
                        if (0 == mp[a[l]])
                            mp.erase(a[l]);
                        ++l;
                    }
                }
                mp[f] = 1;
            }
        }
        res = max(res, r - l);
        return res;
    }
};
// @lc code=end
