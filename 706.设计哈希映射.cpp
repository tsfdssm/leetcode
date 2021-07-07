/*
 * @lc app=leetcode.cn id=706 lang=cpp
 *
 * [706] 设计哈希映射
 */

// @lc code=start
class MyHashMap
{
public:
    vector<list<pair<int, int>>> all;
    /** Initialize your data structure here. */
    constexpr static int mod = 769;
    inline int hash(int key)
    {
        return key % mod;
    }
    MyHashMap()
    {
        all.resize(mod);
    }

    /** value will always be non-negative. */
    void put(int key, int value)
    {
        int idx = hash(key);
        for (auto it = all[idx].begin(); it != all[idx].end(); ++it)
        {
            if (it->first == key)
            {
                it->second = value;
                return;
            }
        }
        all[idx].push_back({key, value});
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        int idx = hash(key);
        for (auto it = all[idx].begin(); it != all[idx].end(); ++it)
        {
            if (it->first == key)
                return it->second;
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        int idx = hash(key);
        for (auto it = all[idx].begin(); it != all[idx].end(); ++it)
        {
            if (it->first == key)
            {
                it = all[idx].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end
