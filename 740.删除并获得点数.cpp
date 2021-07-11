/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 */

// @lc code=start
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        map<int, int> mp;
        for (int num : nums)
            mp[num]++;

        auto it1 = mp.begin();
        int no = 0;
        int has = it1->first * (it1->second);
        for (auto it2 = next(it1); it2 != mp.end(); ++it1, ++it2)
        {
            if (it2->first == (it1->first + 1))
                tie(no, has) = make_pair(has, max(has, no + (it2->first * it2->second)));
            else
            {
                no = has;
                has += (it2->first * it2->second);
            }
        }
        return has;
    }
};
// @lc code=end
