/*
 * @lc app=leetcode.cn id=880 lang=cpp
 *
 * [880] 索引处的解码字符串
 */

// @lc code=start
class Solution
{
public:
    string decodeAtIndex(string s, int k)
    {
        long long len = 0;
        int n = s.size();
        vector<string> strs;
        vector<long long> cnts;
        vector<long long> lens;
        for (int i = 0; i < n;)
        {
            int j = i + 1;
            while (j < n && isChar(s[j]))
                ++j;
            strs.emplace_back(s.substr(i, j - i));
            len += j - i;
            i = j;
            long long cnt = 1;
            while (j < n && isDigit(s[j]))
            {
                cnt *= s[j] - '0';
                ++j;
            }
            i = j;
            cnts.emplace_back(len);
            len *= cnt;
            lens.emplace_back(len);
            if (len >= k)
                break;
        }
        int m = strs.size();
        for (int i = m - 1; i >= 0; --i)
        {
            if (0 == i)
                return string() + strs[0][(k - 1) % strs[0].size()];
            k = (k - 1) % cnts[i] + 1;
            if (lens[i - 1] < k)
            {
                k -= lens[i - 1];
                return string() + strs[i][k - 1];
            }
        }
        return "";
        // int m = strs.size();
        // string res;
        // if (1 == m)
        //     res += strs[0][(k - 1) % strs[0].size()];
        // else
        //     res += strs.back()[(k - lens[m - 2] - 1) % strs.back().size()];
        // return res;
    }

    inline bool isDigit(char c)
    {
        return '0' <= c && c <= '9';
    }

    inline bool isChar(char c)
    {
        return 'a' <= c && c <= 'z';
    }
};
// @lc code=end
