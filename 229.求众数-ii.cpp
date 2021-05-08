/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 求众数 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        if (0 == nums.size())
            return {};
        int m = 0, cm = 0;
        int n = 0, cn = 0;
        for (const auto &num : nums)
        {
            if (m == num)
                ++cm;
            else if (n == num)
                ++cn;
            else if (0 == cm)
            {
                m = num;
                ++cm;
            }
            else if (0 == cn)
            {
                n = num;
                ++cn;
            }
            else
            {
                --cm;
                --cn;
            }
        }
        cm = 0;
        cn = 0;
        int k = nums.size() / 3;
        for (const auto &num : nums)
        {
            if (m == num)
                ++cm;
            else if (n == num)
                ++cn;
        }
        vector<int> res;
        if (cm > k)
            res.push_back(m);
        if (cn > k)
            res.push_back(n);
        return res;
        // unordered_map<int, int> mp;
        // vector<int> res;
        // int n = nums.size();
        // int k = n / 3;
        // for (int i = 0; i < n; ++i)
        //     mp[nums[i]]++;
        // // for (auto it = mp.begin(); it != mp.end(); ++it)
        // // {
        // //     if (it->second > k)
        // //         res.push_back(it->first);
        // // }
        // for (auto tmp : mp)
        // {
        //     if (tmp.second > k)
        //         res.push_back(tmp.first);
        // }
        // return res;
    }
};
// @lc code=end
