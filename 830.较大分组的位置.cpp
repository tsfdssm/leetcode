/*
 * @lc app=leetcode.cn id=830 lang=cpp
 *
 * [830] 较大分组的位置
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> largeGroupPositions(string s)
    {
        int n = s.size();
        vector<vector<int>> res;
        for (int i = 0; i < n;)
        {
            int j = i + 1;
            while (j < n && s[j] == s[i])
                ++j;
            if (j - i >= 3)
                res.emplace_back<vector<int>>({i, j - 1});
            i = j;
        }
        return res;
    }
};
// @lc code=end
