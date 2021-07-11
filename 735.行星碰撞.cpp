/*
 * @lc app=leetcode.cn id=735 lang=cpp
 *
 * [735] 行星碰撞
 */

// @lc code=start
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> stk;
        for (int num : asteroids)
        {
            if (stk.empty() || num > 0)
            {
                stk.push(num);
            }
            else
            {
                if (stk.top() < 0)
                    stk.push(num);
                else if (stk.top() + num == 0)
                    stk.pop();
                else
                {
                    while (!stk.empty() && stk.top() > 0 && stk.top() + num < 0)
                        stk.pop();

                    if (stk.empty() || stk.top() < 0)
                        stk.push(num);
                    else if (stk.top() + num == 0)
                        stk.pop();
                }
            }
        }
        vector<int> res;
        while (!stk.empty())
        {
            res.emplace_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
