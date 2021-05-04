/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

#include <vector>
#include <string>
#include <stack>
using namespace std;
// @lc code=start
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (const auto &str : tokens)
        {
            if (str == "+" || str == "-" || str == "*" || str == "/")
            {
                if (st.empty())
                {
                    break;
                }
                else
                {

                    int x2 = st.top();
                    st.pop();
                    int x1 = st.top();
                    st.pop();
                    int tmp = 0;
                    if (str == "+")
                    {
                        tmp = x1 + x2;
                    }
                    else if (str == "-")
                    {
                        tmp = x1 - x2;
                    }
                    else if (str == "*")
                    {
                        tmp = x1 * x2;
                    }
                    else if (str == "/")
                    {
                        tmp = x1 / x2;
                    }
                    else
                    {
                    }

                    st.push(tmp);
                }
            }
            else
            {
                st.push(atoi(str.c_str()));
            }
        }
        if (!st.empty())
            return st.top();
        else
            return 0;
    }
};
// @lc code=end
