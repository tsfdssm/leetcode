/*
 * @lc app=leetcode.cn id=391 lang=cpp
 *
 * [391] 完美矩形
 */

// @lc code=start
class Solution
{
public:
    bool isRectangleCover(vector<vector<int>> &rectangles)
    {
        int up = INT_MIN, low = INT_MAX;
        int l = INT_MAX, r = INT_MIN;

        map<pair<int, int>, int> mp;
        int area = 0;
        for (auto it : rectangles)
        {
            int tmpup = it[3];
            int tmplow = it[1];
            int tmpl = it[0];
            int tmpr = it[2];
            up = max(up, tmpup);
            low = min(low, tmplow);
            l = min(l, tmpl);
            r = max(r, tmpr);

            mp[{tmpl, tmpup}]++;
            mp[{tmpl, tmplow}]++;
            mp[{tmpr, tmpup}]++;
            mp[{tmpr, tmplow}]++;
            area += (tmpup - tmplow) * (tmpr - tmpl);
        }
        if (area != (up - low) * (r - l))
            return false;

        mp[{l, up}]++;
        mp[{l, low}]++;
        mp[{r, up}]++;
        mp[{r, low}]++;
        for (auto it : mp)
        {
            if (it.second % 2)
                return false;
        }
        return true;
    }
};
// @lc code=end
