/*
 * @lc app=leetcode.cn id=352 lang=cpp
 *
 * [352] 将数据流变为多个不相交区间
 */

// @lc code=start
class SummaryRanges
{
public:
    /** Initialize your data structure here. */
    map<int, int> lower;
    map<int, int> upper;
    unordered_set<int> st;
    SummaryRanges()
    {
    }

    void addNum(int val)
    {
        if (st.count(val))
            return;
        st.insert(val);
        if (lower.count(val + 1) && upper.count(val - 1))
        {
            int l = upper[val - 1];
            int r = lower[val + 1];
            lower.erase(val + 1);
            upper.erase(val - 1);
            lower[l] = r;
            upper[r] = l;
        }
        else if (lower.count(val + 1))
        {
            int r = lower[val + 1];
            lower.erase(val + 1);
            lower[val] = r;
            upper[r] = val;
        }
        else if (upper.count(val - 1))
        {
            int l = upper[val - 1];
            upper.erase(val - 1);
            upper[val] = l;
            lower[l] = val;
        }
        else
        {
            upper[val] = val;
            lower[val] = val;
        }
    }

    vector<vector<int>> getIntervals()
    {
        vector<vector<int>> res;
        for (auto it : lower)
        {
            res.push_back({it.first, it.second});
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
// @lc code=end
