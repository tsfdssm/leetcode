/*
 * @lc app=leetcode.cn id=592 lang=cpp
 *
 * [592] 分数加减运算
 */

// @lc code=start
class Solution
{
public:
    pair<int, int> get(const string &s, int l, int r)
    {
        int mid = l;
        while (mid < r && s[mid] != '/')
            ++mid;
        return {stoi(s.substr(l, mid)), stoi(s.substr(mid + 1, r))};
    }
    int gcd(int x, int y)
    {
        if (0 == y)
            return x;
        return gcd(y, x % y);
    }
    string fractionAddition(string &s)
    {
        int n = s.size();
        int a = 0, b = 1;
        for (int i = 0; i < n;)
        {
            bool flag = true;
            if (s[i] == '-')
            {
                flag = false;
                ++i;
            }
            else if (s[i] == '+')
            {
                flag = true;
                ++i;
            }
            int j = i;
            while (j < n && s[j] != '-' && s[j] != '+')
                ++j;
            auto [ta, tb] = get(s, i, j);
            i = j;
            if (!flag)
                ta *= -1;
            int multi = b * tb / gcd(b, tb);
            a *= multi / b;
            ta *= multi / tb;
            a += ta;

            int div = abs(gcd(a, multi));
            a /= div;
            b = multi / div;
        }
        return to_string(a) + '/' + to_string(b);
    }
};
// @lc code=end
