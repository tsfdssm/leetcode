/*
 * @lc app=leetcode.cn id=808 lang=cpp
 *
 * [808] 分汤
 */

// @lc code=start
class Solution
{
public:
    double soupServings(int n)
    {
        double a = 0.0;
        double b = 0.0;
        double ab = 0.0;
        n = n / 25 + (n % 25 > 0 ? 1 : 0);
        if (n > 500)
            return 1.0;
        int dir_a[4] = {4, 3, 2, 1};
        int dir_b[4] = {0, 1, 2, 3};
        map<pair<int, int>, double> mp;
        mp[{n, n}] = 1.0;
        while (!mp.empty())
        {
            map<pair<int, int>, double> nxt;
            for (auto it = mp.begin(); it != mp.end(); ++it)
            {
                int cur_a = it->first.first;
                int cur_b = it->first.second;
                double prob = it->second;
                for (auto k = 0; k < 4; ++k)
                {
                    int tmpa = dir_a[k];
                    int tmpb = dir_b[k];
                    if (cur_a > tmpa && cur_b > tmpb)
                        nxt[{cur_a - tmpa, cur_b - tmpb}] += prob / 4;
                    else if (cur_a <= tmpa && cur_b <= tmpb)
                        ab += prob / 4;
                    else if (cur_a > tmpa && cur_b <= tmpb)
                    {
                        //nxt[{cur_a - tmpa, 0}] += prob / 4;
                        b += prob / 4;
                    }
                    else
                    {
                        //nxt[{0, cur_b - tmpb}] += prob / 4;
                        a += prob / 4;
                    }
                }
            }
            mp = move(nxt);
        }
        return a + ab / 2;
    }
};
// @lc code=end
