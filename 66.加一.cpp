/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        for (int i = digits.size() - 1; i >= -1; i--)
        {
            if (i == -1)
            {
                digits.insert(digits.begin(), 1);
                break;
            }
            if (digits[i] == 9)
            {
                digits[i] = 0;
                continue;
            }
            else
            {
                digits[i] += 1;
                break;
            }
        }
        return digits;
    }
};
// @lc code=end
