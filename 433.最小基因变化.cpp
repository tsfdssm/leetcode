/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 */

// @lc code=start
class Solution
{
public:
    int minMutation(string start, string end, vector<string> &bank)
    {

        queue<string> q{{start}};
        unordered_set<string> seen{{start}};
        unordered_set<string> st(bank.begin(), bank.end());
        int res = 0;
        while (!q.empty())
        {
            int len = q.size();
            while (len--)
            {
                const auto &cur = q.front();
                //q.pop();
                if (cur == end)
                    return res;
                for (int i = 0; i < 8; ++i)
                {
                    string nxt(cur);
                    for (const auto &c : {'A', 'C', 'G', 'T'})
                    {
                        if (cur[i] != c)
                            nxt[i] = c;
                        if (!st.count(nxt) || !seen.emplace(nxt).second)
                            continue;
                        q.emplace(nxt);
                    }
                }
                q.pop();
            }
            ++res;
        }
        return -1;
    }
};
// @lc code=end
