/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray
{
public:
    vector<int> res;
    NumArray(vector<int> &nums)
    {
        res = nums;
    }

    int sumRange(int left, int right)
    {
        int ans = 0;
        for (int i = left; i <= right; ++i)
        {
            ans += res[i];
        }
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
