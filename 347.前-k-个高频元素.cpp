/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution
{
public:
    // bool cmp(pair<int, int> &a, pair<int, int> &b)
    // {
    //     return a.second > b.second;
    // }
    // struct cmp
    // {
    //     bool operator()(pair<int, int> &a, pair<int, int> &b)
    //     {
    //         return a.second > b.second;
    //     }
    // };
    static bool cmp(pair<int, int> &m, pair<int, int> &n)
    {
        return m.second > n.second;
    }

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        unordered_map<int, int> mp;
        for (int num : nums)
            mp[num]++;
        for (auto it : mp)
        {
            if (q.size() < k)
            {
                q.push(make_pair(it.first, it.second));
            }
            else if (q.top().second < it.second)
            {
                q.pop();
                q.push(make_pair(it.first, it.second));
            }
            else
            {
            }
        }
        vector<int> res(k);
        int index = 0;
        while (!q.empty())
        {
            res[index++] = q.top().first;
            q.pop();
        }
        return res;
    }
};
// @lc code=end
