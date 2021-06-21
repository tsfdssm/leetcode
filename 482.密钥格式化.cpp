/*
 * @lc app=leetcode.cn id=482 lang=cpp
 *
 * [482] 密钥格式化
 */

// @lc code=start
class Solution
{
public:
    string licenseKeyFormatting(string &s, int k)
    {
        int n = s.size();
        vector<string> vec;
        string tmp;
        for (int i = n - 1; i >= 0; --i)
        {
            if ('-' == s[i])
                continue;
            char c = s[i];
            if ('a' <= c && c <= 'z')
                c += 'A' - 'a';
            tmp += c;
            if (tmp.size() == k)
            {
                reverse(tmp.begin(), tmp.end());
                vec.emplace_back(tmp);
                tmp.clear();
            }
        }
        if (0 != tmp.size())
        {
            reverse(tmp.begin(), tmp.end());
            vec.emplace_back(tmp);
            tmp.clear();
        }
        string res;
        if (vec.empty())
            return "";
        else
            res = vec.back();
        for (int i = vec.size() - 2; i >= 0; --i)
            res += "-" + vec[i];
        return res;
    }
};
// @lc code=end
