/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的K对数字
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        priority_queue<pair<int, vector<int>>> q;
        vector<vector<int>> res;

        for (const int &a : nums1)
            for (const int &b : nums2)
            {
                if (q.size() < k)
                {
                    q.push({a + b, {a, b}});
                }
                else
                {
                    if (q.top().first > (a + b))
                    {
                        q.pop();
                        q.push({a + b, {a, b}});
                    }
                }
            }
        while (!q.empty())
        {
            res.emplace_back(q.top().second);
            q.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
