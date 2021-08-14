/*
 * @lc app=leetcode.cn id=914 lang=cpp
 *
 * [914] 卡牌分组
 */

// @lc code=start
class Solution
{
public:
    bool hasGroupsSizeX(vector<int> &deck)
    {
        unordered_map<int, int> mp;
        for (int num : deck)
            mp[num]++;
        int minn = deck.size();
        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            minn = min(minn, gcd(it->second, minn));
            if (minn == 1)
                return false;
        }
        return true;
    }
    int gcd(int a, int b)
    {
        if (0 == b)
            return a;
        return gcd(b, a % b);
    }
};
// @lc code=end
