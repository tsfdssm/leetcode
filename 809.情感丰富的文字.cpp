/*
 * @lc app=leetcode.cn id=809 lang=cpp
 *
 * [809] 情感丰富的文字
 */

// @lc code=start
class Solution
{
public:
    int expressiveWords(string s, vector<string> &words)
    {
        int n = s.size();
        int cnt = 0;
        for (string &word : words)
        {
            int m = word.size();
            int i = 0, j = 0;
            while (i < n && j < m)
            {
                if (s[i] != word[j])
                    break;
                int ii = i + 1;
                int jj = j + 1;
                while (ii < n && s[i] == s[ii])
                    ++ii;
                while (jj < m && word[j] == word[jj])
                    ++jj;
                if ((ii - i < jj - j) || (ii - i > jj - j) && (ii - i < 3))
                    break;
                i = ii;
                j = jj;
            }

            if (i == n && j == m)
                ++cnt;
        }
        return cnt;
    }
};
// @lc code=end
