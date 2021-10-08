/*
 * @lc app=leetcode.cn id=1017 lang=cpp
 *
 * [1017] 负二进制转换
 */

// @lc code=start
class Solution
{
public:
    vector<int> base2K(int n, int k)
    {
        if (0 == n)
            return {0};
        int cur = k;
        vector<int> res;
        while (n != 0)
        {
            int r = abs(n) % abs(k);
            res.push_back(r);
            n -= r;
            n /= k;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    string baseNeg2(int n)
    {
        vector<int> vec = base2K(n, -2);
        string res = "";
        for (int num : vec)
            res += to_string(num);
        return res;
    }
};
// @lc code=end
