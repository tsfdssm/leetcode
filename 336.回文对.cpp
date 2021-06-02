/*
 * @lc app=leetcode.cn id=336 lang=cpp
 *
 * [336] 回文对
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        vector<string> rev;
        unordered_map<string, int> mp;
        int n = words.size();
        for (const string &s : words)
        {
            rev.emplace_back(s);
            reverse(rev.back().begin(), rev.back().end());
        }
        for (int i = 0; i < n; ++i)
        {
            mp[rev[i]] = i;
        }

        vector<vector<int>> res;
        for (int i = 0; i < n; ++i)
        {
            if (words[i].empty())
                continue;
            string view(words[i]);
            int m = view.size();
            for (int j = 0; j <= m; ++j)
            {
                if (j && isPal(view, 0, j))
                {
                    string tmp = view.substr(j, m - j);
                    if (mp.end() != mp.find(tmp) && mp[tmp] != i)
                        res.push_back({mp[tmp], i});
                }
                if (isPal(view, j, m))
                {
                    string tmp = view.substr(0, j);
                    if (mp.end() != mp.find(tmp) && mp[tmp] != i)
                        res.push_back({i, mp[tmp]});
                }
            }
        }
        return res;
    }

    inline bool isPal(const string_view &view, int l, int r)
    {
        if (l > r)
            return false;
        --r;
        while (l < r)
        {
            if (view[l] != view[r])
                return false;
            ++l;
            --r;
        }
        return true;
    }
};
// @lc code=end
