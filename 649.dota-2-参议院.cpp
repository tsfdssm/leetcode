/*
 * @lc app=leetcode.cn id=649 lang=cpp
 *
 * [649] Dota2 参议院
 */

// @lc code=start
class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        bool r = true;
        bool d = true;
        int flag = 0;
        while (r && d)
        {
            r = false;
            d = false;
            for (int i = 0; i < senate.size(); ++i)
            {
                if ('R' == senate[i])
                {
                    if (flag < 0)
                        senate[i] = '0';
                    else
                        r = true;
                    flag++;
                }
                else if ('D' == senate[i])
                {
                    if (flag > 0)
                        senate[i] = '0';
                    else
                        d = true;
                    flag--;
                }
                else
                {
                }
            }
        }
        return r == true ? "Radiant" : "Dire";
    }
};
// @lc code=end
