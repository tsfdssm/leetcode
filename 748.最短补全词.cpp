/*
 * @lc app=leetcode.cn id=748 lang=cpp
 *
 * [748] 最短补全词
 */

// @lc code=start
class Solution
{
public:
    string shortestCompletingWord(const string &licensePlate, vector<string> &words)
    {
        vector<int> target(26, 0);
        for (char c : licensePlate)
        {
            if (c <= 'z' && c >= 'a')
                target[c - 'a']++;
            else if ('A' <= c && c <= 'Z')
                target[c - 'A']++;
        }
        stable_sort(words.begin(), words.end(), [](const auto &a, const auto &b) { return a.size() < b.size(); });
        int n = words.size();
        vector<vector<int>> all(n, vector<int>(26, 0));
        for (int i = 0; i < n; ++i)
        {
            for (char c : words[i])
            {
                if (c <= 'z' && c >= 'a')
                    all[i][c - 'a']++;
                else if ('A' <= c && c <= 'Z')
                    all[i][c - 'A']++;
            }
            bool flag = true;
            for (int j = 0; j < 26; ++j)
            {
                if (target[j] > all[i][j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return words[i];
        }
        return "";
    }
};
// @lc code=end
