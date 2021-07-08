/*
 * @lc app=leetcode.cn id=721 lang=cpp
 *
 * [721] 账户合并
 */

// @lc code=start
class UnionFind
{
public:
    vector<int> parent;
    UnionFind(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void Merge(int x, int y)
    {
        parent[find(y)] = find(x);
    }
};
class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        map<string, int> emailToIndex;
        map<string, string> emailToName;
        int cnt = 0;
        for (auto &account : accounts)
        {
            string &name = account[0];
            int size = account.size();
            for (int i = 1; i < size; ++i)
            {
                string &email = account[i];
                if (!emailToIndex.count(email))
                {
                    emailToIndex[email] = cnt++;
                    emailToName[email] = name;
                }
            }
        }
        UnionFind uf(cnt);
        for (auto &account : accounts)
        {
            string &firstEmail = account[1];
            int firstIndex = emailToIndex[firstEmail];
            int size = account.size();
            for (int i = 2; i < size; ++i)
            {
                string &email = account[i];
                int index = emailToIndex[email];
                uf.Merge(firstIndex, index);
            }
        }
        map<int, vector<string>> indexToEmail;
        for (const auto &[email, _] : emailToIndex)
        {
            int index = uf.find(emailToIndex[email]);
            indexToEmail[index].emplace_back(email);
        }
        vector<vector<string>> merge(indexToEmail.size());
        int i = 0;
        for (const auto [_, emails] : indexToEmail)
        {
            merge[i].emplace_back(emailToName[emails[0]]);
            merge[i].insert(merge[i].end(), emails.begin(), emails.end());
            ++i;
        }
        return merge;
    }
};
// @lc code=end
