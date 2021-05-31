/*
 * @lc app=leetcode.cn id=331 lang=cpp
 *
 * [331] 验证二叉树的前序序列化
 */

// @lc code=start
class Solution
{
public:
    bool isValidSerialization(string preorder)
    {
        int slots = 1;
        int n = preorder.size();
        int i = 0;
        while (i < n)
        {
            if (0 == slots)
                return false;
            if (',' == preorder[i])
                ++i;
            else if ('#' == preorder[i])
            {
                --slots;
                ++i;
            }
            else
            {
                while (i < n && preorder[i] != ',')
                    ++i;
                ++slots;
            }
        }
        return slots == 0;
    }
};
// @lc code=end
