/*
 * @lc app=leetcode.cn id=401 lang=cpp
 *
 * [401] 二进制手表
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<string> res;
    vector<int> vis;
    int visNum = 0;
    void backtrack(int i, int target)
    {
        if (visNum > target)
            return;
        if (10 == i)
        {
            if (visNum != target)
            {
                return;
            }
            int h = 0, m = 0;
            for (int j = 0; j < 4; ++j)
            {
                h += vis[j];
                h *= 2;
            }
            for (int j = 4; j < 10; ++j)
            {
                m += vis[j];
                m *= 2;
            }
            if (h > 12 || m > 60)
                return;
            string tmp = to_string(h) + ":" + to_string(m);
            res.emplace_back(tmp);
        }

        backtrack(i + 1, target);

        ++visNum;
        vis[i] = 1;
        backtrack(i + 1, target);
        vis[i] = 0;
        --visNum;
    }
    vector<string> readBinaryWatch(int n)
    {
        if (n < 0 || 10 < n)
            return {};
        if (0 == n)
            return {"0:00"};
        visNum = 0;
        vis.resize(10, 0);
        backtrack(0, n);
        return res;
    }
};
// @lc code=end
int main()
{
    Solution a;
    a.readBinaryWatch(1);
}