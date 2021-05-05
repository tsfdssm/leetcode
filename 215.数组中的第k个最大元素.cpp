/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        for (int i = 0; i < k; ++i)
        {
            swim(nums, i);
        }
        for (int i = k; i < nums.size(); ++i)
        {
            if (nums[i] < nums[0])
                continue;
            swap(nums[0], nums[i]);
            sink(nums, 0, k);
        }
        return nums[0];
        // priority_queue<int, vector<int>, greater<int>> q(nums.begin(), nums.begin() + k);
        // for (int i = k; i < nums.size(); ++i)
        // {
        //     if (nums[i] > q.top())
        //     {
        //         //nums[0] = 6;
        //         //swap(q.top(), nums[i]);
        //         q.pop();
        //         q.push(nums[i]);
        //     }
        // }
        // return q.top();
    }

    int cmp(int a, int b) { return a < b; };

    void swim(vector<int> &nums, int i)
    {
        while (i > 0 && cmp(nums[i], nums[(i - 1) / 2]))
        {
            swap(nums[i], nums[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void sink(vector<int> &nums, int i, int N)
    {
        while (i * 2 + 1 < N)
        {
            int j = i * 2 + 1;
            if (j + 1 < N && cmp(nums[j + 1], nums[j]))
                j++;
            if (cmp(nums[i], nums[j]))
                break;
            else
                swap(nums[i], nums[j]);
            i = j;
        }
    }
};
// @lc code=end
