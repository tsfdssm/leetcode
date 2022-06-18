/*
 * @lc app=leetcode.cn id=1209 lang=cpp
 *
 * [1209] 删除字符串中的所有相邻重复项 II
 *
 * https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string-ii/description/
 *
 * algorithms
 * Medium (51.25%)
 * Likes:    143
 * Dislikes: 0
 * Total Accepted:    15.3K
 * Total Submissions: 29.9K
 * Testcase Example:  '"abcd"\n2'
 *
 * 给你一个字符串 s，「k 倍重复项删除操作」将会从 s 中选择 k 个相邻且相等的字母，并删除它们，使被删去的字符串的左侧和右侧连在一起。
 *
 * 你需要对 s 重复进行无限次这样的删除操作，直到无法继续为止。
 *
 * 在执行完所有删除操作后，返回最终得到的字符串。
 *
 * 本题答案保证唯一。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "abcd", k = 2
 * 输出："abcd"
 * 解释：没有要删除的内容。
 *
 * 示例 2：
 *
 * 输入：s = "deeedbbcccbdaa", k = 3
 * 输出："aa"
 * 解释：
 * 先删除 "eee" 和 "ccc"，得到 "ddbbbdaa"
 * 再删除 "bbb"，得到 "dddaa"
 * 最后删除 "ddd"，得到 "aa"
 *
 * 示例 3：
 *
 * 输入：s = "pbbcggttciiippooaais", k = 2
 * 输出："ps"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^5
 * 2 <= k <= 10^4
 * s 中只含有小写英文字母。
 *
 *
 */

// @lc code=start
class Solution
{
public:
    using pci = pair<char, int>;
    string removeDuplicates(string s, int k)
    {
        list<pci> lst;
        // lst.push_back({'&', 0});
        int n = s.size();
        int cnt = 1;
        char pre = s[0];
        for (int i = 1; i < n; ++i)
        {
            if (pre == s[i])
                cnt++;
            else
            {
                lst.push_back({pre, cnt});
                cnt = 1;
                pre = s[i];
            }
        }
        lst.push_back({pre, cnt});

        for (auto it = lst.begin(); it != lst.end(); ++it)
        {
            if (it->second < k)
                continue;
            while (it->second > k)
                it->second -= k;
            if (it->second == k)
            {
                it = lst.erase(it);
                if (it == lst.begin())
                {
                    continue;
                }
                it = prev(it);
                auto nxt = next(it);
                if (nxt->first == it->first)
                {
                    it->second += nxt->second;
                    lst.erase(nxt);
                }
                --it;
            }
        }

        string res;
        for (auto [c, cnt] : lst)
        {
            res += string(cnt, c);
        }
        return res;
    }
};
// @lc code=end
