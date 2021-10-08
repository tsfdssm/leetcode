/*
 * @lc app=leetcode.cn id=1024 lang=cpp
 *
 * [1024] 视频拼接
 */

// @lc code=start
class Solution
{
public:
    int videoStitching(vector<vector<int>> &clips, int time)
    {
        vector<int> maxn(time);
        int last = 0;
        int pre = 0;
        int res = 0;
        for (auto &clip : clips)
        {
            if (clip[0] < time)
            {
                maxn[clip[0]] = max(maxn[clip[0]], clip[1]);
            }
        }

        for (int i = 0; i < time; ++i)
        {
            last = max(last, maxn[i]);
            if (i == last)
                return -1;
            if (i == pre)
            {
                ++res;
                pre = last;
            }
        }
        return res;
    }
};
// @lc code=end
