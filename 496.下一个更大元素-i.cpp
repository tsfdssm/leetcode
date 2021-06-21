/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> res(n1, 0);
        unordered_map<int, int> mp;
        stack<int> stk;

        for (const int num : nums2)
        {
            while (!stk.empty() && stk.top() < num)
            {
                mp[stk.top()] = num;
                stk.pop();
            }
            stk.push(num);
        }
        while (!stk.empty())
        {
            mp[stk.top()] = -1;
            stk.pop();
        }

        for (int i = 0; i < n1; ++i)
            res[i] = mp[nums1[i]];

        return res;
    }
};
// @lc code=end
