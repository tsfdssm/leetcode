/*
 * @lc app=leetcode.cn id=957 lang=cpp
 *
 * [957] N 天后的牢房
 */

// @lc code=start
class Solution
{
public:
    vector<int> prisonAfterNDays(vector<int> &cells, int n)
    {
        //n = 3;
        unordered_map<int, int> mpNum;
        unordered_map<int, int> mpPos;
        for (int i = 1; i <= n; ++i)
        {
            vector<int> nxt(8, 0);
            int num = 0;
            for (int j = 1; j < 7; ++j)
            {

                nxt[j] = !(cells[j - 1] ^ cells[j + 1]);

                num ^= (nxt[j] << j);
            }
            cells = move(nxt);
            if (mpNum.count(num))
            {
                int st = mpNum[num];
                int cycle = i - st;
                n -= i;
                n %= cycle;
                int res = mpPos[st + n];
                for (int j = 0; j < 8; ++j)
                {
                    cells[j] = ((res >> j) & 1);
                }
                break;
            }
            else
            {
                mpNum[num] = i;
                mpPos[i] = num;
            }
        }
        return cells;
    }
};
// @lc code=end
