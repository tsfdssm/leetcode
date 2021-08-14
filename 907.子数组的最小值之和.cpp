/*
 * @lc app=leetcode.cn id=907 lang=cpp
 *
 * [907] 子数组的最小值之和
 */

// @lc code=start
class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        arr.push_back(0);
        int n = arr.size();
        const int mod = 1e9 + 7;
        long res = 0;
        stack<int> stk;
        for (int i = 0; i < n; ++i)
        {
            while (!stk.empty() && arr[stk.top()] >= arr[i])
            {
                int index = stk.top();
                stk.pop();
                int prev = -1;
                if (!stk.empty())
                    prev = stk.top();
                res = (res + (long)arr[index] * ((index - prev) * (i - index))) % mod;
            }
            stk.push(i);
        }
        return res;
        // int n = arr.size();
        // const int mod = 1e9 + 7;
        // vector<int> left(n);
        // vector<int> right(n);

        // stack<int> stk;
        // for (int i = 0; i < n; ++i)
        // {
        //     while (!stk.empty() && arr[stk.top()] >= arr[i])
        //     {
        //         right[stk.top()] = i;
        //         stk.pop();
        //     }
        //     stk.push(i);
        // }
        // while (!stk.empty())
        // {
        //     right[stk.top()] = n;
        //     stk.pop();
        // }
        // for (int i = n - 1; i >= 0; --i)
        // {
        //     while (!stk.empty() && arr[stk.top()] >= arr[i])
        //     {
        //         left[stk.top()] = i;
        //         stk.pop();
        //     }
        //     stk.push(i);
        // }
        // while (!stk.empty())
        // {
        //     left[stk.top()] = -1;
        //     stk.pop();
        // }

        // int res = 0;
        // for (int i = 0; i < n; ++i)
        // {
        //     res = (res + arr[i] * (i - left[i]) * (right[i] - i)) % mod;
        // }
        // return res;
    }
};
// @lc code=end
