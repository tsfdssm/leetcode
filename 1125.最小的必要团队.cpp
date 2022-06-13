/*
 * @lc app=leetcode.cn id=1125 lang=cpp
 *
 * [1125] 最小的必要团队
 *
 * https://leetcode.cn/problems/smallest-sufficient-team/description/
 *
 * algorithms
 * Hard (50.07%)
 * Likes:    81
 * Dislikes: 0
 * Total Accepted:    3.8K
 * Total Submissions: 7.5K
 * Testcase Example:  '["java","nodejs","reactjs"]\n[["java"],["nodejs"],["nodejs","reactjs"]]'
 *
 * 作为项目经理，你规划了一份需求的技能清单 req_skills，并打算从备选人员名单 people 中选出些人组成一个「必要团队」（ 编号为 i
 * 的备选人员 people[i] 含有一份该备选人员掌握的技能列表）。
 *
 * 所谓「必要团队」，就是在这个团队中，对于所需求的技能列表 req_skills
 * 中列出的每项技能，团队中至少有一名成员已经掌握。可以用每个人的编号来表示团队中的成员：
 *
 *
 * 例如，团队 team = [0, 1, 3] 表示掌握技能分别为 people[0]，people[1]，和 people[3] 的备选人员。
 *
 *
 * 请你返回 任一 规模最小的必要团队，团队成员用人员编号表示。你可以按 任意顺序 返回答案，题目数据保证答案存在。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：req_skills = ["java","nodejs","reactjs"], people =
 * [["java"],["nodejs"],["nodejs","reactjs"]]
 * 输出：[0,2]
 *
 *
 * 示例 2：
 *
 *
 * 输入：req_skills = ["algorithms","math","java","reactjs","csharp","aws"],
 * people =
 * [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
 * 输出：[1,2]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 * req_skills[i] 由小写英文字母组成
 * req_skills 中的所有字符串 互不相同
 * 1
 * 0
 * 1
 * people[i][j] 由小写英文字母组成
 * people[i] 中的所有字符串 互不相同
 * people[i] 中的每个技能是 req_skills 中的技能
 * 题目数据保证「必要团队」一定存在
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<int> smallestSufficientTeam(vector<string> &req, vector<vector<string>> &peo)
    {
        int m = req.size();
        int n = peo.size();
        unordered_map<string, int> mp;
        int index = 0;
        for (auto &str : req)
            mp[str] = index++;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            auto &vec = peo[i];
            int sk = 0;
            for (auto &str : vec)
                if (mp.count(str))
                    sk |= 1 << mp[str];
            a[i] = sk;
        }
        int total = 1 << m;
        int len = total - 1;
        vector<long long> dp(total, -1);
        dp[0] = 0;
        for (int i = 0; i < len; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dp[i] & (1LL << j))
                    continue;
                int k = i | a[j];
                // int cnt = solve(dp[k]);
                // int cur = solve(dp[i]) + 1;
                int cnt = __builtin_popcountll(dp[k]);
                int cur = __builtin_popcountll(dp[i]) + 1;
                if (cur < cnt)
                    dp[k] = dp[i] | (1LL << j);
            }
        }
        vector<int> ans;
        for (int j = 0; j < 64; ++j)
            if (dp[len] & (1LL << j))
                ans.push_back(j);
        return ans;
    }

    int solve(unsigned long long n)
    {
        int res = 0;
        while (n > 0)
        {
            if (n & 1)
                ++res;
            n >>= 1;
        }
        return res;
    }
};
// @lc code=end
