/*
 * @lc app=leetcode.cn id=470 lang=cpp
 *
 * [470] 用 Rand7() 实现 Rand10()
 */

// @lc code=start
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution
{
public:
    int rand10()
    {
        int a, b, idx;
        while (true)
        {
            a = rand7();
            b = rand7();
            idx = b + (a - 1) * 7;
            if (idx <= 40)
                return 1 + idx % 10;
            a = idx - 40;
            b = rand7();
            idx = b + (a - 1) * 7;
            if (idx <= 60)
                return 1 + idx % 10;
            a = idx - 60;
            b = rand7();
            idx = b + (a - 1) * 7;
            if (idx <= 20)
                return 1 + idx % 10;
        }
        // return 10 * rand7() / 7;
    }
};
// @lc code=end
