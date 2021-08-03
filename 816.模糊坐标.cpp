/*
 * @lc app=leetcode.cn id=816 lang=cpp
 *
 * [816] 模糊坐标
 */

// @lc code=start
class Solution
{
public:
    vector<string> ambiguousCoordinates(string s)
    {
        vector<string> res;
        string str = s.substr(1, s.size() - 2);
        int n = str.size();
        for (int i = 0; i < n - 1; ++i)
        {

            for (int j = 0; j <= i; ++j)
            {
                if (str[0] == '0' && j > 0)
                    continue;
                string s1;
                if (j == i)
                {
                    s1 = str.substr(0, i + 1);
                }
                else
                {
                    if (str[i] == '0')
                        continue;
                    s1 = str.substr(0, j + 1) + "." + str.substr(j + 1, i - j);
                }
                for (int k = i + 1; k < n; ++k)
                {
                    if (str[i + 1] == '0' && k - i > 1)
                        continue;
                    string s2;
                    if (k == n - 1)
                    {
                        s2 = str.substr(i + 1);
                    }
                    else
                    {
                        if (str[n - 1] == '0')
                            continue;
                        s2 = str.substr(i + 1, k - i) + "." + str.substr(k + 1);
                    }
                    res.emplace_back("(" + s1 + ", " + s2 + ")");
                }
            }
        }
        return res;
    }
};
// @lc code=end
