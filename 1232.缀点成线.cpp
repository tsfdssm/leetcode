/*
 * @lc app=leetcode.cn id=1232 lang=cpp
 *
 * [1232] 缀点成线
 *
 * https://leetcode.cn/problems/check-if-it-is-a-straight-line/description/
 *
 * algorithms
 * Easy (46.37%)
 * Likes:    114
 * Dislikes: 0
 * Total Accepted:    40K
 * Total Submissions: 86.3K
 * Testcase Example:  '[[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]'
 *
 * 给定一个数组 coordinates ，其中 coordinates[i] = [x, y] ， [x, y] 表示横坐标为 x、纵坐标为 y
 * 的点。请你来判断，这些点是否在该坐标系中属于同一条直线上。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= coordinates.length <= 1000
 * coordinates[i].length == 2
 * -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
 * coordinates 中不含重复的点
 *
 *
 */

// @lc code=start
class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &c)
    {
        int a0, a1, b0, b1;
        int n = c.size();
        a0 = c[1][1] - c[0][1];
        a1 = c[1][0] - c[0][0];
        for (int i = 2; i < n; ++i)
        {
            if (a0 * (c[i][0] - c[i - 1][0]) != a1 * (c[i][1] - c[i - 1][1]))
                return false;
            a0 = c[i][1] - c[i - 1][1];
            a1 = c[i][0] - c[i - 1][0];
        }
        return true;
    }
};
// @lc code=end
