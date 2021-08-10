/*
 * @lc app=leetcode.cn id=881 lang=cpp
 *
 * [881] 救生艇
 */

// @lc code=start
class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        int n = people.size();
        int l = 0, r = n - 1;
        sort(people.begin(), people.end());
        while (r >= 0 && people[r] == limit)
            --r;
        int res = n - r - 1;
        while (l <= r)
        {
            int tmp = people[r];
            if (l < r && tmp + people[l] <= limit)
                tmp += people[l++];
            --r;
            ++res;
        }
        return res;
    }
};
// @lc code=end
