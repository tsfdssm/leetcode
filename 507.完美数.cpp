/*
 * @lc app=leetcode.cn id=507 lang=cpp
 *
 * [507] 完美数
 */

// @lc code=start
class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        if (num == 1)
            return false;
        vector<int> vec(1, 1);
        int i = 2;
        while (i * i < num)
        {
            if (num % i == 0)
            {
                vec.push_back(i);
                vec.push_back(num / i);
            }
            ++i;
        }
        if (i * i == num)
            vec.push_back(i);
        return num == accumulate(vec.begin(), vec.end(), 0);
    }
};
// @lc code=end
