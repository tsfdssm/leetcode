/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
struct DLinkedNode
{
    int key, val;
    DLinkedNode *prev;
    DLinkedNode *next;
    DLinkedNode() : key(0), val(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value) : key(_key), val(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache
{
public:
    unordered_map<int, DLinkedNode *> mp;

    int cap = 0;
    int size = 0;
    DLinkedNode *head, *tail;
    LRUCache(int capacity)
    {
        cap = capacity;
        size = 0;
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->next = head;
    }

    int get(int key)
    {
        if (0 == mp.count(key))
            return -1;
        DLinkedNode *node = mp[key];
        moveToHead(node);
        return node->val;
    }

    void put(int key, int value)
    {
        if (1 == mp.count(key))
        {
            mp[key]->val = value;
            moveToHead(mp[key]);
        }
        else
        {
            DLinkedNode *node = new DLinkedNode(key, value);
            addToHead(node);
            mp[key] = node;
            size++;
            if (size > cap)
            {
                DLinkedNode *removed = removeTail();
                mp.erase(removed->key);
                delete removed;
                size--;
            }
        }
    }
    void addToHead(DLinkedNode *node)
    {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    void removeNode(DLinkedNode *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        //delete node;
    }
    void moveToHead(DLinkedNode *node)
    {
        removeNode(node);
        addToHead(node);
    }
    DLinkedNode *removeTail()
    {
        DLinkedNode *removed = tail->prev;
        removeNode(tail->prev);
        return removed;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
