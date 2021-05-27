/*
 * @lc app=leetcode.cn id=306 lang=cpp
 *
 * [306] 累加数
 */

// @lc code=start
class Solution
{
public:
    bool isAdditiveNumber(string num)
    {
        int i = 0;
        int n = num.size();
        for (int j = i + 1; j < n; ++j)
            for (int k = j + 1; k < n; ++k)
                if (dfs(num, i, j, k))
                    return true;
        return false;
    }

    bool dfs(string &s, int i, int j, int k)
    {
        if (('0' == s[i] && j - i > 1) || ('0' == s[j] && k - j > 1))
            return false;
        string a = s.substr(i, j - i);
        string b = s.substr(j, k - j);
        string sum = add(a, b);
        int n = sum.size();
        if (k + n > s.size() || sum != s.substr(k, n))
            return false;
        if (k + n == s.size())
            return true;
        return dfs(s, j, k, k + n);
    }

    string add(string &a, string &b)
    {
        int n1 = a.size() - 1;
        int n2 = b.size() - 1;
        int carry = 0;
        string ans;
        while (n1 >= 0 || n2 >= 0 || carry > 0)
        {
            int t1 = n1 >= 0 ? a[n1--] - '0' : 0;
            int t2 = n2 >= 0 ? b[n2--] - '0' : 0;
            ans += (t1 + t2 + carry) % 10 + '0';
            carry = (t1 + t2 + carry) >= 10 ? 1 : 0;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
