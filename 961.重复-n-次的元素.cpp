/*
 * @lc app=leetcode.cn id=961 lang=cpp
 *
 * [961] 重复 N 次的元素
 */

// @lc code=start
class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        // int maxn = 0;
        // int res = -1;
        // int n = nums.size();
        // for (int i = 0; i < n; ++i)
        // {
        //     if (maxn == 0)
        //     {
        //         maxn = 1;
        //         res = nums[i];
        //     }
        //     else if (res == nums[i])
        //     {
        //         maxn++;
        //     }
        //     else
        //         maxn--;
        // }
        // return res;

        int res = -1;
        int n = nums.size();
        int cnt = 0;
        while (cnt < 10)
        {
            int a = random() % n;
            int b = random() % n;
            int c = random() % n;
            if (a == b || b == c || a == c)
                continue;
            a = nums[a];
            b = nums[b];
            c = nums[c];
            if (a == b)
                return a;
            else if (b == c)
                return b;
            else if (a == c)
                return c;
            else
                ++cnt;
        }
        return -1;
    }
};
// @lc code=end
