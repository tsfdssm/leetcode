/*
 * @lc app=leetcode.cn id=480 lang=cpp
 *
 * [480] 滑动窗口中位数
 */

// @lc code=start
class Solution
{
public:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> big;
    unordered_map<int, int> mp;

    double get(int k)
    {
        if (k & 1)
            return small.top();
        return ((double)small.top() + big.top()) / 2;
    }
    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        for (int i = 0; i < k; ++i)
            small.push(nums[i]);
        for (int i = 0; i < k / 2; ++i)
        {
            big.push(small.top());
            small.pop();
        }
        int n = nums.size();
        vector<double> res{get(k)};
        for (int i = k; i < n; ++i)
        {
            int balance = 0;
            int l = nums[i - k];
            mp[l]++;
            if (!small.empty() && l <= small.top())
                balance--;
            else
                balance++;

            if (!small.empty() && nums[i] < small.top())
            {
                small.push(nums[i]);
                balance++;
            }
            else
            {
                big.push(nums[i]);
                balance--;
            }

            if (balance > 0)
            {
                big.push(small.top());
                small.pop();
            }
            else if (balance < 0)
            {
                small.push(big.top());
                big.pop();
            }
            while (!small.empty() && mp[small.top()] > 0)
            {
                mp[small.top()]--;
                small.pop();
            }
            while (!big.empty() && mp[big.top()] > 0)
            {
                mp[big.top()]--;
                big.pop();
            }
            res.push_back(get(k));
        }
        return res;
        /*1111111*/
        // const auto func = [=](multiset<int> &mset) -> double {
        //     auto it = mset.begin();
        //     for (int i = 0; i < k / 2; ++i)
        //         ++it;
        //     if (k & 1)
        //         return *it;
        //     else
        //     {
        //         auto curr = *it;
        //         auto prev = *(--it);
        //         return prev / 2.0 + curr / 2.0;
        //     }
        // };
        // vector<double> ans;
        // multiset<int> mset(nums.begin(), nums.begin() + k);
        // ans.push_back(func(mset));
        // for (int i = k; i < nums.size(); ++i)
        // {
        //     mset.erase(mset.find(nums.at(i - k)));
        //     mset.insert(nums.at(i));
        //     ans.push_back(func(mset));
        // }
        // return ans;

        /*2222222222222222*/
        // int n = nums.size();
        // int l = 0, r = k;
        // multiset<int> st(nums.begin(), nums.begin() + k);
        // vector<double> res(n - k + 1, 0);
        // res[0] = get(st);
        // while (r < n)
        // {
        //     st.erase(st.find(nums[l]));
        //     st.insert(nums[r]);
        //     ++l;
        //     ++r;
        //     res[l] = get(st);
        // }
        // return res;
    }

    // double get(multiset<int> &st)
    // {
    //     int k = st.size();

    //     auto it = st.begin();
    //     advance(it, k / 2);
    //     double res = *it;
    //     if (k % 2 == 0)
    //     {
    //         res += *prev(it, 1);
    //         res /= 2;
    //     }
    //     return res;
    // }
};
// @lc code=end
