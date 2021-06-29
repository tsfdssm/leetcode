/*
 * @lc app=leetcode.cn id=593 lang=cpp
 *
 * [593] 有效的正方形
 */

// @lc code=start
class Solution
{
public:
    int dic(vector<int> &p1, vector<int> &p2)
    {
        int x = abs(p1[0] - p2[0]);
        int y = abs(p1[1] - p2[1]);
        return x * x + y * y;
    }
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        map<int, int> mp;
        mp[dic(p1, p2)]++;
        mp[dic(p1, p3)]++;
        mp[dic(p1, p4)]++;
        mp[dic(p2, p3)]++;
        mp[dic(p2, p4)]++;
        mp[dic(p3, p4)]++;
        if (2 != mp.size())
            return false;
        auto it = mp.begin();
        int r = it->first;
        int n = it->second;
        ++it;
        int mid = it->first;
        int l = it->second;
        return mid == 2 * r && n == 4 && l == 2;
    }
};
// @lc code=end
