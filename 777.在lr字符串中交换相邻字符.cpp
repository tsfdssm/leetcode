/*
 * @lc app=leetcode.cn id=777 lang=cpp
 *
 * [777] 在LR字符串中交换相邻字符
 */

// @lc code=start
class Solution
{
public:
    bool canTransform(string start, string end)
    {
        int n = start.size();
        int i = 0, j = 0;
        while (i < n && j < n)
        {
            while (i < n && start[i] == 'X')
                ++i;
            while (j < n && end[j] == 'X')
                ++j;
            if (i < n && j < n)
            {
                if (start[i] != end[j] || (start[i] == 'L' && i < j) || (start[i] == 'R' && i > j))
                    return false;
                ++i;
                ++j;
            }
        }
        while (i < n && start[i] == 'X')
            ++i;
        while (j < n && end[j] == 'X')
            ++j;
        return i == j;
    }
};
// @lc code=end
