/*
 * @lc app=leetcode.cn id=705 lang=cpp
 *
 * [705] 设计哈希集合
 */

// @lc code=start
class MyHashSet
{
public:
    const int l = 1e6 + 5;
    vector<bool> vec;
    /** Initialize your data structure here. */
    MyHashSet()
    {
        vec.resize(l, false);
    }

    void add(int key)
    {
        vec[key % l] = true;
    }

    void remove(int key)
    {
        vec[key % l] = false;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        return vec[key % l];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end
