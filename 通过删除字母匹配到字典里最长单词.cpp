/*
����һ���ַ��� s ��һ���ַ������� dictionary ���ҳ�������?dictionary ������ַ��������ַ�������ͨ��ɾ�� s �е�ĳЩ�ַ��õ���
����𰸲�ֹһ�������س��������ĸ����С���ַ���������𰸲����ڣ��򷵻ؿ��ַ�����
ʾ�� 1��
���룺s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
�����"apple"
ʾ�� 2��
���룺s = "abpcplea", dictionary = ["a","b","c"]
�����"a"
��ʾ��
1 <= s.length <= 1000
1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 1000
s �� dictionary[i] ����СдӢ����ĸ���
*/

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ret;
        for (string d : dictionary)
        {
            int j = 0;
            for (int i = 0; i < s.size() && j < d.size(); i++)
                if (d[j] == s[i])
                    j++;
                    
            if (j == d.size())
            {
                if (d.size() > ret.size())
                    ret = d;
                else if (d.size() == ret.size())
                    ret = d < ret ? d : ret;
            }
        }
        return ret;
    }
};
