/*
 * @lc app=leetcode.cn id=855 lang=cpp
 *
 * [855] 考场就座
 */

// @lc code=start
class ExamRoom
{
public:
    set<int> st;
    int maxn;
    ExamRoom(int n)
    {
        maxn = n;
    }

    int seat()
    {
        if (st.empty())
        {
            st.insert(0);
            return 0;
        }
        int dist = *st.begin();
        int stu = 0;
        int prev = dist;
        for (auto it = next(st.begin()); it != st.end(); ++it)
        {
            int d = (*it - prev) / 2;
            if (d > dist)
            {
                dist = d;
                stu = prev + d;
            }
            prev = *it;
        }
        if (maxn - 1 - *st.rbegin() > dist)
        {
            stu = maxn - 1;
        }
        st.insert(stu);
        return stu;
    }

    void leave(int p)
    {
        st.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
// @lc code=end
