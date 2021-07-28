/*
 * @lc app=leetcode.cn id=804 lang=cpp
 *
 * [804] 唯一摩尔斯密码词
 */

// @lc code=start
class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        vector<string> mos = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        set<string> res;
        for (string word : words)
        {
            string tmp;
            for (char c : word)
                tmp += mos[c - 'a'];
            res.insert(tmp);
        }
        return res.size();
    }
};
// @lc code=end
