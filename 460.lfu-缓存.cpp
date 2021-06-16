/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */

// @lc code=start
struct Node
{
    int key, val, freq;
    Node(int _key, int _val, int _freq) : key(_key), val(_val), freq(_freq) {}
};
class LFUCache
{
    int minfreq;
    int capacity;
    unordered_map<int, list<Node>::iterator> key_table;
    unordered_map<int, list<Node>> freq_table;

public:
    LFUCache(int _capacity)
    {
        minfreq = 0;
        capacity = _capacity;
    }

    int get(int key)
    {
        if (capacity <= 0)
            return -1;
        auto it = key_table.find(key);
        if (it == key_table.end())
            return -1;
        list<Node>::iterator node = it->second;
        int val = node->val, freq = node->freq;
        freq_table[freq].erase(node);
        if (0 == freq_table[freq].size())
        {
            freq_table.erase(freq);
            if (minfreq == freq)
                minfreq++;
        }
        freq_table[freq + 1].push_front(Node(key, val, freq + 1));
        key_table[key] = freq_table[freq + 1].begin();
        return val;
    }

    void put(int key, int value)
    {
        if (capacity <= 0)
            return;
        auto it = key_table.find(key);
        if (it == key_table.end())
        {

            if (key_table.size() == capacity)
            {
                auto it2 = freq_table[minfreq].back();
                key_table.erase(it2.key);
                freq_table[minfreq].pop_back();
                if (0 == freq_table[minfreq].size() && minfreq != 1)
                    freq_table.erase(minfreq);
            }
            freq_table[1].push_front(Node(key, value, 1));
            key_table[key] = freq_table[1].begin();
            minfreq = 1;
        }
        else
        {
            list<Node>::iterator node = it->second;
            int freq = node->freq;
            freq_table[freq].erase(node);
            if (0 == freq_table[freq].size())
            {
                freq_table.erase(freq);
                if (minfreq == freq)
                    ++minfreq;
            }
            freq_table[freq + 1].push_front(Node(key, value, freq + 1));
            key_table[key] = freq_table[freq + 1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
