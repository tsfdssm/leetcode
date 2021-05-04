/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack
{
public:
    /** initialize your data structure here. */
    stack<int> st;
    unordered_map<int, int> all;
    int mn;

    MinStack()
    {
        mn = INT_MAX;
    }

    void push(int val)
    {
        st.push(val);
        mn = min(mn, val);
        all[val]++;
    }

    void pop()

    {
        int val = st.top();
        st.pop();
        all[val]--;
        if (0 == all[val])
        {
            all.erase(val);
            if (val == mn)
            {
                mn = INT_MAX;
                for (auto it = all.begin(); it != all.end(); ++it)
                {
                    mn = min(mn, it->first);
                }
            }
        }
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
