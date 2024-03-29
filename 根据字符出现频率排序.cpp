/*
给定一个字符串，请将字符串里的字符按照出现的频率降序排列。
示例 1:
输入:
"tree"
输出:
"eert"
解释:
'e'出现两次，'r'和't'都只出现一次。
因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
示例 2:
输入:
"cccaaa"
输出:
"cccaaa"
解释:
'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
注意"cacaca"是不正确的，因为相同的字母必须放在一起。
示例 3:
输入:
"Aabb"
输出:
"bbAa"
解释:
此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
注意'A'和'a'被认为是两种不同的字符。
*/

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;  // 字符 - 出现次数 
        string ret = "";
        for (auto& c : s)
            m[c]++;
        while (!m.empty())
        {
            auto pos = m.begin();
            for (auto i = m.begin(); i != m.end(); i++)  // 每次找次数最高的那个 
                if (i->second > pos->second)
                    pos = i;
            ret.insert(ret.size(), pos->second, pos->first);
            m.erase(pos);
        }
        return ret;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (const auto& c : s)
            mp[c]++;
        priority_queue<pair<int, char>> pq;  // 优先队列 
        for (const auto &m : mp)
            pq.push({m.second, m.first});
            
        string ret;
        while (!pq.empty())
        {
            auto t = pq.top(); 
            pq.pop();
            ret.append(t.first, t.second);
        }
        return ret;
    }
};
 
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for (const auto& c : s)
            m[c]++;
        // lambda自定义排序 
        sort(s.begin(), s.end(), [&](char &a, char &b) { return m[a] > m[b] || (m[a] == m[b] && a < b); });
        return s;
    }
};
