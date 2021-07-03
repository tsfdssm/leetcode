/*
 * @lc app=leetcode.cn id=659 lang=cpp
 *
 * [659] 分割数组为连续子序列
 */

// @lc code=start
class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        unordered_map<int, int> rest;
        unordered_map<int, int> seq;
        for (const int num : nums)
            rest[num]++;
        for (const int num : nums)
        {
            if (rest[num] == 0)
                continue;
            if (seq[num - 1] > 0)
            {
                seq[num]++;
                seq[num - 1]--;
            }
            else
            {
                if (rest[num + 1] > 0 && rest[num + 2] > 0)
                {
                    seq[num + 2]++;
                    rest[num + 1]--;
                    rest[num + 2]--;
                }
                else
                    return false;
            }
            rest[num]--;
        }
        return true;
    }
};
// @lc code=end
