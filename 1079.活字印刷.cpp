/*
 * @lc app=leetcode.cn id=1079 lang=cpp
 *
 * [1079] 活字印刷
 *
 * https://leetcode-cn.com/problems/letter-tile-possibilities/description/
 *
 * algorithms
 * Medium (73.28%)
 * Likes:    138
 * Dislikes: 0
 * Total Accepted:    13.3K
 * Total Submissions: 18.2K
 * Testcase Example:  '"AAB"'
 *
 * 你有一套活字字模 tiles，其中每个字模上都刻有一个字母 tiles[i]。返回你可以印出的非空字母序列的数目。
 *
 * 注意：本题中，每个活字字模只能使用一次。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入："AAB"
 * 输出：8
 * 解释：可能的序列为 "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA"。
 *
 *
 * 示例 2：
 *
 *
 * 输入："AAABBC"
 * 输出：188
 *
 *
 * 示例 3：
 *
 *
 * 输入："V"
 * 输出：1
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= tiles.length <= 7
 * tiles 由大写英文字母组成
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int res = 0;
    void dfs(string &str, vector<int> &visit)
    {
        for (int i = 0; i < str.size(); ++i)
        {
            if ((i > 0) && (str[i] == str[i - 1]) && (visit[i - 1] == 0))
                continue;
            if (visit[i] == 0)
            {
                visit[i] = 1;
                res++;
                dfs(str, visit);
                visit[i] = 0;
            }
        }
        return;
    }
    int numTilePossibilities(string tiles)
    {
        vector<int> visit = vector<int>(tiles.size(), 0);
        sort(tiles.begin(), tiles.end());
        dfs(tiles, visit);
        return res;
    }
};
// @lc code=end
