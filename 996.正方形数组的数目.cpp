/*
 * @lc app=leetcode.cn id=996 lang=cpp
 *
 * [996] 正方形数组的数目
 */

// @lc code=start
class Solution
{
public:
    int numSquarefulPerms(vector<int> &nums)
    {
        int res = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> vis(n, 0);
        vector<int> tmp;
        function<void()> dfs = [&]() {
            if (n == tmp.size())
            {
                ++res;
                return;
            }
            if (0 == tmp.size())
            {
                for (int i = 0; i < n; ++i)
                {
                    if (i > 0 && nums[i] == nums[i - 1])
                        continue;
                    vis[i] = 1;
                    tmp.emplace_back(nums[i]);
                    dfs();
                    tmp.pop_back();
                    vis[i] = 0;
                }
            }
            else
            {
                int cur = tmp.back();
                for (int i = 0; i < n; ++i)
                {
                    if (vis[i])
                        continue;
                    int sqr = sqrt(cur + nums[i]);
                    if (sqr * sqr != (cur + nums[i]))
                        continue;
                    bool flag = false;
                    for (int j = i - 1; j >= 0; --j)
                        if (nums[j] < nums[i])
                            break;
                        else if (nums[j] == nums[i])
                        {
                            if (0 == vis[j])
                            {
                                flag = true;
                                break;
                            }
                        }
                    if (flag)
                        continue;
                    vis[i] = 1;
                    tmp.emplace_back(nums[i]);
                    dfs();
                    tmp.pop_back();
                    vis[i] = 0;
                }
            }
        };
        dfs();
        return res;
    }
};
// @lc code=end
