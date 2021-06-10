/*
 * @lc app=leetcode.cn id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

// @lc code=start
class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {

        vector<string> res;
        for (int i = 1; i <= n; ++i)
        {
            res.emplace_back(ToStr(i));
        }
        return res;
    }

    inline string ToStr(int n)
    {
        if ((0 == n % 3) && (0 == n % 5))
            return "FizzBuzz";
        if (0 == n % 3)
            return "Fizz";
        if (0 == n % 5)
            return "Buzz";
        return to_string(n);
    }
};
// @lc code=end
