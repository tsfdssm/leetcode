/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        auto it = upper_bound(letters.begin(), letters.end(), target);
        if (it == letters.end())
            return letters[0];
        return *it;
    }
};
// @lc code=end
