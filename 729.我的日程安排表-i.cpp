/*
 * @lc app=leetcode.cn id=729 lang=cpp
 *
 * [729] 我的日程安排表 I
 */

// @lc code=start
class MyCalendar
{
public:
    map<int, int> calender;
    MyCalendar()
    {
        calender.clear();
    }

    bool book(int start, int end)
    {
        auto low = calender.upper_bound(start);

        if (low != calender.end())
        {
            if (low->second < end)
                return false;
            if (calender.count(start))
            {
                int tmp = calender[start];
                calender.erase(start);
                start = tmp;
            }
            if (low->second == end)
            {
                low->second = start;
                return true;
            }
        }
        calender[end] = start;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end
