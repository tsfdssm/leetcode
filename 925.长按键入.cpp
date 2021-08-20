/*
 * @lc app=leetcode.cn id=925 lang=cpp
 *
 * [925] 长按键入
 */

// @lc code=start
class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        int m = name.size();
        int n = typed.size();
        int i = 0, j = 0;
        while (i < m && j < n)
        {
            int i1 = i + 1;
            int j1 = j + 1;
            while (i1 < m && name[i1] == name[i])
                ++i1;
            while (j1 < n && typed[j1] == typed[j])
                ++j1;
            if (name[i] != typed[j])
                return false;
            if (j1 - j < i1 - i)
                return false;
            i = i1;
            j = j1;
        }
        return i == m && j == n;
    }
};
// @lc code=end
