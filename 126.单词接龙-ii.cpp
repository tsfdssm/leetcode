/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;
// @lc code=start

const int INF = 1 << 20;

class Solution
{
private:
    unordered_map<string, int> wordId;
    vector<string> idWord;
    vector<vector<int>> edges;

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        int id = 0;
        for (const string &word : wordList)
        {
            if (!wordId.count(word))
            {
                wordId[word] = id++;
                idWord.push_back(word);
            }
        }
        if (!wordId.count(endWord))
        {
            return {};
        }
        if (!wordId.count(beginWord))
        {
            wordId[beginWord] = id++;
            idWord.push_back(beginWord);
        }
        edges.resize(idWord.size());
        for (int i = 0; i < idWord.size(); i++)
        {
            for (int j = i + 1; j < idWord.size(); j++)
            {
                if (transformCheck(idWord[i], idWord[j]))
                {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
        const int dest = wordId[endWord];
        vector<vector<string>> res;
        queue<vector<int>> q;
        vector<int> cost(id, INF);
        q.push(vector<int>{wordId[beginWord]});
        cost[wordId[beginWord]] = 0;
        while (!q.empty())
        {
            vector<int> now = q.front();
            q.pop();
            int last = now.back();
            if (last == dest)
            {
                vector<string> tmp;
                for (int index : now)
                {
                    tmp.push_back(idWord[index]);
                }
                res.push_back(tmp);
            }
            else
            {
                for (int i = 0; i < edges[last].size(); i++)
                {
                    int to = edges[last][i];
                    if (cost[last] + 1 <= cost[to])
                    {
                        cost[to] = cost[last] + 1;
                        vector<int> tmp(now);
                        tmp.push_back(to);
                        q.push(tmp);
                    }
                }
            }
        }
        return res;
    }

    bool transformCheck(const string &str1, const string &str2)
    {
        int differences = 0;
        for (int i = 0; i < str1.size() && differences < 2; i++)
        {
            if (str1[i] != str2[i])
            {
                ++differences;
            }
        }
        return differences == 1;
    }
};
// class Solution
// {
// public:
//     int sum = 0, n = 0;
//     unordered_map<string, int> words;
//     vector<vector<int>> adj;
//     vector<int> pre, vis, dis, post;
//     vector<vector<string>> res;
//     void bfs(int s, int t, vector<string> &wordList)
//     {
//         vis[s] = 1;
//         dis[s] = 0;
//         queue<int> begin;
//         begin.push(s);
//         while (!begin.empty())
//         {
//             int st = begin.front();
//             begin.pop();
//             for (int i = 0; i < n; ++i)
//             {
//                 if (1 == vis[i] && dis[i] < dis[st] + 1 || i == s)
//                     continue;
//                 if (adj[st][i] > 0)
//                 {
//                     if (t == i)
//                     {
//                         if ((dis[t] >= (dis[st] + 1)) || (INT_MAX == dis[t]))
//                         {
//                             dis[t] = dis[st] + 1;
//                             post[st] = t;
//                             pre[t] = st;
//                             vector<string> tmp;
//                             for (int k = t, j = 0; k != s && j < n && k != -1; k = pre[k], ++j)
//                             {
//                                 tmp.emplace_back(wordList[k]);
//                             }
//                             tmp.emplace_back(wordList[s]);
//                             reverse(tmp.begin(), tmp.end());
//                             res.push_back(tmp);
//                         }
//                         else
//                         {
//                             break;
//                         }
//                     }
//                     else
//                     {
//                         vis[i] = 1;
//                         post[st] = i;
//                         pre[i] = st;
//                         dis[i] = dis[st] + 1;
//                         begin.push(i);
//                     }
//                 }
//             }
//         }
//         return;
//     }
//     bool near(string &a, string &b)
//     {
//         int cnt = 0;
//         for (int i = 0; i < a.size() && cnt < 2; ++i)
//         {
//             if (a[i] != b[i])
//                 cnt++;
//         }
//         if (1 == cnt)
//             return true;
//         return false;
//     }
//     vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
//     {
//         if (wordList.size() == 0)
//             return res;
//         for (int i = 0; i < wordList.size(); ++i)
//             words.insert(pair<string, int>{wordList[i], i});
//         if (words.find(endWord) == words.end())
//             return res;
//         n = words.size();
//         if (words.find(beginWord) == words.end())
//         {
//             words.insert(pair<string, int>{beginWord, n});
//             wordList.emplace_back(beginWord);
//             n++;
//         }
//         adj.resize(n, vector<int>(n, 0));
//         post.resize(n, -1);
//         pre.resize(n, -1);
//         dis.resize(n, INT_MAX);
//         vis.resize(n, 0);
//         int st = words[beginWord];
//         int ed = words[endWord];
//         for (int i = 0; i < wordList.size(); ++i)
//         {
//             for (int j = i + 1; j < wordList.size(); ++j)
//             {
//                 if (near(wordList[i], wordList[j]))
//                 {
//                     adj[i][j] = 1;
//                     adj[j][i] = 1;
//                 }
//             }
//             if (near(wordList[i], beginWord))
//             {
//                 adj[i][st] = 1;
//                 adj[st][i] = 1;
//             }
//         }
//         bfs(st, ed, wordList);
//         return res;
//     }
// };
// @lc code=end
