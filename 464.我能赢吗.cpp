/*
 * @lc app=leetcode.cn id=464 lang=cpp
 *
 * [464] 我能赢吗
 */

// @lc code=start
#define len 21
class Solution
{
public:
    int maxCh;
    int desir;
    unordered_map<int, int> mp;

    bool dfs(int sum, bitset<len> &bs)
    {
        if (sum >= desir)
            return true;
        if (mp.count((int)bs.to_ullong()))
            return mp[(int)bs.to_ullong()];
        bool res = true;
        for (int i = 1; i <= maxCh; ++i)
        {
            if (bs[i])
                continue;
            bs[i] = 1;
            if (dfs(sum + i, bs))
            {
                res = false;
                bs[i] = 0;
                break;
            }
            bs[i] = 0;
        }
        return mp[(int)bs.to_ullong()] = res;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal)
    {
        maxCh = maxChoosableInteger;
        desir = desiredTotal;
        if (maxCh >= desir)
            return true;
        if ((maxCh + 1) * maxCh / 2 < desir)
            return false;
        bitset<len> bs;
        for (int i = 1; i <= maxCh; ++i)
        {

            bs[i] = 1;
            if (dfs(i, bs))
                return true;
            bs[i] = 0;
        }
        return false;
    }
};
// @lc code=end
