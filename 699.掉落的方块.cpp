/*
 * @lc app=leetcode.cn id=699 lang=cpp
 *
 * [699] 掉落的方块
 */

// @lc code=start
class Solution
{
public:
    vector<int> fallingSquares(vector<vector<int>> &pos)
    {
        vector<int> res(pos.size());
        int ind = 0;
        int mm = 0;
        map<int, int> sp;
        for (auto &ele : pos)
        {
            int from = ele[0], to = ele[1] + from, len = ele[1];
            int midh = 0, endh = 0;

            auto a = sp.lower_bound(from);
            if (a != sp.begin() && sp.find(from) == sp.end())
                --a;
            auto b = sp.lower_bound(to);
            if (b != sp.begin() && sp.find(to) == sp.end())
                --b;
            auto c = sp.upper_bound(to);

            auto d = sp.lower_bound(to);

            for (auto tmp = a; tmp != d; ++tmp)
                midh = max(midh, tmp->second);
            for (auto tmp = b; tmp != c; ++tmp)
                endh = tmp->second;

            sp.erase(sp.lower_bound(from), sp.upper_bound(to));
            sp[from] = midh + len;
            sp[to] = endh;

            mm = max(mm, midh + len);

            res[ind++] = mm;
        }
        return res;
    }
};
// @lc code=end
