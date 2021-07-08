/*
 * @lc app=leetcode.cn id=719 lang=cpp
 *
 * [719] 找出第 k 小的距离对
 */

// @lc code=start
class Solution
{
public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums.back() - nums.front();
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            int cnt = 0;
            for (int i = 0, j = 0; j < n; ++j)
            {
                while (i < j && nums[j] - nums[i] > mid)
                    ++i;
                cnt += j - i;
            }

            if (cnt >= k)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
        // map<int, int> mp;
        // int n = nums.size();
        // for (int i = 0; i < n; ++i)
        //     for (int j = i + 1; j < n; ++j)
        //         mp[abs(nums[i] - nums[j])]++;
        // auto it = mp.begin();
        // while (k > 0)
        // {
        //     k -= it->second;
        //     ++it;
        // }
        // --it;
        // return it->first;
    }
};
// @lc code=end
