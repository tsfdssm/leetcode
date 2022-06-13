/*
 * @lc app=leetcode.cn id=1154 lang=cpp
 *
 * [1154] 一年中的第几天
 *
 * https://leetcode.cn/problems/day-of-the-year/description/
 *
 * algorithms
 * Easy (64.01%)
 * Likes:    98
 * Dislikes: 0
 * Total Accepted:    48.4K
 * Total Submissions: 75.6K
 * Testcase Example:  '"2019-01-09"'
 *
 * 给你一个字符串 date ，按 YYYY-MM-DD 格式表示一个 现行公元纪年法 日期。返回该日期是当年的第几天。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：date = "2019-01-09"
 * 输出：9
 * 解释：给定日期是2019年的第九天。
 *
 * 示例 2：
 *
 *
 * 输入：date = "2019-02-10"
 * 输出：41
 *
 *
 *
 *
 * 提示：
 *
 *
 * date.length == 10
 * date[4] == date[7] == '-'，其他的 date[i] 都是数字
 * date 表示的范围从 1900 年 1 月 1 日至 2019 年 12 月 31 日
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int dayOfYear(string data)
    {
        vector<int> a = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int y = stoi(data.substr(0, 4));
        int m = stoi(data.substr(5, 2));
        int d = stoi(data.substr(8, 2));
        if ((y % 4 == 0) && (y % 100 != 0 || y % 400 == 0))
            a[2] = 29;
        int cnt = 0;
        for (int i = 0; i <= 12; ++i)
        {
            if (i == m)
            {
                cnt += d;
                return cnt;
            }
            cnt += a[i];
        }
        return 0;
    }
};
// @lc code=end
