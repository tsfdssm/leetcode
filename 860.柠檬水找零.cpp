/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        multiset<int> st;
        for (int num : bills)
        {
            if (5 == num)
                st.insert(5);
            else if (10 == num)
            {
                if (!st.count(5))
                    return false;
                st.erase(st.find(5));
                st.insert(10);
            }
            else
            {
                if (!st.count(5))
                    return false;
                if (!st.count(10))
                {
                    if (3 > st.count(5))
                        return false;
                    for (int k = 0; k < 3; ++k)
                        st.erase(st.find(5));
                }
                else
                {
                    st.erase(st.find(5));
                    st.erase(st.find(10));
                }
            }
        }
        return true;
    }
};
// @lc code=end
