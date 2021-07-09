/*
 * @lc app=leetcode.cn id=728 lang=cpp
 *
 * [728] 自除数
 */

// @lc code=start
class Solution
{
public:
    bool isSelfDiv(int i)
    {
        if (i <= 0)
            return false;
        int x = i;
        while (i > 0)
        {
            int low = i % 10;
            if (0 == low || x % low != 0)
                return false;
            i /= 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> res;
        for (int i = left; i <= right; ++i)
            if (isSelfDiv(i))
                res.emplace_back(i);
        return res;
    }
};
// @lc code=end
