/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string getPermutation(int n, int k)
    {
        vector fact(n, 0);
        fact[0] = 1;
        for (int i = 1; i < n; i++)
            fact[i] = fact[i - 1] * i;
        --k;
        string res;
        vector valid(n + 1, 1);
        for (int i = 1; i <= n; i++)
        {
            int order = (k / fact[n - i]) + 1;
            for (int j = 1; j <= n; j++)
            {
                order -= valid[j];
                if (order == 0)
                {
                    res.push_back(j + '0');
                    valid[j] = 0;
                    break;
                }
            }
            k %= fact[n - i];
        }
        return res;
    }
};
// @lc code=end
