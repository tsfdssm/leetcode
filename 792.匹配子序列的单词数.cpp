/*
 * @lc app=leetcode.cn id=792 lang=cpp
 *
 * [792] 匹配子序列的单词数
 */

// @lc code=start
class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        int ans = 0;
        unordered_set<string> pass;
        unordered_set<string> fail;

        for (string w : words)
        {
            if (pass.count(w))
            {
                ans++;
                continue;
            }
            if (fail.count(w))
            {
                continue;
            }
            int sIdx = 0;
            int wIdx = 0;
            while (sIdx < s.size() && wIdx < w.size())
            {
                if (s[sIdx] == w[wIdx])
                {
                    sIdx++;
                    wIdx++;
                }
                else
                {
                    sIdx++;
                }
            }
            if (wIdx == w.size())
            {
                ans++;
                if (!pass.count(w))
                    pass.insert(w);
            }
            else
            {
                if (!fail.count(w))
                    fail.insert(w);
            }
        }
        return ans;
    }
};
// @lc code=end
