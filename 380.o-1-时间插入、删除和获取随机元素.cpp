/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

// @lc code=start
class RandomizedSet
{
public:
    /** Initialize your data structure here. */
    unordered_map<int, int> st;
    vector<int> vec;
    RandomizedSet()
    {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (st.count(val))
            return false;
        st[val] = vec.size();
        vec.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (!st.count(val))
            return false;
        if (st[val] != vec.size() - 1)
        {
            int pos = st[val];
            vec[pos] = vec.back();
            st[vec[pos]] = pos;
        }
        vec.pop_back();
        st.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        if (vec.empty())
            return -1;
        return vec[random() % (vec.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
