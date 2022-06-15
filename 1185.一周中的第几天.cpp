/*
 * @lc app=leetcode.cn id=1185 lang=cpp
 *
 * [1185] 一周中的第几天
 *
 * https://leetcode.cn/problems/day-of-the-week/description/
 *
 * algorithms
 * Easy (62.60%)
 * Likes:    114
 * Dislikes: 0
 * Total Accepted:    36.2K
 * Total Submissions: 57.9K
 * Testcase Example:  '31\n8\n2019'
 *
 * 给你一个日期，请你设计一个算法来判断它是对应一周中的哪一天。
 *
 * 输入为三个整数：day、month 和 year，分别表示日、月、年。
 *
 * 您返回的结果必须是这几个值中的一个 {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
 * "Friday", "Saturday"}。
 *
 *
 *
 * 示例 1：
 *
 * 输入：day = 31, month = 8, year = 2019
 * 输出："Saturday"
 *
 *
 * 示例 2：
 *
 * 输入：day = 18, month = 7, year = 1999
 * 输出："Sunday"
 *
 *
 * 示例 3：
 *
 * 输入：day = 15, month = 8, year = 1993
 * 输出："Sunday"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 给出的日期一定是在 1971 到 2100 年之间的有效日期。
 *
 *
 */

// @lc code=start
class Solution
{
public:
    struct time
    {
        int year;
        int month;
        int day;
        time(int y, int m, int d) : year(y), month(m), day(d)
        {
        }
        int operator-(time t)
        {
            int cnt = 0;
            for (int i = t.year; i < year; ++i)
                if ((i % 4 == 0) && ((i % 100 != 0) || (i % 400 == 0)))
                    cnt += 366;
                else
                    cnt += 365;
            vector<int> m = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)))
                m[2] = 29;
            for (int j = 1; j < month; ++j)
                cnt += m[j];
            cnt += day - 1;
            return cnt;
        }
    };
    string dayOfTheWeek(int day, int month, int year)
    {

        time st = time(1971, 1, 1);
        time cur = time(year, month, day);

        int len = cur - st;
        vector<string> res = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        int base = 5;
        return res[(len + base) % 7];
    }
};
// @lc code=end
