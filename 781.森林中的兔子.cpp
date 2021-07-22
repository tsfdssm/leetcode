/*
 * @lc app=leetcode.cn id=781 lang=cpp
 *
 * [781] 森林中的兔子
 */

// @lc code=start
class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        map<int, int> mp;
        int res = 0;
        for (int num : answers)
        {
            if (!mp.count(num))
                mp[num] = 1;
            else
            {
                if (mp[num] < (num + 1))
                {
                    mp[num]++;
                }
                else
                {
                    res += num + 1;
                    mp[num] = 1;
                }
            }
        }
        for (auto it = mp.begin(); it != mp.end(); ++it)
            res += it->first + 1;
        return res;
    }
};
// @lc code=end
