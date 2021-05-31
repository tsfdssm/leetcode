/*
 * @lc app=leetcode.cn id=327 lang=cpp
 *
 * [327] 区间和的个数
 */

// @lc code=start
class Solution
{
public:
    vector<long long> tree;

    inline long long lowbit(long long x)
    {
        return x & -x;
    }

    void update(long long x, int val)
    {
        while (x < tree.size())
        {
            tree[x] += val;
            x += lowbit(x);
        }
    }

    long long query(long long x)
    {
        long long sum = 0;
        while (x > 0)
        {
            sum += tree[x];
            x -= lowbit(x);
        }
        return sum;
    }
    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        vector<long long> preSum = {0};
        long long sum = 0;
        for (int num : nums)
        {
            sum += (long long)num;
            preSum.push_back(sum);
        }
        set<long long> allNum;
        unordered_map<long long, int> values;

        for (long long sum : preSum)
        {
            allNum.insert(sum);
            allNum.insert(sum - upper);
            allNum.insert(sum - lower);
        }
        tree.resize(allNum.size() + 1, 0);
        int idx = 0;
        for (long long num : allNum)
            values[num] = idx++;

        int res = 0;
        for (int i = 0; i < preSum.size(); ++i)
        {
            int left = values[preSum[i] - upper];
            int right = values[preSum[i] - lower];
            res += query(right + 1) - query(left);
            update(values[preSum[i]] + 1, 1);
        }
        return res;
    }
};
// @lc code=end
