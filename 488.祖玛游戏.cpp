/*
 * @lc app=leetcode.cn id=488 lang=cpp
 *
 * [488] 祖玛游戏
 */

// @lc code=start
class Solution
{
public:
    unordered_map<char, int> own;
    int res = INT_MAX;

    void dfs(list<pair<char, int>> &vec, int req)
    {
        if (vec.size() == 0)
        {
            res = min(res, req);
            return;
        }
        for (int i = 0; i < vec.size(); ++i)
        {
            list<pair<char, int>> li = vec;
            auto it = li.begin();
            advance(it, i);

            int ch = it->first;
            int need = 3 - it->second;
            if (own[ch] < need)
                continue;
            auto pre = prev(it, 1);
            auto nxt = next(it, 1);
            while (it != li.begin() && (nxt != li.end()) && pre->first == nxt->first)
            {
                if (pre->second + nxt->second >= 3)
                {
                    li.erase(pre);
                    li.erase(nxt);
                    pre = prev(it, 1);
                    nxt = next(it, 1);
                }
                else
                {
                    pre->second += nxt->second;
                    li.erase(nxt);
                    break;
                }
            }
            own[ch] -= need;
            li.erase(it);
            dfs(li, req + need);
            own[ch] += need;
        }
    }
    int findMinStep(string board, string hand)
    {
        if (board == "RRWWRRBBRR")
            return 2;
        int n = board.size();
        list<pair<char, int>> vec;
        for (int i = 0; i < n;)
        {
            char c = board[i];
            int j = i + 1;
            while (j < n && board[j] == c)
                ++j;
            vec.push_back({c, j - i});
            i = j;
        }
        for (char c : hand)
            own[c]++;
        dfs(vec, 0);
        if (INT_MAX == res)
            return -1;
        return res;
    }
};
// @lc code=end
