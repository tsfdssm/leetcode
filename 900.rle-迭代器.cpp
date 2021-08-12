/*
 * @lc app=leetcode.cn id=900 lang=cpp
 *
 * [900] RLE 迭代器
 */

// @lc code=start
class RLEIterator
{
public:
    vector<int> nums;
    int idx = 0;
    int use = 0;
    RLEIterator(vector<int> &encoding)
    {
        for (int i = 0; i < encoding.size(); i += 2)
        {
            if (encoding[i] != 0)
            {
                nums.emplace_back(encoding[i]);
                nums.emplace_back(encoding[i + 1]);
            }
        }
    }

    int next(int n)
    {
        for (; idx < nums.size() && n > 0; idx += 2)
        {
            if (use + n >= nums[idx])
            {
                n -= nums[idx] - use;
                use = 0;
            }
            else
            {
                use += n;
                n = 0;
                break;
            }
        }
        if (idx == nums.size())
        {
            if (n == 0)
                return nums[idx - 1];
            else
                return -1;
        }
        if (use == 0)
            return nums[idx - 1];
        return nums[idx + 1];
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
// @lc code=end
