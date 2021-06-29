/*
 * @lc app=leetcode.cn id=622 lang=cpp
 *
 * [622] 设计循环队列
 */

// @lc code=start
class MyCircularQueue
{
public:
    vector<int> vec;
    int l;
    int r;
    int len;
    MyCircularQueue(int k)
    {
        vec.resize(k + 1);
        len = k + 1;
        l = 0;
        r = 0;
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;
        vec[r] = value;
        ++r;
        r %= len;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        ++l;
        l %= len;
        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return vec[l];
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        return vec[(r - 1 + len) % len];
    }

    bool isEmpty()
    {
        return l == r;
    }

    bool isFull()
    {
        return l % len == ((r + 1) % len);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end
