/*
 * @lc app=leetcode.cn id=1170 lang=cpp
 *
 * [1170] 比较字符串最小字母出现频次
 *
 * https://leetcode.cn/problems/compare-strings-by-frequency-of-the-smallest-character/description/
 *
 * algorithms
 * Medium (61.89%)
 * Likes:    51
 * Dislikes: 0
 * Total Accepted:    15.1K
 * Total Submissions: 24.4K
 * Testcase Example:  '["cbd"]\n["zaaaz"]'
 *
 * 定义一个函数 f(s)，统计 s  中（按字典序比较）最小字母的出现频次 ，其中 s 是一个非空字符串。
 *
 * 例如，若 s = "dcce"，那么 f(s) = 2，因为字典序最小字母是 "c"，它出现了 2 次。
 *
 * 现在，给你两个字符串数组待查表 queries 和词汇表 words 。对于每次查询 queries[i] ，需统计 words 中满足
 * f(queries[i]) < f(W) 的 词的数目 ，W 表示词汇表 words 中的每个词。
 *
 * 请你返回一个整数数组 answer 作为答案，其中每个 answer[i] 是第 i 次查询的结果。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：queries = ["cbd"], words = ["zaaaz"]
 * 输出：[1]
 * 解释：查询 f("cbd") = 1，而 f("zaaaz") = 3 所以 f("cbd") < f("zaaaz")。
 *
 *
 * 示例 2：
 *
 *
 * 输入：queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
 * 输出：[1,2]
 * 解释：第一个查询 f("bbb") < f("aaaa")，第二个查询 f("aaa") 和 f("aaaa") 都 > f("cc")。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 * 1
 * queries[i][j]、words[i][j] 都由小写英文字母组成
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words)
    {
        const int N = 2005;
        vector<int> cnt(N, 0);
        vector<int> sum(N + 1, 0);
        auto f = [&](const string &s)
        {
            vector<int> tmp(26, 0);
            for (char c : s)
                tmp[c - 'a']++;
            for (int i = 0; i < 26; ++i)
                if (tmp[i] > 0)
                    return tmp[i];
            return 0;
        };
        for (auto &str : words)
            cnt[f(str)]++;
        for (int i = 1; i < N; ++i)
            sum[i] = sum[i - 1] + cnt[i - 1];
        int m = words.size();
        int n = queries.size();
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i)
            res[i] = m - sum[f(queries[i]) + 1];
        return res;
    }
};
// @lc code=end
