/*
 * @lc app=leetcode.cn id=822 lang=cpp
 *
 * [822] 翻转卡片游戏
 */

// @lc code=start
class Solution
{
public:
    int flipgame(vector<int> &fronts, vector<int> &backs)
    {
        set<int> all;
        set<int> no;
        int n = fronts.size();
        for (int i = 0; i < n; ++i)
        {
            all.insert(fronts[i]);
            all.insert(backs[i]);
            if (fronts[i] == backs[i])
                no.insert(backs[i]);
        }
        for (int num : all)
        {
            if (!no.count(num))
                return num;
        }
        return 0;
    }
};
// @lc code=end
