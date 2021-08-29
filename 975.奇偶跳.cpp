/*
 * @lc app=leetcode.cn id=975 lang=cpp
 *
 * [975] 奇偶跳
 */

// @lc code=start
class Solution
{
public:
    int oddEvenJumps(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<bool>> next(2, vector<bool>(n, false));
        next[0].back() = true;
        next[1].back() = true;
        int res = 1;
        map<int, int> mp;
        for (int i = n - 1; i >= 0; --i)
        {
            auto it = mp.lower_bound(arr[i]);
            if (it != mp.end() && next[0][it->second])
            {
                next[1][i] = true;
                ++res;
            }
            it = mp.lower_bound(-arr[i]);
            if (it != mp.end() && it->first <= 0 && next[1][it->second])
                next[0][i] = true;
            mp[arr[i]] = i;
            mp[-arr[i]] = i;
        }
        return res;
    }
};
// @lc code=end
