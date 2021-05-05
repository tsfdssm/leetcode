/*
 * @lc app=leetcode.cn id=214 lang=cpp
 *
 * [214] 最短回文串
 */
#include <vector>
#include <string>
#include <iostream>
using namespace std;
// @lc code=start

class Solution
{
public:
    string shortestPalindrome(string s)
    {
        int n = s.size();
        vector<int> fail(n, 0);
        for (int i = 1; i < n; ++i)
        {
            int j = fail[i - 1];
            while (j != 0 && s[j] != s[i])
                j = fail[j - 1];
            if (s[j] == s[i])
                fail[i] = j + 1;
        }
        int best = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            while (best != 0 && s[best] != s[i])
                best = fail[best - 1];
            if (s[best] == s[i])
                ++best;
        }
        string add = (best == n ? "" : s.substr(best, n));
        reverse(add.begin(), add.end());
        return add + s;
        // int n = s.size();
        // int base = 13, mod = 10e6 + 7;
        // long long left = 0, right = 0, mul = 1;
        // int best = -1;
        // for (int i = 0; i < n; ++i)
        // {
        //     left = (left * base + s[i]) % mod;
        //     right = (right + s[i] * mul) % mod;
        //     if (left == right)
        //         best = i;
        //     mul = mul * base % mod;
        // }
        // string add = (best == n - 1) ? "" : s.substr(best + 1, n);
        // reverse(add.begin(), add.end());
        // return add + s;

        // int n = s.size(), k = n;
        // while (k > 0)
        // {
        //     if (isPal(string(s.begin(), s.begin() + k)))
        //         break;
        //     --k;
        // }
        // string tmp = s.substr(k, n - k);
        // reverse(tmp.begin(), tmp.end());
        // return tmp + s;
    }

    bool isPal(const string &s)
    {
        if (1 == s.size() || 0 == s.size())
            return true;
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
};
// @lc code=end
int main()
{
    Solution A;
    string s = "aacecaaa";
    cout << A.shortestPalindrome(s);
}
