/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */

// @lc code=start
class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        //vector<string> all;
        unordered_map<string, int> mp;
        int n = 0;
        for (auto &vec : equations)
        {
            if (mp.find(vec[0]) == mp.end())
            {
                mp.insert(make_pair(vec[0], n++));
                //all.emplace_back(vec[0]);
            }
            if (mp.find(vec[1]) == mp.end())
            {
                mp.insert(make_pair(vec[1], n++));
                //all.emplace_back(vec[1]);
            }
        }
        //int n = all.size();
        vector<vector<double>> adj(n, vector<double>(n, -1.0));
        for (int i = 0; i < n; ++i)
            adj[i][i] = 1.0;
        for (int i = 0; i < equations.size(); ++i)
        {
            auto &vec = equations[i];
            int div = mp[vec[0]];
            int bediv = mp[vec[1]];
            adj[div][bediv] = values[i];
            adj[bediv][div] = 1 / values[i];
        }
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                {
                    if (adj[i][k] >= 0 && adj[k][j] >= 0)
                        adj[i][j] = adj[i][k] * adj[k][j];
                }
        vector<double> res(queries.size(), -1.0);
        for (int i = 0; i < queries.size(); ++i)
        {
            string a = queries[i][0];
            string b = queries[i][1];
            if (mp.count(a) && mp.count(b))
                res[i] = adj[mp[a]][mp[b]];
        }
        return res;
    }
};
// @lc code=end
