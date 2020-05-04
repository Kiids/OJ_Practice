/*
实现一个算法，确定一个字符串 s 的所有字符是否全都不同。
示例 1：
输入: s = "leetcode"
输出: false 
示例 2：
输入: s = "abc"
输出: true
限制：
0 <= len(s) <= 100
如果你不使用额外的数据结构，会很加分。
*/

// 利用标记数组 
class Solution {
public:
    bool isUnique(string astr) {
        vector<int> v(26, 0);
        for (int i = 0; i < astr.size(); i++)
        {
            if (v[astr[i] - 'a'])
                return false;
            v[astr[i] - 'a']++;
        }
        return true;
    }
};

// 暴力排序后遍历判断
class Solution {
public:
    bool isUnique(string astr) {
        sort(astr.begin(),astr.end());
        for (int i=1;i<astr.size();i++) {
            if (astr[i]==astr[i-1]) {
                return 0;
            }
        }
        return 1;
    }
};

// unordered_map哈希表 
class Solution {
public:
    bool isUnique(string astr) {
        unordered_map<char,int> r;
        for(char s:astr)
        {
            r[s]++;
            if(r[s] >= 2){
                return false;
            }
        }
        return true;
    }
};

// 位运算
// 不用额外数据结构 因此使用位运算方法
// int32位可以覆盖26个字母表的长度，可用。
// 无需额外内存 
class Solution {
public:
    bool isUnique(string astr) {
        char start = 'a';
        int memo = 0x0;
        bool isUnique = true;
        for (auto cr : astr) {
            unsigned int pos = cr - start;
            if ((memo & (0x01 << pos)) == 0) {
                memo = (0x01 << pos) | memo;
            } else {
                isUnique = false;
                break;
            }
        }
        return isUnique;
    }
};

作者：tuo-yang-he-tang-he-gan-suan-3
链接：https://leetcode-cn.com/problems/is-unique-lcci/solution/jian-dan-wei-yun-suan-memo-by-tuo-yang-he-tang-he-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
