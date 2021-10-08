/*
 * @lc app=leetcode.cn id=1016 lang=cpp
 *
 * [1016] 子串能表示从 1 到 N 数字的二进制串
 */

// @lc code=start
class Solution
{
public:
    bool queryString(string s, int n)
    {
        unordered_set<int> covers;
        int sn = s.size();
        if (n > sn * sn)
            return false;
        for (int i = 0; i < sn; ++i)
        {
            // 忽略 0xx的清卡
            if (s[i] == '0')
            {
                continue;
            }

            int curr = 0;
            for (int j = i; j < sn; ++j)
            {
                curr = (curr << 1) + s[j] - '0';
                // 大于情况下就无需再遍历下去
                if (curr > n)
                {
                    break;
                }

                covers.insert(curr);
            }
        }

        return covers.size() == n;
    }
};
// @lc code=end
