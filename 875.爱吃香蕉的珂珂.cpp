/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        //sort(piles.begin(), piles.end());

        auto isOk = [&](int speed) {
            int cnt = 0;
            for (int i = 0; i < piles.size(); ++i)
                cnt += piles[i] / speed + (piles[i] % speed != 0);
            return cnt <= h;
        };
        // long long sum = accumulate(piles.begin(), piles.end(), (long long)0);
        // if (sum < h)
        //     return 1;
        int l = 1, r = 1e9;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (isOk(mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
// @lc code=end
