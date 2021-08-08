/*
 * @lc app=leetcode.cn id=842 lang=cpp
 *
 * [842] 将数组拆分成斐波那契序列
 */

// @lc code=start
class Solution
{
public:
    vector<int> splitIntoFibonacci(string num)
    {
        int n = num.size();
        vector<int> res;
        long long prepre;
        long long pre;
        for (int i = 1; i < n - 1 && i < 9; ++i)
        {
            if (num[0] == '0' && i > 1)
                continue;
            for (int j = 1; i + j < n && j < 9; ++j)
            {
                if ('0' == num[i] && j > 1)
                    continue;
                res.clear();
                prepre = stoi(num.substr(0, i));
                pre = stoi(num.substr(i, j));
                res.emplace_back(prepre);
                res.emplace_back(pre);
                int k = i + j;
                while (k < n)
                {
                    long long now = prepre + pre;
                    if (now > INT_MAX)
                        break;
                    string cur = to_string(prepre + pre);
                    if (cur.size() + k > n)
                        break;
                    if (num.substr(k, cur.size()) != cur)
                        break;

                    res.emplace_back(now);
                    if (cur.size() + k == n)
                        return res;
                    prepre = pre;
                    pre = now;
                    k += cur.size();
                }
            }
        }
        return {};
    }
};
// @lc code=end
