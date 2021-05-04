/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */

// @lc code=start
class Solution
{
public:
    unordered_map<int, vector<string>> ans;
    unordered_set<string> wordSet;

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        wordSet = unordered_set(wordDict.begin(), wordDict.end());
        backtrack(s, 0);
        return ans[0];
    }

    void backtrack(const string &s, int index)
    {
        if (!ans.count(index))
        {
            if (index == s.size())
            {
                ans[index] = {""};
                return;
            }
            ans[index] = {};
            for (int i = index + 1; i <= s.size(); ++i)
            {
                string word = s.substr(index, i - index);
                if (wordSet.count(word))
                {
                    backtrack(s, i);
                    for (const auto &succ : ans[i])
                        ans[index].push_back(succ.empty() ? word : word + " " + succ);
                }
            }
        }
    }
};
// @lc code=end
