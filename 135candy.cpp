/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

#include <vector>
#include <string>
#include <stack>
using namespace std;
// @lc code=start
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        if (1 >= n)
            return n;
        stack<int> st;
        vector<int> res(n, 1);
        st.push(0);
        for (int i = 1; i < n; ++i)
        {
            // if (true == st.empty())
            // {
            //     st.push(i);
            //     res[i] = res[i - 1] + 1;
            //     continue;
            // }
            if (ratings[st.top()] <= ratings[i])
            {
                if (ratings[st.top()] < ratings[i])
                    res[i] = res[i - 1] + 1;
                int tmp_candy = res[st.top()];
                while (false == st.empty())
                {
                    int tmp = st.top();
                    st.pop();
                    res[tmp] = tmp_candy;
                    tmp_candy++;
                }
                st.push(i);
            }
            else
            {
                st.push(i);
            }
        }
        if (false == st.empty())
        {
            int tmp_candy = res[st.top()];
            while (false == st.empty())
            {
                int tmp = st.top();
                st.pop();
                res[tmp] = max(res[tmp,tmp_candy];
                tmp_candy++;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans += res[i];
        return ans;
    }
};
// @lc code=end

int main()
{
    vector<int> a = {1, 3, 4, 5, 2};
    Solution A;
    int res = A.candy(a);
    return 0;
}
