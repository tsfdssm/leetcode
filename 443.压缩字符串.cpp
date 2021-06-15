/*
 * @lc app=leetcode.cn id=443 lang=cpp
 *
 * [443] 压缩字符串
 */

// @lc code=start
class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int l = 0, r = 0;
        int n = chars.size();
        while (r < n)
        {
            char c = chars[r];
            int ed = r + 1;
            while (ed < n && chars[ed] == c)
                ++ed;
            int len = ed - r;
            r = ed;
            chars[l] = c;
            ++l;
            if (1 != len)
            {
                string tmp = to_string(len);
                for (int i = 0; i < tmp.size(); ++i)
                {
                    chars[l] = tmp[i];
                    ++l;
                }
            }
        }
        return l;
    }
};
// @lc code=end
