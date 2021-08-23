/*
 * @lc app=leetcode.cn id=937 lang=cpp
 *
 * [937] 重新排列日志文件
 */

// @lc code=start
class Solution
{
public:
    vector<string> reorderLogFiles(vector<string> &logs)
    {
        vector<string> str_char;
        vector<string> str_digit;
        int n = logs.size();
        auto isStrDigit = [](const string &s) -> bool {
            int n = s.size();
            int i = 0;
            while (i < n && s[i] != ' ')
                ++i;
            ++i;
            return '0' <= s[i] && s[i] <= '9';
        };
        for (int i = 0; i < n; ++i)
        {
            if (isStrDigit(logs[i]))
                str_digit.emplace_back(logs[i]);
            else
                str_char.emplace_back(logs[i]);
        }
        auto cmp = [](const string &a, const string &b) {
            int m = a.size();
            int n = b.size();
            int i = 0, j = 0;
            while (i < m && a[i] != ' ')
                ++i;
            while (j < n && b[j] != ' ')
                ++j;
            string tmpa = a.substr(i);
            string tmpb = b.substr(j);
            if (tmpa != tmpb)
                return tmpa < tmpb;
            return a.substr(0, i) < b.substr(0, j);
        };
        sort(str_char.begin(), str_char.end(), cmp);
        str_char.insert(str_char.end(), str_digit.begin(), str_digit.end());
        return str_char;
    }
};
// @lc code=end
