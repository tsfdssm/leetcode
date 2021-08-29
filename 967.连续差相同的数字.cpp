/*
 * @lc app=leetcode.cn id=967 lang=cpp
 *
 * [967] 连续差相同的数字
 */

// @lc code=start
class Solution
{
public:
    vector<int> numsSameConsecDiff(int n, int k)
    {
        vector<int> res;
        string tmp;
        function<void(int)> dfs = [&](int idx) {
            if (idx == n)
            {
                if (n > 1 && tmp[0] == '0')
                    return;
                res.emplace_back(stoi(tmp));
            }
            else
            {
                for (char i = '0'; i <= '9'; ++i)
                {
                    if ((0 == idx) || (abs(i - tmp.back()) == k))
                    {
                        tmp.push_back(i);
                        dfs(idx + 1);
                        tmp.pop_back();
                    }
                }
            }
        };
        dfs(0);
        return res;
    }
};
// @lc code=end
