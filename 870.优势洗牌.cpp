/*
 * @lc app=leetcode.cn id=870 lang=cpp
 *
 * [870] 优势洗牌
 */

// @lc code=start
class Solution
{
public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<pair<int, int>> tmp;
        for (int i = 0; i < n; ++i)
        {
            tmp.push_back({nums2[i], i});
        }
        sort(tmp.begin(), tmp.end());
        sort(nums1.begin(), nums1.end());
        vector<int> remain;
        vector<int> res(n, -1);
        int l = 0;
        int p1 = 0, p2 = 0;
        while (p1 < n && p2 < n)
        {
            while (p1 < n && nums1[p1] <= tmp[p2].first)
            {
                remain.emplace_back(nums1[p1]);
                ++p1;
            }
            if (p1 == n)
                break;
            res[tmp[p2].second] = nums1[p1];
            ++p1;
            ++p2;
        }
        int idx = 0;
        for (int i = 0; i < n; ++i)
            if (-1 != res[i])
                continue;
            else
            {
                res[i] = remain[idx++];
            }
        return res;
        //multiset<int> st(nums1.begin(), nums1.end());
        // vector<int>& st=nums1;
        // sort(st.begin(),st.end());
        // int n = nums1.size();
        // vector<int> res(n);
        // for (int i = 0; i < n; ++i)
        // {
        //     auto it = upper_bound(st.begin(), st.end(), nums2[i]);
        //     if (it == st.end())
        //     {
        //         res[i] = *st.begin();
        //         st.erase(st.begin());
        //     }
        //     else
        //     {
        //         res[i] = *it;
        //         st.erase(it);
        //     }
        // }
        // return res;
    }
};
// @lc code=end
