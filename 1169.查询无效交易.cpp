/*
 * @lc app=leetcode.cn id=1169 lang=cpp
 *
 * [1169] 查询无效交易
 *
 * https://leetcode.cn/problems/invalid-transactions/description/
 *
 * algorithms
 * Medium (32.49%)
 * Likes:    29
 * Dislikes: 0
 * Total Accepted:    7.6K
 * Total Submissions: 23.5K
 * Testcase Example:  '["alice,20,800,mtv","alice,50,100,beijing"]'
 *
 * 如果出现下述两种情况，交易 可能无效：
 *
 *
 * 交易金额超过 $1000
 * 或者，它和 另一个城市 中 同名 的另一笔交易相隔不超过 60 分钟（包含 60 分钟整）
 *
 *
 * 给定字符串数组交易清单 transaction 。每个交易字符串 transactions[i]
 * 由一些用逗号分隔的值组成，这些值分别表示交易的名称，时间（以分钟计），金额以及城市。
 *
 * 返回 transactions，返回可能无效的交易列表。你可以按 任何顺序 返回答案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
 * 输出：["alice,20,800,mtv","alice,50,100,beijing"]
 * 解释：第一笔交易是无效的，因为第二笔交易和它间隔不超过 60 分钟、名称相同且发生在不同的城市。同样，第二笔交易也是无效的。
 *
 * 示例 2：
 *
 *
 * 输入：transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
 * 输出：["alice,50,1200,mtv"]
 *
 *
 * 示例 3：
 *
 *
 * 输入：transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
 * 输出：["bob,50,1200,mtv"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * transactions.length <= 1000
 * 每笔交易 transactions[i] 按 "{name},{time},{amount},{city}" 的格式进行记录
 * 每个交易名称 {name} 和城市 {city} 都由小写英文字母组成，长度在 1 到 10 之间
 * 每个交易时间 {time} 由一些数字组成，表示一个 0 到 1000 之间的整数
 * 每笔交易金额 {amount} 由一些数字组成，表示一个 0 到 2000 之间的整数
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<string> invalidTransactions(vector<string> &t)
    {
        int n = t.size();
        map<string, map<string, vector<pair<int, int>>>> all;
        map<string, vector<pair<int, int>>> p;

        vector<string> peo(n);
        vector<int> ti(n);
        vector<int> am(n);
        vector<string> ci(n);
        for (int index = 0; index < n; ++index)
        {
            auto &str = t[index];
            int i = 0;
            while (str[i] != ',')
                ++i;
            int j = i + 1;
            while (str[j] != ',')
                ++j;
            int k = j + 1;
            while (str[k] != ',')
                ++k;
            const string &name = str.substr(0, i);
            int time = stoi(str.substr(i + 1, j - i - 1));
            int amount = stoi(str.substr(j + 1, k - j - 1));
            const string &city = str.substr(k + 1);

            peo[index] = name;
            ti[index] = time;
            am[index] = amount;
            ci[index] = city;
            all[name][city].push_back({time, amount});
            p[name].push_back({time, amount});
        }

        for (auto &a : all)
            for (auto &vec : a.second)
            {
                sort(vec.second.begin(), vec.second.end());
            }
        for (auto &a : p)
            sort(a.second.begin(), a.second.end());
        vector<string> res;

        for (int i = 0; i < n; ++i)
        {
            if (am[i] > 1000)
            {
                res.push_back(t[i]);
                continue;
            }
            const string &name = peo[i];
            int time = ti[i];
            int amount = am[i];
            const string &city = ci[i];

            pair<int, int> l = {time - 60, -1};
            pair<int, int> u = {time + 60, 1000};
            int cnt = upper_bound(p[name].begin(), p[name].end(), u) - lower_bound(p[name].begin(), p[name].end(), l);
            int cnt_same = upper_bound(all[name][city].begin(), all[name][city].end(), u) - lower_bound(all[name][city].begin(), all[name][city].end(), l);
            if (cnt - cnt_same > 0)
                res.push_back(t[i]);
        }
        return res;
    }
};
// @lc code=end
