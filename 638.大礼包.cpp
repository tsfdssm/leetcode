/*
 * @lc app=leetcode.cn id=638 lang=cpp
 *
 * [638] 大礼包
 */

// @lc code=start
class Solution
{
public:
    map<vector<int>, int> memo;
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
    {
        int n = price.size();
        int res = inner_product(price.begin(), price.end(), needs.begin(), 0);
        if (memo.count(needs))
            return memo[needs];

        for (const auto &offer : special)
        {
            auto rem = helper(offer, needs);
            if (rem.empty())
                continue;
            res = min(res, offer.back() + shoppingOffers(price, special, rem));
        }
        memo[needs] = res;
        return res;
    }
    vector<int> helper(const vector<int> &offer, const vector<int> needs)
    {
        vector<int> remainder(needs.size(), 0);
        for (int i = 0; i < needs.size(); ++i)
        {
            if (needs[i] < offer[i])
                return {};
            remainder[i] = needs[i] - offer[i];
        }
        return remainder;
    }
};
// @lc code=end
