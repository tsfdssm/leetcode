/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        unordered_set<string> st;
        st.insert(wordDict.begin(), wordDict.end());

        for (const auto &word : wordDict)
            st.insert(word);
        for (int i = 0; i < n + 1; ++i)
        {
            if (1 == dp[i])
                for (const auto &word : wordDict)
                {
                    if (i + word.size() < n + 1 && word == s.substr(i, word.size()))
                        dp[i + word.size()] = 1;
                }
        }
        return dp[n];
    }
    //     unordered_set<string> st;
    // string target;

    // int n;
    // bool dfs(int i)
    // {
    //     if (i == target.size())
    //         return true;
    //     for (auto it = st.begin(); it != st.end(); ++it)
    //     {
    //         if (i + (*it).size() <= target.size())
    //         {
    //             if (target.substr(i, (*it).size()) == (*it))
    //                 if (true == dfs(i + (*it).size()))
    //                     return true;
    //         }
    //     }
    //     return false;
    // }
    // bool wordBreak(string s, vector<string> &wordDict)
    // {
    //     for (const auto &str : wordDict)
    //         st.insert(str);
    //     target = s;
    //     n = s.size();
    //     return dfs(0);
    // }
};
// @lc code=end
