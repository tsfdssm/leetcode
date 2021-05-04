/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
#include <unordered_set>
#include <string>

using namespace std;

class Solution
{
public:
    unordered_set<string> st;
    string target;

    int n;
    bool dfs(int i)
    {
        if (i == target.size())
            return true;
        for (auto it = st.begin(); it != st.end(); ++it)
        {
            if (i + (*it).size() <= target.size())
            {
                if (target.substr(i, (*it).size()) == (*it))
                    if (true == dfs(i + (*it).size()))
                        return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        for (const auto &str : wordDict)
            st.insert(str);
        target = s;
        n = s.size();
        return dfs(0);
    }
};
// @lc code=end

int main()
{
    Solution a;
    string s = "catsandog";
    vector<string> &wordDict = {"cats", "dog", "sand", "and", "cat"};
    int res = a.wordBreak(s, wordDict);
    return 0;
};
