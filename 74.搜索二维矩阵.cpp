/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (target < matrix[0][0] || target > matrix.back().back())
            return false;
        int l_l = 0, r_l = matrix.size() - 1;
        int line = l_l;
        while (l_l <= r_l)
        {
            int mid = (l_l + r_l) / 2;
            if (target >= matrix[mid][0])
            {
                line = mid;
                l_l = mid + 1;
            }
            else
            {
                r_l = mid - 1;
            }
        }

        int l = 0, r = matrix[0].size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (target == matrix[line][mid])
                return true;
            else if (target < matrix[line][mid])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return false;
    }
};
// @lc code=end
