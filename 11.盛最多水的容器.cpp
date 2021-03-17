/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        auto i = 0;
        auto j = height.size() - 1;
        int maxx = 0;
        while (i < j)
        {
            int tmp = (j - i) * min(height[i], height[j]);
            maxx = max(maxx, tmp);
            if (height[i] > height[j])
            {
                int r = height[j];
                while (i < j && r >= height[j])
                    j--;
            }
            else
            {
                int l = height[i];
                while (i < j && l >= height[i])
                    i++;
            }
        }
        return maxx;
    }
};
// @lc code=end

int main()
{
    vector<int> a = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution b;
    int x = b.maxArea(a);
    cout << x;
    getchar();
    return 0;
}