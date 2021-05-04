/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        int i = 0, j = 0;
        int n1 = version1.size();
        int n2 = version2.size();
        while (i < n1 || j < n2)
        {
            int num1 = 0, num2 = 0;
            if (i < n1)
            {
                int tmpi = i + 1;
                while (tmpi < n1 && version1[tmpi] != '.')
                    tmpi++;
                num1 = atoi(version1.substr(i, tmpi - i).c_str());
                i = tmpi + 1;
            }
            if (j < n2)
            {
                int tmpj = j + 1;
                while (tmpj < n2 && version2[tmpj] != '.')
                    tmpj++;
                num2 = atoi(version2.substr(j, tmpj - j).c_str());
                j = tmpj + 1;
            }

            if (num1 > num2)
                return 1;
            if (num2 > num1)
                return -1;
        }
        return 0;
    }
};
// @lc code=end
