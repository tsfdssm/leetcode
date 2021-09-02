/*
 * @lc app=leetcode.cn id=1003 lang=cpp
 *
 * [1003] 检查替换后的词是否有效
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        const string t = "abc";
        while (s.size() > 0)
        {
            int pos = s.find(t);
            if (pos < 0)
                return false;
            s.erase(pos, 3);
        }
        return true;
    }
};
// @lc code=end
