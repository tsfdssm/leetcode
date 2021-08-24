/*
 * @lc app=leetcode.cn id=948 lang=cpp
 *
 * [948] 令牌放置
 */

// @lc code=start
class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        int n = tokens.size();
        if (0 == n)
            return 0;
        sort(tokens.begin(), tokens.end());
        if (power < tokens[0])
            return 0;

        int l = 0, r = n - 1;
        long long sum = accumulate(tokens.begin(), tokens.end(), (long long)0);
        int res = 0;
        long long tmp = 0;
        for (; res < n; ++res)
        {
            tmp += tokens[res];
            if (tmp > power)
                break;
        }
        while (l < r)
        {
            power += tokens[r] - tokens[l];
            sum -= (long long)tokens[r] + tokens[l];
            ++l;
            --r;
            if (sum <= power)
            {
                res = max(res, r - l + 1);
                break;
            }
            long long tmp = 0;
            for (int i = l; i <= r; ++i)
            {
                tmp += tokens[i];
                if (tmp > power)
                {
                    res = max(res, i - l);
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end
