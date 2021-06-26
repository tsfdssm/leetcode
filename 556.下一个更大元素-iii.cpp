/*
 * @lc app=leetcode.cn id=556 lang=cpp
 *
 * [556] 下一个更大元素 III
 */

// @lc code=start
class Solution
{
public:
    int nextGreaterElement(int n)
    {
        string num = to_string(n);
        int k = num.size();
        for (int i = k - 2; i >= 0; --i)
        {
            if ((num[i] >= num[i + 1]))
                continue;
            else
            {
                char c = num[i];
                int j = k - 1;
                while (num[j] <= c)
                    --j;
                swap(num[i], num[j]);
                reverse(num.begin() + i + 1, num.end());
                long long res = stol(num);
                if (res > INT_MAX)
                    break;
                return (int)res;
            }
        }
        return -1;
    }
};
// @lc code=end
