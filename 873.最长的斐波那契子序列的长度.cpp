/*
 * @lc app=leetcode.cn id=873 lang=cpp
 *
 * [873] 最长的斐波那契子序列的长度
 */

// @lc code=start
class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, int> index;
        for (int i = 0; i < n; ++i)
            index[arr[i]] = i;
        unordered_map<int, int> longest;
        int res = 0;
        for (int k = 0; k < n; ++k)
            for (int j = 0; j < k; ++j)
            {
                if (arr[k] - arr[j] < arr[j] && index.count(arr[k] - arr[j]))
                {
                    int i = index[arr[k] - arr[j]];
                    longest[j * n + k] = longest[i * n + j] + 1;
                    res = max(res, longest[j * n + k] + 2);
                }
            }
        return res > 2 ? res : 0;

        // int n = arr.size();
        // int res = 0;
        // unordered_set<int> st(arr.begin(), arr.end());
        // for (int i = 0; i < n - 1; ++i)
        //     for (int j = i + 1; j < n; ++j)
        //     {
        //         int prepre = arr[i];
        //         int pre = arr[j];
        //         int len = 2;
        //         while (st.count(prepre + pre))
        //         {
        //             int tmp = prepre + pre;
        //             prepre = pre;
        //             pre = tmp;
        //             ++len;
        //         }
        //         res = max(res, len);
        //     }
        // return res == 2 ? 0 : res;

        // int n = arr.size();
        // priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q; //(need,last,length)
        // for (int i = 0; i < n - 2; ++i)
        //     for (int j = i + 1; j < n - 1; ++j)
        //     {
        //         int prepre = arr[i];
        //         int pre = arr[j];
        //         q.push({arr[i] + arr[j], arr[j], 2});
        //     }
        // int res = 0;
        // for (int i = 2; i < n; ++i)
        // {
        //     while (!q.empty() && get<0>(q.top()) < arr[i])
        //         q.pop();
        //     while (!q.empty() && get<0>(q.top()) == arr[i])
        //     {
        //         auto [need, last, length] = q.top();
        //         q.pop();
        //         q.push({last + need, need, length + 1});
        //         res = max(res, length + 1);
        //     }
        // }
        // return res;
    }
};
// @lc code=end
