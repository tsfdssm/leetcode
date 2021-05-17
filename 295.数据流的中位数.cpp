/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
class MedianFinder
{
public:
    /** initialize your data structure here. */
    priority_queue<int> less;
    priority_queue<int, vector<int>, greater<int>> greater;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        less.push(num);
        greater.push(less.top());
        less.pop();

        if (less.size() < greater.size())
        {
            less.push(greater.top());
            greater.pop();
        }
    }

    double findMedian()
    {
        return less.size() > greater.size() ? less.top() : (less.top() + greater.top()) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
