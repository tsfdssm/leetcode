/*
 * @lc app=leetcode.cn id=436 lang=cpp
 *
 * [436] 寻找右区间
 */

// @lc code=start
class Solution
{
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        unordered_map<int, int> mp;
        int n = intervals.size();
        vector<int> vec(n, 0);
        for (int i = 0; i < n; ++i)
        {
            vec[i] = intervals[i][0];
            mp[intervals[i][0]] = i;
        }
        sort(vec.begin(), vec.end());

        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i)
        {
            if (intervals[i][1] > vec.back())
                res[i] = -1;
            else
                res[i] = mp[find(intervals[i][1], vec)];
        }
        return res;
    }

    int find(int target, vector<int> &vec)
    {
        int l = 0;
        int r = vec.size();
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (vec[mid] >= target)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return vec[l];
    }
};
// @lc code=end
