/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */

// @lc code=start
class Solution
{
public:
    bool isSubStr(const string &a, const string &b)
    {
        int i = 0;
        for (char c : b)
            if (i < a.size() && a[i] == c)
                ++i;
        return i == a.size();
    }
    string findLongestWord(string s, vector<string> &dictionary)
    {
        sort(dictionary.begin(), dictionary.end(), [](const string &a, const string &b) { return a.size() > b.size() || a.size() == b.size() && a < b; });
        for (const string &cur : dictionary)
            if (isSubStr(cur, s))
                return cur;
        return "";
    }
};
// @lc code=end
