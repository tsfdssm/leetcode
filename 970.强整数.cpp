/*
 * @lc app=leetcode.cn id=970 lang=cpp
 *
 * [970] 强整数
 */

// @lc code=start
class Solution
{
public:
    vector<int> powerfulIntegers(int x, int y, int bound)
    {
        //x**i+y**j==z
        int i = 0, j = 0;
        if (1 == x)
            i = 0;
        else
        {
            int px = 1;
            while (px < bound)
            {
                ++i;
                px *= x;
            }
        }
        if (1 == y)
            j = 0;
        else
        {
            int py = 1;
            while (py < bound)
            {
                ++j;
                py *= y;
            }
        }
        vector<int> fx(i + 1, 1);
        vector<int> fy(j + 1, 1);
        for (int m = 1; m <= i; ++m)
            fx[m] = fx[m - 1] * x;
        for (int n = 1; n <= j; ++n)
            fy[n] = fy[n - 1] * y;

        set<int> res;
        for (int m = 0; m <= i; ++m)
        {
            for (int n = 0; n <= j; ++n)
            {
                int num = fx[m] + fy[n];
                if (num > bound)
                    break;
                else
                    res.insert(num);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};
// @lc code=end
