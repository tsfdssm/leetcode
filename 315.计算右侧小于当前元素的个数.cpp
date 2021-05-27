/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
class Solution
{
public:
    vector<int> tree;
    vector<int> a;
    void init(int n)
    {
        tree.resize(n, 0);
    }

    inline int lowbit(int i)
    {
        return i & (-i);
    }
    int find(int pos)
    {
        int res = 0;
        while (pos > 0)
        {
            res += tree[pos];
            pos -= lowbit(pos);
        }
        return res;
    }

    void update(int pos)
    {
        while (pos < tree.size())
        {
            tree[pos]++;
            pos += lowbit(pos);
        }
    }
    void discretization(vector<int> &num)
    {
        a.assign(num.begin(), num.end());
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
    }

    int getID(int x)
    {
        return lower_bound(a.begin(), a.end(), x) - a.begin();
    }
    vector<int> countSmaller(vector<int> &nums)
    {
        discretization(nums);
        int n = nums.size();
        init(a.size());
        vector<int> res(n);

        for (int i = n - 1; i >= 0; --i)
        {
            int id = getID(nums[i]);
            res[i] = find(id);
            update(id + 1);
        }
        return res;
    }
};
// @lc code=end
