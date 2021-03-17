/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string countAndSay(int n)
    {
        if (1 == n)
            return "1";
        string s = countAndSay(n - 1);
        string res;
        int start = 0;

        for (int i = 1; i < s.size(); i++)
        {
            if (s[start] != s[i])
            {
                res.push_back(i - start + '0');
                res.push_back(s[start]);
                start = i;
            }
        }
        res.push_back(s.size() - start + '0');
        res.push_back(s[start]);
        return res;
    }
};
// @lc code=end
