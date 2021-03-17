/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution
{
public:
	bool isMatch(string s, string p)
	{
		if (p.size() > 0 && p[0] == '*')
			return false;
		int line = p.size() + 1;
		int col = s.size() + 1;
		vector<vector<bool>> dp(line, vector<bool>(col));

		for (int i = 0; i < col; i++)
			dp[0][i] = false;
		for (int i = 0; i < line; i++)
		{
			if (0 == i)
				dp[i][0] = true;
			else if (p[i - 1] != '*')
				dp[i][0] = false;
			else
				dp[i][0] = dp[i - 2][0];
		}
		for (int j = 1; j < col; j++)
		{
			for (int i = 1; i < line; i++)
			{
				/*s[j-1],p[i-1]*/
				if (p[i - 1] == '*')
				{
					if (p[i - 2] == '.' || p[i - 2] == s[j - 1])
						dp[i][j] = dp[i][j - 1] || dp[i - 1][j] || dp[i - 2][j];
					else
						dp[i][j] = dp[i - 2][j];
				}
				else if (p[i - 1] == '.' || p[i - 1] == s[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1];
				}
				else
				{
					dp[i][j] = false;
				}
			}
		}
		return dp[line - 1][col - 1];
	}
};
// @lc code=end
