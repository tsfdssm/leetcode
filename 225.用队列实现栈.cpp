/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack
{
public:
    //stack<int> m_s;
    queue<int> q;

    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        int len = q.size();
        q.push(x);
        for (int i = 0; i < len; ++i)
        {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        //m_s.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int tmp = q.front();
        q.pop();
        return tmp;
        // int tmp = m_s.top();
        // m_s.pop();
        // return tmp;
    }

    /** Get the top element. */
    int top()
    {
        return q.front();
        //return m_s.top();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q.empty();
        //return m_s.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
