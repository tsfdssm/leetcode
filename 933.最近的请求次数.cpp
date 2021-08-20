/*
 * @lc app=leetcode.cn id=933 lang=cpp
 *
 * [933] 最近的请求次数
 */

// @lc code=start
class RecentCounter
{
public:
    vector<int> vec;
    RecentCounter()
    {
    }

    int ping(int t)
    {
        vec.emplace_back(t);
        auto l = lower_bound(vec.begin(), vec.end(), t - 3000);
        return vec.end() - l;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end
