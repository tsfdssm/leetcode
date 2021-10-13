/*
 * @lc app=leetcode.cn id=1031 lang=cpp
 *
 * [1031] 两个非重叠子数组的最大和
 */

// @lc code=start
class Solution
{
public:
    int maxSumTwoNoOverlap(vector<int> &A, int L, int M)
    {
        //计算dp, 4个滑动窗口, 4种情况
        vector<vector<int>> dp(A.size(), vector<int>(4, 0));
        int presum = 0;
        int maxsum;
        for (int i = 0; i < L; ++i)
        {
            presum += A[i];
        }
        maxsum = presum;
        dp[L - 1][0] = maxsum;
        for (int i = L; i < A.size(); ++i)
        {
            presum -= A[i - L];
            presum += A[i];
            maxsum = max(maxsum, presum);
            dp[i][0] = maxsum;
        }

        presum = 0;
        for (int i = 0; i < M; ++i)
        {
            presum += A[i];
        }
        maxsum = presum;
        dp[M - 1][1] = maxsum;
        for (int i = M; i < A.size(); ++i)
        {
            presum -= A[i - M];
            presum += A[i];
            maxsum = max(maxsum, presum);
            dp[i][1] = maxsum;
        }

        presum = 0;
        for (int i = A.size() - 1; i >= A.size() - L; --i)
        {
            presum += A[i];
        }
        maxsum = presum;
        dp[A.size() - L][2] = maxsum;
        for (int i = A.size() - L - 1; i >= 0; --i)
        {
            presum -= A[i + L];
            presum += A[i];
            maxsum = max(maxsum, presum);
            dp[i][2] = maxsum;
        }

        presum = 0;
        for (int i = A.size() - 1; i >= A.size() - M; --i)
        {
            presum += A[i];
        }
        maxsum = presum;
        dp[A.size() - M][3] = maxsum;
        for (int i = A.size() - M - 1; i >= 0; --i)
        {
            presum -= A[i + M];
            presum += A[i];
            maxsum = max(maxsum, presum);
            dp[i][3] = maxsum;
        }

        //计算答案
        int res = 0;
        //L在M左边
        for (int i = L; i <= A.size() - M; ++i)
            res = max(res, dp[i - 1][0] + dp[i][3]);
        //M在L左边
        for (int i = M; i <= A.size() - L; ++i)
            res = max(res, dp[i - 1][1] + dp[i][2]);

        return res;
    }
};
// @lc code=end
