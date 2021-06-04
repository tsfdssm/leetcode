/*
 * @lc app=leetcode.cn id=390 lang=cpp
 *
 * [390] 消除游戏
 */

// @lc code=start
class Solution
{
public:
    int lastRemaining(int n)
    {
        int step = 1;
        int st = 1;
        bool L2R = true;
        while (n > 1)
        {
            if (L2R || n % 2 == 1)
            {
                st += step;
            }
            n >>= 1;
            step <<= 1;
            L2R = !L2R;
        }
        return st;
        // vector<int> a(n, 0);
        // vector<int> b;
        // for (int i = 0; i < n; ++i)
        //     a[i] = (i + 1);
        // bool flag = true;
        // //true:a->b
        // //false:b->a
        // while (a.size() > 1 || b.size() > 1)
        // {
        //     if (flag)
        //     {
        //         flag = false;
        //         b.resize(0);
        //         int n = a.size();
        //         for (int i = 0; i < n; ++i)
        //         {
        //             if (i % 2 == 0)
        //                 continue;
        //             b.push_back(a[i]);
        //         }
        //         if (1 == b.size())
        //             break;
        //         reverse(b.begin(), b.end());
        //     }
        //     else
        //     {
        //         flag = true;
        //         a.resize(0);
        //         int n = b.size();
        //         for (int i = 0; i < n; ++i)
        //         {
        //             if (i % 2 == 0)
        //                 continue;
        //             a.push_back(b[i]);
        //         }
        //         if (1 == a.size())
        //             break;
        //         reverse(a.begin(), a.end());
        //     }
        // }
        // if (1 == a.size())
        //     return a[0];
        // if (1 == b.size())
        //     return b[0];
        // return -1;
    }
};
// @lc code=end
