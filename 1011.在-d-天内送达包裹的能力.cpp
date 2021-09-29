/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start
class Solution
{
public:
    int shipWithinDays(vector<int> &a, int d)
    {
        int n = a.size();

        vector<int> psum(n + 1, 0);
        for (int i = 0; i < n; ++i)
            psum[i + 1] = psum[i] + a[i];
        int sum = psum[n];
        function<bool(int)> check = [&](int cap) {
            int cur = 0;
            int cnt = 0;
            int idx = 0;
            while (idx < n)
            {
                idx = upper_bound(psum.begin() + idx + 1, psum.end(), cur + cap) - psum.begin() - 1;
                cur = psum[idx];
                ++cnt;
                if (cnt > d)
                    return false;
            }
            return true;
        };
        int l = *max_element(a.begin(), a.end()), r = sum;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (check(mid))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};
// @lc code=end
