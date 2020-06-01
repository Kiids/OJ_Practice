/*
��дһ�ַ��������ַ�������������򣬽����б�λ�������һ�𡣱�λ����ָ��ĸ��ͬ�������в�ͬ���ַ�����
ע�⣺�������ԭ�������޸�
ʾ��:
����: ["eat", "tea", "tan", "ate", "nat", "bat"],
���:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
˵����
���������ΪСд��ĸ��
�����Ǵ������˳��
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, vector<int>> m;
        for (int i = 0; i < strs.size(); i++)
        {
            string t = strs[i];
            sort(t.begin(), t.end());
            m[t].push_back(i);
        }
        for (auto e : m)
        {
            vector<string> v;
            auto i = e.second;
            for (auto index : i)
                v.push_back(strs[index]);
            ret.push_back(v);
        }
        return ret;
    }
};
