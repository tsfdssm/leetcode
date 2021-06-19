/*
 * @lc app=leetcode.cn id=479 lang=cpp
 *
 * [479] 最大回文数乘积
 */

// @lc code=start
class Solution
{
public:
    int base = 1337;
    int largestPalindrome(int n)
    {
        if (1 == n)
            return 9;
        int upper = pow(10, n) - 1;
        int lower = pow(10, n - 1);
        for (int i = upper; i >= lower; --i)
        {
            string tmp = to_string(i);
            string r_tmp = tmp;
            reverse(r_tmp.begin(), r_tmp.end());
            long long product = stol(tmp + r_tmp);
            for (long long j = upper; j * j > product; --j)
                if (product % j == 0)
                    return product % base;
        }
        return -1;
    }
};
// @lc code=end
