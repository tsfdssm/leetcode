/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
            m[nums[i]] = i;
        for (int i = 0; i < nums.size(); i++)
            if (m.find(target - nums[i]) != m.end() && m.find(target - nums[i])->second != i)
                return {i, m.find(target - nums[i])->second};
        return {};
    }
};
// @lc code=end
int main()
{
    int a = 0;
    for (int i = 0; i < 100; i++)
        a++;
    cout << a << endl;
    cout << "hello world";
    return 0;
}