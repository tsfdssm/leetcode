/*
 * @lc app=leetcode.cn id=1202 lang=cpp
 *
 * [1202] 交换字符串中的元素
 *
 * https://leetcode.cn/problems/smallest-string-with-swaps/description/
 *
 * algorithms
 * Medium (50.67%)
 * Likes:    276
 * Dislikes: 0
 * Total Accepted:    29.3K
 * Total Submissions: 57.8K
 * Testcase Example:  '"dcab"\n[[0,3],[1,2]]'
 *
 * 给你一个字符串 s，以及该字符串中的一些「索引对」数组 pairs，其中 pairs[i] = [a, b] 表示字符串中的两个索引（编号从 0
 * 开始）。
 *
 * 你可以 任意多次交换 在 pairs 中任意一对索引处的字符。
 *
 * 返回在经过若干次交换后，s 可以变成的按字典序最小的字符串。
 *
 *
 *
 * 示例 1:
 *
 * 输入：s = "dcab", pairs = [[0,3],[1,2]]
 * 输出："bacd"
 * 解释：
 * 交换 s[0] 和 s[3], s = "bcad"
 * 交换 s[1] 和 s[2], s = "bacd"
 *
 *
 * 示例 2：
 *
 * 输入：s = "dcab", pairs = [[0,3],[1,2],[0,2]]
 * 输出："abcd"
 * 解释：
 * 交换 s[0] 和 s[3], s = "bcad"
 * 交换 s[0] 和 s[2], s = "acbd"
 * 交换 s[1] 和 s[2], s = "abcd"
 *
 * 示例 3：
 *
 * 输入：s = "cba", pairs = [[0,1],[1,2]]
 * 输出："abc"
 * 解释：
 * 交换 s[0] 和 s[1], s = "bca"
 * 交换 s[1] 和 s[2], s = "bac"
 * 交换 s[0] 和 s[1], s = "abc"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^5
 * 0 <= pairs.length <= 10^5
 * 0 <= pairs[i][0], pairs[i][1] < s.length
 * s 中只含有小写英文字母
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<int> f;

    int find(int x)
    {
        if (f[x] == x)
            return x;
        return f[x] = find(f[x]);
    }

    void merge(int x, int y)
    {
        if (find(x) != find(y))
            f[find(y)] = find(x);
    }
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        int n = s.size();
        f.resize(n);
        for (int i = 0; i < n; ++i)
            f[i] = i;
        for (auto &vec : pairs)
        {
            int x = vec[0];
            int y = vec[1];
            merge(x, y);
        }
        map<int, vector<int>> mp;
        map<int, string> str;
        for (int i = 0; i < n; ++i)
        {
            mp[find(i)].push_back(i);
            str[find(i)].push_back(s[i]);
        }

        for (auto it = str.begin(); it != str.end(); ++it)
        {
            sort(it->second.begin(), it->second.end());
        }

        for (auto &[id, vec] : mp)
        {
            int m = vec.size();
            for (int j = 0; j < m; ++j)
                s[vec[j]] = str[id][j];
        }

        return s;
    }
};
// @lc code=end
