/*
 * @lc app=leetcode.cn id=932 lang=cpp
 *
 * [932] 漂亮数组
 */

// @lc code=start
class Solution
{
public:
    unordered_map<int, vector<int>> mp;
    vector<int> beautifulArray(int n)
    {
        mp[1] = {1};
        return f(n);
    }
    vector<int> f(int n)
    {
        if (mp.count(n))
            return mp[n];
        else
        {
            int l = (n + 1) / 2;
            int r = n / 2;
            auto vec = f(l);
            auto vecr = f(r);
            vec.insert(vec.end(), vecr.begin(), vecr.end());
            for (int i = 0; i < l; ++i)
                vec[i] = vec[i] * 2 - 1;
            for (int i = l; i < n; ++i)
                vec[i] = vec[i] * 2;
            mp[n] = vec;
            return vec;
        }
    }
};
// @lc code=end
