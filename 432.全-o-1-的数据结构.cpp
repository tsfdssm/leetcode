/*
 * @lc app=leetcode.cn id=432 lang=cpp
 *
 * [432] 全 O(1) 的数据结构
 */

// @lc code=start

struct LinkedList
{
    LinkedList *prev;
    LinkedList *next;
    int val;
    string key;
    LinkedList(int _val) : val(_val), prev(nullptr), next(nullptr) {}
};
class AllOne
{
public:
    unordered_map<string, LinkedList *> mp;
    LinkedList *head; //big
    LinkedList *tail; //small
    /** Initialize your data structure here. */
    AllOne()
    {
        head = new LinkedList(INT_MAX);
        tail = new LinkedList(INT_MIN);
        head->next = tail;
        tail->prev = head;
    }
    ~AllOne()
    {
        LinkedList *tmp;
        while (nullptr != head)
        {
            tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key)
    {
        auto it = mp.find(key);
        if (it == mp.end()) //不存在
        {
            LinkedList *p = new LinkedList(1);
            mp[key] = p;
            p->key = key;

            p->prev = tail->prev;
            p->next = tail;

            p->prev->next = p;
            tail->prev = p;
        }
        else
        {
            auto p = it->second;
            p->val++;
            LinkedList *tmp = p->prev;
            if (tmp->val >= p->val)
                return;
            while (tmp->val < p->val)
            {
                tmp = tmp->prev;
            }
            p->next->prev = p->prev;
            p->prev->next = p->next;

            p->prev = tmp;
            p->next = tmp->next;

            tmp->next->prev = p;
            tmp->next = p;
        }
        return;
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key)
    {
        auto it = mp.find(key);
        if (it == mp.end()) //不存在
            return;
        auto p = it->second;

        if (1 == p->val)
        {
            mp.erase(it);
            p->next->prev = p->prev;
            p->prev->next = p->next;
            delete p;
            return;
        }
        p->val--;
        LinkedList *tmp = p->next;
        if (tmp->val <= p->val)
            return;
        while (tmp->val > p->val)
        {
            tmp = tmp->next;
        }
        p->next->prev = p->prev;
        p->prev->next = p->next;

        p->next = tmp;
        p->prev = tmp->prev;

        tmp->prev->next = p;
        tmp->prev = p;
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey()
    {
        if (0 == mp.size())
            return "";
        return head->next->key;
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey()
    {
        if (0 == mp.size())
            return "";
        return tail->prev->key;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end
