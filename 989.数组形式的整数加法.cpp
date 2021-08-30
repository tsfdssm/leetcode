/*
 * @lc app=leetcode.cn id=989 lang=cpp
 *
 * [989] 数组形式的整数加法
 */

// @lc code=start
class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        reverse(num.begin(), num.end());
        int idx = 0;
        int over = 0;
        while (k > 0 || over > 0)
        {
            int cur = k % 10 + over;
            k /= 10;
            if (idx < num.size())
                cur += num[idx];
            over = cur / 10;
            cur = cur % 10;
            if (idx < num.size())
                num[idx] = cur;
            else
                num.emplace_back(cur);
            ++idx;
        }
        reverse(num.begin(), num.end());
        return num;
    }
};
// @lc code=end
