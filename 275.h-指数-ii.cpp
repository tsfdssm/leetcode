/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
 */

// @lc code=start
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        int l = 0, r = n;

        while (l < r)
        {
            int mid = (r - l) / 2 + l;
            if (citations[mid] == n - mid)
                return n - mid;
            else if (citations[mid] > n - mid)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return n - l;
    }
};
// @lc code=end
