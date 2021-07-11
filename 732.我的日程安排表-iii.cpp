/*
 * @lc app=leetcode.cn id=732 lang=cpp
 *
 * [732] 我的日程安排表 III
 */

// @lc code=start
class MyCalendarThree
{
public:
    map<int, int> f;
    MyCalendarThree()
    {
    }

    int book(int start, int end)
    {
        f[start]++;
        f[end]--;
        int num = 0;
        int res = 0;
        for (auto [t, c] : f)
        {
            num += c;
            res = max(res, num);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
// @lc code=end
