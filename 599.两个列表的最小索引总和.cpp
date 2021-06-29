/*
 * @lc app=leetcode.cn id=599 lang=cpp
 *
 * [599] 两个列表的最小索引总和
 */

// @lc code=start
class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        int m = INT_MAX;
        set<string> st;
        map<string, int> mp;
        for (int i = 0; i < list2.size(); ++i)
            mp[list2[i]] = i;
        for (int i = 0; i < list1.size(); ++i)
        {
            if (!mp.count(list1[i]))
                continue;
            int idx = i + mp[list1[i]];
            if (idx > m)
            {
                continue;
            }
            else if (idx == m)
            {
                st.insert(list1[i]);
            }
            else
            {
                m = idx;
                st.clear();
                st = {list1[i]};
            }
        }
        return vector<string>(st.begin(), st.end());
    }
};
// @lc code=end
