/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
public:
    int sum = 0, n = 0;
    unordered_map<string, int> words;
    vector<vector<int>> adj;
    vector<int> pre, vis, dis;
    vector<vector<int>> res;
    void bfs(int s, int t)
    {
        vis[s] = 1;
        vis[t] = 2;
        dis[s] = 0;
        dis[t] = 0;
        queue<int> begin;
        queue<int> end;
        begin.push(s);
        end.push(t);
        while (!begin.empty() && !end.empty())
        {
            int st = begin.front();
            begin.pop();
            for (int i = 0; i < n; ++i)
            {
                if (1 == vis[i])
                    continue;
                if (adj[st][i] > 0)
                {
                    if (2 == vis[i])
                    {
                        sum = dis[st] + dis[i] + 2;
                        return;
                    }
                    else
                    {
                        vis[i] = 1;
                        dis[i] = dis[st] + 1;
                        begin.push(i);
                    }
                }
            }
            int ed = end.front();
            end.pop();
            for (int i = 0; i < n; ++i)
            {
                if (2 == vis[i])
                    continue;
                if (adj[ed][i] > 0)
                {
                    if (1 == vis[i])
                    {
                        sum = dis[i] + dis[ed] + 2;
                        return;
                    }
                    else
                    {
                        vis[i] = 2;
                        dis[i] = dis[ed] + 1;
                        end.push(i);
                    }
                }
            }
        }
        return;
    }
    bool near(string &a, string &b)
    {
        int cnt = 0;
        for (int i = 0; i < a.size() && cnt < 2; ++i)
        {
            if (a[i] != b[i])
                cnt++;
        }
        if (1 == cnt)
            return true;
        return false;
    }
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        for (int i = 0; i < wordList.size(); ++i)
        {
            words.insert(pair<string, int>{wordList[i], i});
            //words[wordList[i]] = i;
        }
        n = words.size();
        if (words.find(beginWord) == words.end())
        {
            words.insert(pair<string, int>{beginWord, n});
            n++;
        }
        if (words.find(endWord) == words.end())
            return 0;
        adj.resize(n, vector<int>(n, 0));
        pre.resize(n, -1);
        dis.resize(n, INT_MAX);
        vis.resize(n, 0);
        int st = words[beginWord];
        int ed = words[endWord];
        for (int i = 0; i < wordList.size(); ++i)
        {
            for (int j = i + 1; j < wordList.size(); ++j)
            {
                if (near(wordList[i], wordList[j]))
                {
                    adj[i][j] = 1;
                    adj[j][i] = 1;
                }
            }
            if (near(wordList[i], beginWord))
            {
                adj[i][st] = 1;
                adj[st][i] = 1;
            }
        }
        bfs(st, ed);
        return sum;
    }
};
// @lc code=end
