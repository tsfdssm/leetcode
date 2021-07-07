/*
 * @lc app=leetcode.cn id=690 lang=cpp
 *
 * [690] 员工的重要性
 */

// @lc code=start
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution
{
public:
    unordered_map<int, Employee *> mp;
    int getImportance(const vector<Employee *> &emp, int id)
    {
        for (const auto &e : emp)
        {
            int i = e->id;
            mp[i] = e;
        }
        return dfs(id);
    }

    int dfs(int id)
    {
        if (!mp.count(id))
            return 0;
        auto &e = mp[id];
        int res = e->importance;
        for (const auto &i : e->subordinates)
        {
            res += dfs(i);
        }
        return res;
    }
};
// @lc code=end
