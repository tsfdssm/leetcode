/*
 * @lc app=leetcode.cn id=641 lang=cpp
 *
 * [641] 设计循环双端队列
 */

// @lc code=start
class MyCircularDeque
{
public:
    vector<int> vec;
    int front = 0;
    int last = 0;
    int cap = 0;
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k)
    {
        cap = k + 1;
        vec.resize(cap);
        front = last = 0;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value)
    {
        if (isFull())
            return false;
        --front;
        front += cap;
        front %= cap;
        vec[front] = value;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value)
    {
        if (isFull())
            return false;
        vec[last] = value;
        ++last;
        last %= cap;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront()
    {
        if (isEmpty())
            return false;
        ++front;
        front %= cap;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast()
    {
        if (isEmpty())
            return false;
        --last;
        last += cap;
        last %= cap;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront()
    {
        if (isEmpty())
            return -1;
        return vec[front];
    }

    /** Get the last item from the deque. */
    int getRear()
    {
        if (isEmpty())
            return -1;
        return vec[(last - 1 + cap) % cap];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty()
    {
        return front == last;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull()
    {
        return front == ((last + 1) % cap);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end
