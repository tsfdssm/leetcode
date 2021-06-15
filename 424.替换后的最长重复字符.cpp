/*
 * @lc app=leetcode.cn id=424 lang=cpp
 *
 * [424] 替换后的最长重复字符
 */

// @lc code=start
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        vector<int> nums(26, 0);
        int maxn = 0;
        int n = s.size();
        int l = 0, r = 0;
        while (r < n)
        {
            nums[s[r] - 'A']++;
            maxn = max(maxn, nums[s[r] - 'A']);
            if (r - l + 1 - maxn > k)
            {
                nums[s[l] - 'A']--;
                l++;
            }
            ++r;
        }
        return r - l;
    }
};
// @lc code=end
