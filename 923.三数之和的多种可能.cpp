/*
 * @lc app=leetcode.cn id=923 lang=cpp
 *
 * [923] 三数之和的多种可能
 */

// @lc code=start
class Solution
{
public:
    int threeSumMulti(vector<int> &arr, int target)
    {
        const int mod = 1e9 + 7;
        int n = arr.size();
        long res = 0;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); ++i)
        {
            int subsum = target - arr[i];
            int j = i + 1;
            int k = arr.size() - 1;
            while (j < k)
            {
                if (arr[j] + arr[k] > subsum)
                    --k;
                else if (arr[j] + arr[k] < subsum)
                    ++j;
                else
                {
                    if (arr[j] != arr[k])
                    {
                        long l = 1;
                        while (j + 1 < k && arr[j] == arr[j + 1])
                        {
                            ++j;
                            ++l;
                        }
                        long r = 1;
                        while (k - 1 > j && arr[k] == arr[k - 1])
                        {
                            --k;
                            ++r;
                        }
                        res = (res + l * r) % mod;
                        ++j;
                        --k;
                    }
                    else
                    {
                        int cnt = k - j + 1;
                        res = (res + (cnt - 1) * cnt / 2) % mod;
                        break;
                    }
                }
            }
        }
        return res;
        //Wrong
        // sort(arr.begin(), arr.end());
        // unordered_map<int, int> mp;
        // unordered_map<int, int> idx;
        // int n = arr.size();
        // for (int i = 0; i < n; ++i)
        // {
        //     mp[arr[i]]++;
        //     idx[arr[i]] = i;
        // }
        // long res = 0;
        // const int mod = 1e9 + 7;
        // for (int i = 0; i < n - 1; ++i)
        //     for (int j = i + 1; j < n; ++j)
        //     {
        //         int t = target - arr[i] - arr[j];
        //         if (t < arr[j] || !mp.count(t))
        //             continue;
        //         res = (res + min(mp[t], idx[t] - j)) % mod;
        //     }
        // return res;

        //TLE
        // unordered_map<int, vector<int>> mp;
        // int n = arr.size();
        // for (int i = 0; i < n; ++i)
        //     mp[arr[i]].emplace_back(i);
        // long res = 0;
        // const int mod = 1e9 + 7;
        // for (int i = 0; i < n - 1; ++i)
        //     for (int j = i + 1; j < n; ++j)
        //     {
        //         int t = target - arr[i] - arr[j];
        //         if (!mp.count(t))
        //             continue;
        //         int cnt = mp[t].end() - upper_bound(mp[t].begin(), mp[t].end(), j);
        //         res = (res + cnt) % mod;
        //     }
        // return res;
    }
};
// @lc code=end
