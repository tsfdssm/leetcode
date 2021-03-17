/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */
#include <vector>
#include <string>

using namespace std;
// @lc code=start
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        int res = -1;
        for (int i = 0; i < n; ++i)
        {
            if (gas[i] < cost[i])
                continue;
            bool tmpok = true;
            int left_gas = gas[i] - cost[i];
            int tmp = i + 1;
            while ((tmp % n) < i)
            {
                tmp = tmp % n;
                left_gas = left_gas + gas[tmp] - cost[tmp];
                if (left_gas < 0)
                {
                    tmpok = false;
                    break;
                }
                tmp++;
            }
            if (tmpok = true)
            {
                res = i;
                break;
            }
        }
        return res;
    }
};
// @lc code=end

int main()
{
    vector<int> a{2, 3, 4};
    vector<int> b{3, 4, 3};
    Solution as;
    int res = as.canCompleteCircuit(a, b);
    return 0;
}