/*
 * @lc app=leetcode.cn id=546 lang=cpp
 *
 * [546] 移除盒子
 */

// @lc code=start
class Solution
{
public:
    int dp[100][100][100];

    int removeBoxes(vector<int> &boxes)
    {
        memset(dp, 0, sizeof(dp));
        return calculatePoints(boxes, 0, boxes.size() - 1, 0);
    }

    int calculatePoints(vector<int> &boxes, int l, int r, int k)
    {
        if (l > r)
            return 0;
        if (dp[l][r][k] == 0)
        {
            int r1 = r, k1 = k;
            while (r1 > l && boxes[r1] == boxes[r1 - 1])
            {
                r1--;
                k1++;
            }
            dp[l][r][k] = calculatePoints(boxes, l, r1 - 1, 0) + (k1 + 1) * (k1 + 1);
            for (int i = l; i < r1; ++i)
                if (boxes[i] == boxes[r])
                    dp[l][r][k] = max(dp[l][r][k], calculatePoints(boxes, l, i, k1 + 1) + calculatePoints(boxes, i + 1, r1 - 1, 0));
        }
        return dp[l][r][k];

        // if (l > r)
        //     return 0;
        // if (dp[l][r][k] == 0)
        // {
        //     dp[l][r][k] = calculatePoints(boxes, l, r - 1, 0) + (k + 1) * (k + 1);
        //     for (int i = l; i < r; ++i)
        //         if (boxes[i] == boxes[r])
        //             dp[l][r][k] = max(dp[l][r][k], calculatePoints(boxes, l, i, k + 1) + calculatePoints(boxes, i + 1, r - 1, 0));
        // }
        // return dp[l][r][k];
    }
};
// @lc code=end
