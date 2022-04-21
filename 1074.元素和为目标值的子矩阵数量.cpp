/*
 * @lc app=leetcode.cn id=1074 lang=cpp
 *
 * [1074] 元素和为目标值的子矩阵数量
 *
 * https://leetcode-cn.com/problems/number-of-submatrices-that-sum-to-target/description/
 *
 * algorithms
 * Hard (66.97%)
 * Likes:    190
 * Dislikes: 0
 * Total Accepted:    19.7K
 * Total Submissions: 29.4K
 * Testcase Example:  '[[0,1,0],[1,1,1],[0,1,0]]\n0'
 *
 * 给出矩阵 matrix 和目标值 target，返回元素总和等于目标值的非空子矩阵的数量。
 *
 * 子矩阵 x1, y1, x2, y2 是满足 x1  且 y1  的所有单元 matrix[x][y] 的集合。
 *
 * 如果 (x1, y1, x2, y2) 和 (x1', y1', x2', y2') 两个子矩阵中部分坐标不同（如：x1 !=
 * x1'），那么这两个子矩阵也不同。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
 * 输出：4
 * 解释：四个只含 0 的 1x1 子矩阵。
 *
 *
 * 示例 2：
 *
 *
 * 输入：matrix = [[1,-1],[-1,1]], target = 0
 * 输出：5
 * 解释：两个 1x2 子矩阵，加上两个 2x1 子矩阵，再加上一个 2x2 子矩阵。
 *
 *
 * 示例 3：
 *
 *
 * 输入：matrix = [[904]], target = 0
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 * -1000
 * -10^8
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int cnt = 0;
        int pre = 0;
        for (auto &x : nums)
        {
            pre += x;
            if (mp.find(pre - k) != mp.end())
                cnt += mp[pre - k];
            mp[pre]++;
        }
        return cnt;
    }
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        int res = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i)
        {
            vector<int> sum(n);
            for (int j = i; j < m; ++j)
            {
                for (int c = 0; c < n; ++c)
                    sum[c] += matrix[j][c];
                res += subarraySum(sum, target);
            }
        }
        return res;
    }
};
// @lc code=end
