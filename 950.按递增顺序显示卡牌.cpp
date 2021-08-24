/*
 * @lc app=leetcode.cn id=950 lang=cpp
 *
 * [950] 按递增顺序显示卡牌
 */

// @lc code=start
class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        deque<int> q;
        int n = deck.size();
        sort(deck.begin(), deck.end());
        for (int r = n - 1; r >= 0; --r)
        {
            if (q.size() > 1)
            {
                auto nxt = q.back();
                q.pop_back();
                q.push_front(nxt);
            }
            q.push_front(deck[r]);
        }
        for (int i = 0; i < n; ++i)
        {
            deck[i] = q.front();
            q.pop_front();
        }
        return deck;
    }
};
// @lc code=end
