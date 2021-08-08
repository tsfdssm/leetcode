/*
 * @lc app=leetcode.cn id=854 lang=cpp
 *
 * [854] 相似度为 K 的字符串
 */

// @lc code=start
class Solution
{
public:
    int kSimilarity(string A, string B)
    {
        if (A == B)
            return 0;
        unordered_set<string> close;
        int n = A.size();
        unordered_map<string, int> dist;
        struct cmp
        {
            bool operator()(const pair<vector<int>, string> &l, const pair<vector<int>, string> &r)
            {
                return l.first[0] > r.first[0];
            }
        };
        priority_queue<pair<vector<int>, string>, vector<pair<vector<int>, string>>, cmp> open;
        int cur_g = 0;
        int cur_h = h(A, B);
        open.push({{cur_g + cur_h, cur_g}, A});
        dist[A] = 0;
        while (!open.empty())
        {
            auto top = open.top();
            open.pop();
            auto cur_str = top.second;
            auto cur_g = top.first[1];
            if (dist[cur_str] < cur_g)
                continue;
            if (cur_str == B)
                return cur_g;
            //状态转移是不是一定转移那些不同的字符？
            close.insert(cur_str);
            int i = 0;
            for (; i < n && cur_str[i] == B[i]; i++)
                ;
            for (int j = i + 1; j < n; j++)
            {
                if (cur_str[j] == B[i])
                {
                    auto next_str = cur_str;
                    swap(next_str[i], next_str[j]);
                    if (!close.count(next_str))
                    {
                        auto next_g = cur_g + 1;
                        auto next_h = next_g + h(next_str, B);
                        if (!dist.count(next_str) || dist[next_str] > next_g)
                        {
                            dist[next_str] = next_g;
                            open.push({{next_h, next_g}, next_str});
                        }
                    }
                }
            }
        }
        return 0;
    }
    int h(const string &s, const string &end)
    {
        int sum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            sum += s[i] != end[i];
        }
        return (sum + 1) / 2;
    }
};
// @lc code=end
