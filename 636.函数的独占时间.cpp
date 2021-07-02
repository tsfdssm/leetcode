/*
 * @lc app=leetcode.cn id=636 lang=cpp
 *
 * [636] 函数的独占时间
 */

// @lc code=start
class Solution
{
public:
    vector<int> exclusiveTime(int n, vector<string> &logs)
    {
        vector<int> res(n, 0);
        stack<int> stk;
        int time = 0;
        int len = logs.size();
        for (int i = 0; i < len; ++i)
        {
            auto &log = logs[i];
            int j = 0;
            while (j < log.size() && log[j] != ':')
                ++j;
            int idx = stoi(log.substr(0, j));
            bool flag = true;
            ++j;
            if (log[j] == 'e')
                flag = false;
            while (j < log.size() && log[j] != ':')
                ++j;
            ++j;
            int t = stoi(log.substr(j));

            if (stk.empty())
            {
                stk.push(idx);
                time = t;
                continue;
            }
            int last = stk.top();
            if (flag)
            {
                res[last] += t - time;
                time = t;
                stk.push(idx);
            }
            else
            {
                res[last] += t - time + 1;
                time = t + 1;
                stk.pop();
            }
        }
        return res;
    }
};
// @lc code=end
