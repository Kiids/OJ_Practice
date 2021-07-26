/*
����һ���ַ������飬����ĸ��λ�������һ�𡣿��԰�����˳�򷵻ؽ���б�
��ĸ��λ��ָ��ĸ��ͬ�������в�ͬ���ַ�����
ʾ�� 1:
����: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
���: [["bat"],["nat","tan"],["ate","eat","tea"]]
ʾ�� 2:
����: strs = [""]
���: [[""]]
ʾ�� 3:
����: strs = ["a"]
���: [["a"]]
��ʾ��
1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] ������Сд��ĸ
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m; 
        for (string &s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            m[key].push_back(s);
        }
        vector<vector<string>> v;
        for (auto i = m.begin(); i != m.end(); i++)
            v.push_back(i->second);
        return v;
    }
};
