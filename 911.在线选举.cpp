/*
 * @lc app=leetcode.cn id=911 lang=cpp
 *
 * [911] 在线选举
 */

// @lc code=start
class TopVotedCandidate
{
public:
    vector<int> res;
    vector<int> &my_time;
    TopVotedCandidate(vector<int> &persons, vector<int> &times) : my_time(times)
    {
        int n = times.size();
        res.resize(n);
        int maxn = 0;
        int tmp = -1;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i)
        {
            mp[persons[i]]++;
            if (mp[persons[i]] >= maxn)
            {
                maxn = mp[persons[i]];
                tmp = persons[i];
            }
            res[i] = tmp;
        }
    }

    int q(int t)
    {
        int idx = upper_bound(my_time.begin(), my_time.end(), t) - my_time.begin() - 1;
        return res[idx];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
// @lc code=end
