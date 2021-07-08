/*
 * @lc app=leetcode.cn id=715 lang=cpp
 *
 * [715] Range 模块
 */

// @lc code=start
class RangeModule
{
public:
    map<int, int> mp;
    RangeModule()
    {
        mp.clear();
    }

    void addRange(int left, int right)
    {
        auto l = mp.lower_bound(left);
        auto r = mp.upper_bound(right);
        if (l != mp.end() && l->second < left)
            left = l->second;
        if (r != mp.end() && r->second <= right)
            right = r->first;
        for (auto it = mp.begin(); it != mp.end();)
        {
            if (it->first <= right && it->second >= left)
                it = mp.erase(it);
            else
                ++it;
            if (it->second > right)
                break;
        }
        mp[right] = left;
    }

    bool queryRange(int left, int right)
    {
        auto r = mp.lower_bound(right);
        if (r != mp.end() && r->second <= left)
            return true;
        return false;
    }

    void removeRange(int left, int right)
    {
        auto a = mp.upper_bound(left);
        auto b = mp.lower_bound(right);
        if (a == mp.end() || right <= mp.begin()->second)
            return;
        else
        {
            int x = (*a).second;
            auto p = a;
            while (p != b)
            {
                ++a;
                mp.erase(p);
                p = a;
            }
            if (b != mp.end())
            {
                int y = (*b).first;
                if ((*b).second < right)
                {
                    mp.erase(b);
                    if (right < y)
                        mp[y] = right;
                }
            }
            if (x < left)
                mp[left] = x;
        }
        // auto r = mp.upper_bound(right);
        // if (r != mp.end() && r->second < left)
        // {
        //     int tmpl = r->second;
        //     r->second = right;
        //     mp[left] = tmpl;
        //     return;
        // }
        // for (auto it = mp.begin(); it != mp.end();)
        // {
        //     if (it->first <= right && it->second >= left)
        //         it = mp.erase(it);
        //     else
        //         ++it;
        //     if (it->second > right)
        //         break;
        // }
        // r = mp.upper_bound(right);
        // r->second = max(right, r->second);
        // auto l = mp.upper_bound(left);
        // if (l->first < right)
        // {
        //     mp[left] = l->second;
        //     mp.erase(l);
        // }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
// @lc code=end
