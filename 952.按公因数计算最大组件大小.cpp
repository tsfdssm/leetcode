/*
 * @lc app=leetcode.cn id=952 lang=cpp
 *
 * [952] 按公因数计算最大组件大小
 */

// @lc code=start

class Solution
{
public:
    vector<int> f;
    int find(int x)
    {
        if (x == f[x])
            return x;
        return f[x] = find(f[x]);
    }
    void merge(int x, int y)
    {
        f[find(y)] = find(x);
    }
    int largestComponentSize(vector<int> &nums)
    {
        int n = nums.size();
        f.resize(n);
        for (int i = 0; i < n; ++i)
            f[i] = i;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i)
        {
            int num = nums[i];
            if (1 == num)
                continue;

            if (mp.count(num))
                merge(mp[num], i);
            else
                mp[num] = i;

            for (int k = 2; k * k <= num; ++k)
            {
                if (num % k != 0)
                    continue;
                if (mp.count(k))
                    merge(mp[k], i);
                else
                    mp[k] = i;

                if (mp.count(num / k))
                    merge(mp[num / k], i);
                else
                    mp[num / k] = i;
            }
        }
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; ++i)
        {
            cnt[find(i)]++;
        }
        int res = 0;
        for (auto it = cnt.begin(); it != cnt.end(); ++it)
            res = max(res, it->second);
        return res;
    }
};
// @lc code=end
