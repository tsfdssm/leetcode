/*
 * @lc app=leetcode.cn id=381 lang=cpp
 *
 * [381] O(1) 时间插入、删除和获取随机元素 - 允许重复
 */

// @lc code=start
class RandomizedCollection
{
public:
    unordered_multimap<int, int> st;
    vector<unordered_multimap<int, int>::iterator> vec;
    /** Initialize your data structure here. */
    RandomizedCollection()
    {
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val)
    {
        bool flag = st.find(val) == st.end();
        vec.push_back(st.insert({val, vec.size()}));
        return flag;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val)
    {
        if (st.find(val) == st.end())
            return false;
        auto it = st.find(val);
        int idx = it->second;
        vec.back()->second = idx;
        swap(vec.back(), vec[idx]);
        vec.pop_back();
        st.erase(it);
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom()
    {
        return vec[random() % (vec.size())]->first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
