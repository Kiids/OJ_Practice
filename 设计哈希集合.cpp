/*
不使用任何内建的哈希表库设计一个哈希集合
具体地说，你的设计应该包含以下的功能
add(value)：向哈希集合中插入一个值。
contains(value) ：返回哈希集合中是否存在这个值。
remove(value)：将给定值从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。
示例:
MyHashSet hashSet = new MyHashSet();
hashSet.add(1);         
hashSet.add(2);         
hashSet.contains(1);    // 返回 true
hashSet.contains(3);    // 返回 false (未找到)
hashSet.add(2);          
hashSet.contains(2);    // 返回 true
hashSet.remove(2);          
hashSet.contains(2);    // 返回  false (已经被删除)
注意：
所有的值都在 [0, 1000000]的范围内。
操作的总数目在[1, 10000]范围内。
不要使用内建的哈希集合库。
*/

class MyHashSet {
    vector<unsigned> v;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        v = vector<unsigned >(1000000 / 32,0);
    }
    
    void add(int key) {
        v[key / 31] |= 1 << (key % 31);
    }
    
    void remove(int key) {
        v[key / 31] &= ~(1 << (key % 31));
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return  v[key / 31] & (1 << (key % 31));
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

// 用位表示，位的逻辑值为1则表示hash表中存在。
// 一个无符号的整数可以表示hash 表中的 32 个数，这里可以理解为 1000000/32 个桶，但是每个桶为32 个数。
// 判断key的值 是否存在就去 桶为 k/32 的 k%32 位。 k/32 等价于 k>>5(左移） k%32 等价于 k&31.（逻辑与)
// 把某一位 搞成0 就->&0，把某一位 搞成1 就->|1,看某一位是啥就->& 。
