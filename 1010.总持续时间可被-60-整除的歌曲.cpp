/*
 * @lc app=leetcode.cn id=1010 lang=cpp
 *
 * [1010] 总持续时间可被 60 整除的歌曲
 */

// @lc code=start
class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        map<int, int> mp;
        for (int num : time)
        {
            num %= 60;
            mp[num]++;
        }
        int res = 0;
        for (auto [time, cnt] : mp)
        {
            if (time > 30)
                break;
            if (0 == time)
            {
                res += cnt * (cnt - 1) / 2;
            }
            else if (30 == time)
            {
                res += cnt * (cnt - 1) / 2;
            }
            else
            {
                if (mp.count(60 - time))
                {
                    res += cnt * mp[60 - time];
                }
            }
        }
        return res;
    }
};
// @lc code=end
