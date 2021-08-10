/*
 * @lc app=leetcode.cn id=869 lang=cpp
 *
 * [869] 重新排序得到 2 的幂
 */

// @lc code=start
class Solution
{
public:
    bool reorderedPowerOf2(int n)
    {
        string s = to_string(n);
        for (int i = 31; i >= 0; --i)
        {
            string tmp = (to_string(1 << i));
            if (isSameSeq(s, tmp))
                return true;
        }
        return false;
    }

    inline bool isSameSeq(const string &s, const string &target)
    {
        if (s.size() != target.size())
            return false;
        vector<int> cnt(10, 0);
        int n = target.size();
        for (int i = 0; i < n; ++i)
        {
            cnt[target[i] - '0']++;
            cnt[s[i] - '0']--;
        }
        for (int i = 0; i < 10; ++i)
            if (cnt[i] != 0)
                return false;
        return true;
    }
};
// @lc code=end
