/*
 * @lc app=leetcode.cn id=457 lang=cpp
 *
 * [457] 环形数组是否存在循环
 */

// @lc code=start
class Solution
{
public:
    bool circularArrayLoop(vector<int> &nums)
    {

        int n = nums.size();
        for (int i = 0; i < n; ++i)
            nums[i] = nums[i] % n;
        vector<int> vis(n, 0);
        int flag = 1;
        for (int i = 0; i < n; ++i)
        {
            if (0 != vis[i])
                continue;
            if (0 == nums[i])
            {
                vis[i] = -1;
                continue;
            }
            flag = nums[i] > 0 ? 1 : -1;
            int j = i;
            while (vis[j] == 0)
            {
                vis[j] = 1;
                j = (nums[j] + j + n) % n;
                if (nums[j] * flag <= 0)
                    break;
            }
            if (vis[j] > 0)
                return true;
            j = i;
            while (vis[j] >= 0)
            {
                vis[j] = -1;
                j = (nums[j] + j + n) % n;
                if (nums[j] * flag <= 0)
                    break;
            }
        }
        return false;
    }
};
// @lc code=end
