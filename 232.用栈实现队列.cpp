/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue
{
public:
    stack<int> st;
    stack<int> tmp;
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        while (!st.empty())
        {
            tmp.push(st.top());
            st.pop();
        }
        st.push(x);
        while (!tmp.empty())
        {
            st.push(tmp.top());
            tmp.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int tmp = st.top();
        st.pop();
        return tmp;
    }

    /** Get the front element. */
    int peek()
    {
        return st.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
