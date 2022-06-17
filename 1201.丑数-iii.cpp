/*
 * @lc app=leetcode.cn id=1201 lang=cpp
 *
 * [1201] 丑数 III
 *
 * https://leetcode.cn/problems/ugly-number-iii/description/
 *
 * algorithms
 * Medium (26.31%)
 * Likes:    109
 * Dislikes: 0
 * Total Accepted:    8K
 * Total Submissions: 30.5K
 * Testcase Example:  '3\n2\n3\n5'
 *
 * 给你四个整数：n 、a 、b 、c ，请你设计一个算法来找出第 n 个丑数。
 *
 * 丑数是可以被 a 或 b 或 c 整除的 正整数 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 3, a = 2, b = 3, c = 5
 * 输出：4
 * 解释：丑数序列为 2, 3, 4, 5, 6, 8, 9, 10... 其中第 3 个是 4。
 *
 * 示例 2：
 *
 *
 * 输入：n = 4, a = 2, b = 3, c = 4
 * 输出：6
 * 解释：丑数序列为 2, 3, 4, 6, 8, 9, 10, 12... 其中第 4 个是 6。
 *
 *
 * 示例 3：
 *
 *
 * 输入：n = 5, a = 2, b = 11, c = 13
 * 输出：10
 * 解释：丑数序列为 2, 4, 6, 8, 10, 11, 12, 13... 其中第 5 个是 10。
 *
 *
 * 示例 4：
 *
 *
 * 输入：n = 1000000000, a = 2, b = 217983653, c = 336916467
 * 输出：1999999984
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 * 本题结果在 [1, 2 * 10^9] 的范围内
 *
 *
 */

// @lc code=start
class Solution
{
public:
    using ll = long long;

    int gcd(ll a, ll b)
    {
        if (0 == b)
            return a;
        return gcd(b, a % b);
    }
    int nthUglyNumber(int n, int a, int b, int c)
    {
        vector<long long> cnt = {a, b, c};
        sort(cnt.begin(), cnt.end());
        a = cnt[0];
        b = cnt[1];
        c = cnt[2];
        long long l = 1;
        long long r = a * n;
        long long ab = (ll)a * b / gcd(a, b);
        long long ac = (ll)a * c / gcd(a, c);
        long long bc = (ll)b * c / gcd(b, c);
        long long abc = (ll)ab * c / gcd(ab, c);
        while (l < r)
        {
            long long m = l + (r - l) / 2;
            long long sum = (m / a + m / b + m / c - m / (ab)-m / (ac)-m / (bc) + m / (abc));
            if (sum < n)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};
// @lc code=end
