/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if(x<0)
            return false;
        long long tmp = 0;
        int y = x;
        while(y>0)
        {
            tmp *= 10;
            tmp += y % 10;
            y /= 10;
        }
        return tmp == x;
    }
};
// @lc code=end
