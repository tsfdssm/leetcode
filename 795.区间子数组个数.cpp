/*
 * @lc app=leetcode.cn id=795 lang=cpp
 *
 * [795] 区间子数组个数
 */

// @lc code=start
class Solution
{
public:
    int numSubarrayBoundedMax(vector<int> &nums, int left, int right)
    {
        int n = nums.size();
        set<int> r{-1, n};
        set<int> l{-1, n};
        for (int i = 0; i < n; ++i)
        {
            int num = nums[i];
            if (num >= left)
            {
                l.insert(i);
                if (num > right)
                {
                    r.insert(i);
                }
            }
        }
        long long less_r = cnt(r);
        long long less_l = cnt(l);
        return (int)(less_r - less_l);
    }

    long long cnt(set<int> &st)
    {
        auto it1 = st.begin(), it2 = st.begin();
        it2++;
        long long res = 0;
        while (it2 != st.end())
        {
            long long len = *it2 - *it1 - 1;
            if (len > 0)
            {
                res += len * (len + 1) / 2;
            }
            ++it1;
            ++it2;
        }
        return res;
    }
};
// @lc code=end
