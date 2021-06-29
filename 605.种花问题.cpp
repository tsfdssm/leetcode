/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int len = flowerbed.size();
        int cnt = 0;
        if (1 == len)
            return flowerbed[0] + n <= 1;
        for (int i = 0; i < len; ++i)
        {
            if (1 == flowerbed[i])
                continue;
            if (0 == i)
            {
                if (flowerbed[i + 1] == 0)
                {
                    cnt++;
                    flowerbed[0] = 1;
                }
            }
            else if (len - 1 == i)
            {
                if (flowerbed[i - 1] == 0)
                {
                    cnt++;
                    flowerbed[i] = 1;
                }
            }
            else
            {
                if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
                {
                    cnt++;
                    flowerbed[i] = 1;
                }
            }
        }
        return cnt >= n;
    }
};
// @lc code=end
