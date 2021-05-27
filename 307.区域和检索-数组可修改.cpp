/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start
class NumArray
{
public:
    vector<int> tree;
    inline int lowbit(int x)
    {
        return x & -x;
    }
    int query(int x)
    {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i))
            ans += tree[i];
        return ans;
    }
    void add(int x, int u)
    {
        for (int i = x; i <= n; i += lowbit(i))
            tree[i] += u;
    }
    int n;
    vector<int> nums;
    NumArray(vector<int> &_nums)
    {
        nums = _nums;
        n = nums.size();
        tree.resize(n + 1);
        for (int i = 0; i < n; ++i)
            add(i + 1, nums[i]);
    }

    void update(int i, int val)
    {
        add(i + 1, val - nums[i]);
        nums[i] = val;
    }

    int sumRange(int left, int right)
    {
        return query(right + 1) - query(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end
