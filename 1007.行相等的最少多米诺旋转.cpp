/*
 * @lc app=leetcode.cn id=1007 lang=cpp
 *
 * [1007] 行相等的最少多米诺旋转
 */

// @lc code=start
class Solution
{
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        int n = tops.size();
        int up = tops[0];
        int down = bottoms[0];
        int cntUp = 1;
        int cntDown = 1;
        int totalUp = 0;
        int totalDown = 0;
        if (tops[0] == bottoms[0])
            totalUp = totalDown = 1;
        for (int i = 1; i < n; ++i)
        {
            if (-1 != up)
            {
                if (tops[i] != up && bottoms[i] != up)
                    up = -1;
                else
                {

                    if (tops[i] == up)
                    {
                        cntUp++;
                        if (bottoms[i] == up)
                        {
                            totalUp++;
                        }
                    }
                }
            }
            if (-1 != down)
            {
                if (tops[i] != down && bottoms[i] != down)
                    down = -1;
                else
                {

                    if (bottoms[i] == down)
                    {
                        cntDown++;
                        if (tops[i] == down)
                        {
                            totalDown++;
                        }
                    }
                }
            }
            if (-1 == up && -1 == down)
                return -1;
        }
        int res = n;
        if (-1 != up)
        {
            cntUp = min(cntUp - totalUp, n - cntUp);
            res = min(res, cntUp);
        }
        if (-1 != down)
        {
            cntDown = min(cntDown - totalDown, n - cntDown);
            res = min(res, cntDown);
        }
        return res;
    }
};
// @lc code=end
