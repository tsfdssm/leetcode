/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        if (1 == n)
            return 1;
        if (2 == n)
        {
            if (nums[0] == nums[1])
                return 1;
            return 2;
        }
        bool flag;
        //true:up
        //false:low
        stack<int> st;
        int init = 1;
        st.push(nums[0]);
        while (init < n)
        {
            if (nums[init] == st.top())
            {
                ++init;
                continue;
            }
            if (nums[init] > st.top())
                flag = true;
            else
                flag = false;
            st.push(nums[init]);
            break;
        }
        for (int i = init + 1; i < n; ++i)
        {
            if (nums[i] == st.top())
                continue;
            if (nums[i] > st.top())
            {
                if (flag)
                {
                    st.pop();
                }
                st.push(nums[i]);
                flag = true;
            }
            else
            {
                if (!flag)
                {
                    st.pop();
                }
                st.push(nums[i]);
                flag = false;
            }
        }
        return st.size();
    }
};
// @lc code=end
