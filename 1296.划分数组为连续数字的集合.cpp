/*
 * @lc app=leetcode.cn id=1296 lang=cpp
 *
 * [1296] 划分数组为连续数字的集合
 */

// @lc code=start
class Solution
{
public:
    bool isPossibleDivide(vector<int> &hand, int w)
    {
        int n = hand.size();
        if (n % w != 0)
            return false;
        map<int, int> mp;
        map<int, int> ed;
        for (int num : hand)
            mp[num]++;
        int cnt = 0;

        for (auto it = mp.begin(); it != mp.end(); ++it)
        {

            int val = it->first;
            int num = it->second;

            if (it != mp.begin() && cnt > 0)
            {
                if (prev(it)->first != val - 1)
                    return false;
            }
            if (cnt > num)
            {
                return false;
            }
            else if (cnt < num)
            {
                ed[val + w - 1] = num - cnt;
                cnt = num;
            }
            else
            {
            }

            if (ed.count(val))
            {
                cnt -= ed.find(val)->second;
            }
        }
        return cnt == 0;
    }
};
// @lc code=end
