/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 */

// @lc code=start
class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        int res = 0;
        int mask = 0;
        for (int i = 30; i >= 0; --i)
        {
            mask = mask | (1 << i);

            unordered_set<int> st;

            int tmp = res | (1 << i);
            for (int num : nums)
            {
                if (st.count(num & mask ^ tmp))
                {
                    res = tmp;
                    break;
                }
                else
                    st.insert(num & mask);
            }
        }
        return res;
        // int res = 0;
        // int n = nums.size();
        // for (int i = 0; i < n; ++i)
        //     for (int j = i + 1; j < n; ++j)
        //         res = res < (nums[i] ^ nums[j]) ? (nums[i] ^ nums[j]) : res;
        // return res;
    }
};
// @lc code=end
