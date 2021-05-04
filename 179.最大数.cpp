/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        string res;
        vector<string> strs;
        for (const auto num : nums)
            strs.push_back(to_string(num));
        sort(strs.begin(), strs.end(), cmp);
        for (const auto str : strs)
            res += str;

        for (auto it = res.begin(); it != res.end();)
        {
            if (*it != '0' || (it + 1) == res.end())
                break;
            else
            {
                it = res.erase(it);
            }
        }
        return res;
    }
    static bool cmp(string &a, string &b)
    {
        return a + b > b + a;
    }
};
// @lc code=end
