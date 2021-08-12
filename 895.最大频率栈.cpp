/*
 * @lc app=leetcode.cn id=895 lang=cpp
 *
 * [895] 最大频率栈
 */

// @lc code=start
class FreqStack
{
public:
    // list<int> stk;
    // map<int, vector<list<int>::iterator>> mp;

    map<int, int> freq;
    map<int, stack<int>> group;
    int maxf = 0;
    FreqStack()
    {
    }

    void push(int x)
    {
        freq[x]++;
        if (freq[x] > maxf)
            maxf = freq[x];
        group[freq[x]].push(x);
        // stk.push_back(val);
        // mp[val].emplace_back(prev(stk.end()));
    }

    int pop()
    {
        int x = group[maxf].top();

        group[maxf].pop();
        freq[x]--;
        if (group[maxf].size() == 0)
            maxf--;
        return x;
        // int res = -1;
        // int maxn = 0;
        // int len = 0;

        // //res = mp.rbegin()->first;
        // for (auto it = mp.begin(); it != mp.end(); ++it)
        // {
        //     if (it->second.size() < maxn)
        //         continue;
        //     int tmpLen = distance(stk.begin(), it->second.back());
        //     if (it->second.size() > maxn)
        //     {
        //         maxn = it->second.size();
        //         res = it->first;
        //         len = tmpLen;
        //     }
        //     else
        //     {
        //         if (tmpLen > len)
        //         {
        //             res = it->first;
        //             len = tmpLen;
        //         }
        //     }
        // }
        // auto iter = mp[res].back();
        // int tmp = *iter;
        // stk.erase(iter);
        // mp[res].pop_back();
        // if (0 == mp[res].size())
        //     mp.erase(res);
        // return tmp;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end
