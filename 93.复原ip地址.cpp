/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */

// @lc code=start
class Solution
{
public:
    vector<string> res;
    string tmp;
    int n = 0;
    void dfs(int cnt, int i, string &s)
    {
        int left = n - i;
        if (left < cnt || (3 * cnt) < left)
            return;
        if (1 == cnt)
        {
            if ('0' == s[i] && left != 1 || atoi(s.substr(i).c_str()) > 255)
                return;
            tmp += s.substr(i);
            res.emplace_back(tmp);
            tmp = tmp.substr(0, tmp.size() - left);
            return;
        }
        for (int k = 1; k <= 3; k++)
        {
            if ('0' == s[i] && k != 1)
                break;
            if (atoi(s.substr(i, k).c_str()) > 255)
                break;
            if (i + k > n)
                return;
            tmp += (s.substr(i, k) + '.');
            dfs(cnt - 1, i + k, s);
            tmp = tmp.substr(0, tmp.size() - k - 1);
            //tmp.erase(tmp.size() - k - 1, k + 1);
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        n = s.size();
        dfs(4, 0, s);
        return res;
    }
};
// @lc code=end
