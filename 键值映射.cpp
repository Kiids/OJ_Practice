/*
设计一个 map ，满足以下几点:
字符串表示键，整数表示值
返回具有前缀等于给定字符串的键的值的总和
实现一个 MapSum 类：
MapSum() 初始化 MapSum 对象
void insert(String key, int val) 插入 key-val 键值对，字符串表示键 key ，整数表示值 val 。如果键 key 已经存在，那么原来的键值对?key-value?将被替代成新的键值对。
int sum(string prefix) 返回所有以该前缀 prefix 开头的键 key 的值的总和。
示例 1：
输入：
["MapSum", "insert", "sum", "insert", "sum"]
[[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
输出：
[null, null, 3, null, 5]
解释：
MapSum mapSum = new MapSum();
mapSum.insert("apple", 3);  
mapSum.sum("ap");           // 返回 3 (apple = 3)
mapSum.insert("app", 2);    
mapSum.sum("ap");           // 返回 5 (apple + app = 3 + 2 = 5)
提示：
1 <= key.length, prefix.length <= 50
key 和 prefix 仅由小写英文字母组成
1 <= val <= 1000
最多调用 50 次 insert 和 sum
*/

class MapSum {
    map<string, int> m;
public:
    MapSum() {
        m.clear();
    }
    
    void insert(string key, int val) {
        m[key] = val;
    }
    
    int sum(string prefix) {
        auto r = m.insert({prefix, 0});
        auto b = r.first;  // b为第一个匹配的key对应的迭代器
        if (r.second)      // 若以前没有（成功插入）则b后移
        {
            b++;
            m.erase(prefix);
        }
        (*(prefix.end() - 1)) ++;
        r = m.insert({prefix, 0});
        auto e = r.first;  // e为最后一个匹配的key对应的迭代器加一
        if (r.second)      // 若以前没有（成功插入）则e后移
        {
            e++;
            m.erase(prefix);
        }
        int ret = 0;
        while (b != e)     // 累加b到e-1
        {
            ret += b->second;
            b++;
        }
        return ret;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
 

//存储和插入，直接插入map，空间复杂度空间复杂度O(M)，insert时间复杂度O(logM)，M为要存储的键值对个数。
//求sum，因为map有序，需要累加的key在map中连续，只需要确定符合条件的key在map中的起始位置和结束位置，之后累加。
//起始位置，插入一个prefix键值，如果插入失败，表示map原本就有prefix,map::insert函数返回的迭代器即为起始位置，
//如果插入成功，表示map原本不存在prefix，map::insert函数返回的迭代器加上1即为起始位置。
//结束位置，需要先将prefix字符串的最后一个字符加一（例如原本为"abc", 加一后变为"abd"）,再插入map中，
//位置在最后一个符合条件的key后面，减1就确定最后一个符合条件key的位置。
//sum函数的时间复杂度为O(logM + C), M为要存储的键值对个数，C为匹配到的key值个数。

