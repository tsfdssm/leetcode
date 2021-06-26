/*
 * @lc app=leetcode.cn id=537 lang=cpp
 *
 * [537] 复数乘法
 */

// @lc code=start
class Solution
{
public:
    string complexNumberMultiply(string num1, string num2)
    {
        auto [a1, b1] = get(num1);
        auto [a2, b2] = get(num2);

        int a = a1 * a2 - (b1 * b2);
        int b = a1 * b2 + a2 * b1;
        string res = to_string(a);
        res += '+';
        res += to_string(b);
        res += 'i';
        return res;
    }
    pair<int, int> get(const string &num)
    {
        int a = 0, b = 0;
        int n = num.size();
        int i = 0;
        int j = i;
        while (j < n && num[j] != '+')
            ++j;
        a = stoi(num.substr(i, j - i));
        i = ++j;
        while (j < n && num[j] != 'i')
            ++j;
        b = stoi(num.substr(i, j - i));
        return {a, b};
    }
};
// @lc code=end
