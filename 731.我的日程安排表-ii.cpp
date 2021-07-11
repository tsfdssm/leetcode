/*
 * @lc app=leetcode.cn id=731 lang=cpp
 *
 * [731] 我的日程安排表 II
 */

// @lc code=start
class MyCalendarTwo
{
public:
    int k;
    map<int, int> f;

    MyCalendarTwo()
    {
        k = 2;
    }

    bool book(int start, int end)
    {
        f[start]++;
        f[end]--;
        int num = 0;
        for (auto &[t, c] : f)
        {
            num += c;
            if (num >= 3)
            {
                f[start]--;
                f[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end
