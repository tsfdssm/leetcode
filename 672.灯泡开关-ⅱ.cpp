/*
 * @lc app=leetcode.cn id=672 lang=cpp
 *
 * [672] 灯泡开关 Ⅱ
 */

// @lc code=start
class Solution
{
public:
    int flipLights(int n, int presses)
    {
        const int N = 1001;
        unordered_set<bitset<N>> st;
        st.insert(bitset<N>());
        for (int i = 0; i < presses; ++i)
        {
            unordered_set<bitset<N>> nxt_st;
            for (const auto bits : st)
            {
                bitset<N> b1, b2, b3, b4 = b3 = b2 = b1 = bits;
                for (int j = 0; j < n; ++j)
                    b1.flip(j);
                for (int j = 1; j < n; j += 2)
                    b2.flip(j);
                for (int j = 0; j < n; j += 2)
                    b3.flip(j);
                for (int j = 0; j < n; j += 3)
                    b4.flip(j);
                nxt_st.emplace(b1);
                nxt_st.emplace(b2);
                nxt_st.emplace(b3);
                nxt_st.emplace(b4);
            }
            st = move(nxt_st);
        }
        return st.size();
    }
};
// @lc code=end
