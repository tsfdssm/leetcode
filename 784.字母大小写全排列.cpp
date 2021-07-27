/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
class Solution
{
public:
    vector<string> vec;
    vector<int> index;
    void dfs(string &s, int i)
    {
        if (i == index.size())
            return;
        char c = s[index[i]];
        if (isLess(c))
            s[index[i]] += 'A' - 'a';
        else
            s[index[i]] += 'a' - 'A';
        vec.emplace_back(s);
        dfs(s, i + 1);
        c = s[index[i]];
        if (isLess(c))
            s[index[i]] += 'A' - 'a';
        else
            s[index[i]] += 'a' - 'A';
        dfs(s, i + 1);
    }
    vector<string> letterCasePermutation(string s)
    {
        vec.emplace_back(s);
        for (int i = 0; i < s.size(); ++i)
        {
            if (isLess(s[i]) || isUpper(s[i]))
                index.emplace_back(i);
        }
        dfs(s, 0);
        return vec;
    }

    inline bool isLess(char c)
    {
        return ('a' <= c && c <= 'z');
    }
    inline bool isUpper(char c)
    {
        return ('A' <= c && c <= 'Z');
    }
};
// @lc code=end
