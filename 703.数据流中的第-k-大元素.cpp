/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第 K 大元素
 */

// @lc code=start
class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> q;
    int k = 0;
    KthLargest(int K, vector<int> &nums)
    {
        k = K;
        for (int num : nums)
        {
            if (q.size() < k)
                q.push(num);
            else if (num > q.top())
            {
                q.push(num);
                q.pop();
            }
            else
            {
            }
        }
    }

    int add(int val)
    {
        if (q.size() < k)
            q.push(val);
        else if (val > q.top())
        {
            q.push(val);
            q.pop();
        }
        else
        {
        }
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
