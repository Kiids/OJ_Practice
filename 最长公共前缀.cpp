/*
��дһ�������������ַ��������е������ǰ׺��
��������ڹ���ǰ׺�����ؿ��ַ��� ""��
ʾ�� 1��
���룺strs = ["flower","flow","flight"]
�����"fl"
ʾ�� 2��
���룺strs = ["dog","racecar","car"]
�����""
���ͣ����벻���ڹ���ǰ׺��
��ʾ��
0 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] ����СдӢ����ĸ���
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret = strs.empty() ? "" : strs[0]; 
        for (string s : strs) 
            while (s.find(ret) != 0)
                ret = ret.substr(0, ret.length() - 1);
        return ret;
    }
};
