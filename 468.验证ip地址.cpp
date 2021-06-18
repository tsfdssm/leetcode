/*
 * @lc app=leetcode.cn id=468 lang=cpp
 *
 * [468] 验证IP地址
 */

// @lc code=start
class Solution
{
public:
    // vector<string> split(string s, char spliter)
    // {
    //     vector<string> ans;
    //     int it;
    //     while ((it = s.find(spliter)) && it != s.npos)
    //     {
    //         ans.push_back(s.substr(0, it));
    //         s = s.substr(it + 1);
    //     }
    //     ans.push_back(s);
    //     return ans;
    // }

    vector<string> split(const string &s, const char c)
    {
        vector<string> res;
        int n = s.size();
        for (int i = 0; i < n;)
        {
            if (s[i] == c)
                ++i;
            int j = i;
            while (j < n && s[j] != c)
                ++j;
            res.emplace_back(s.substr(i, j - i));
            i = j;
        }
        return res;
    }
    bool isIPV4(const string &s)
    {
        vector<string> res = split(s, '.');
        if (4 != res.size())
            return false;
        for (const auto &num : res)
        {
            if (num.size() < 1 || num.size() > 3 || num[0] == '0' && num.size() > 1)
                return false;
            for (const char c : num)
            {
                if (c >= '0' && c <= '9')
                    continue;
                else
                    return false;
            }
            if (stoi(num) > 255 || stoi(num) < 0)
                return false;
        }
        return true;
    }

    bool isIPV6(const string &s)
    {
        vector<string> res = split(s, ':');
        if (8 != res.size())
            return false;
        for (const auto &num : res)
        {
            if (num.size() < 1 || num.size() > 4)
                return false;
            for (const char c : num)
            {
                if (c >= '0' && c <= '9' || c >= 'a' && c <= 'f' || c >= 'A' && c <= 'F')
                    continue;
                else
                    return false;
            }
        }
        return true;
    }
    string validIPAddress(string IP)
    {
        if (isIPV4(IP))
            return "IPv4";
        if (isIPV6(IP))
            return "IPv6";
        return "Neither";
    }
};
// @lc code=end
