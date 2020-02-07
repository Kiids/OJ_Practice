/*
����һ������� (ransom) �ַ�����һ����־(magazine)�ַ������жϵ�һ���ַ���ransom�ܲ����ɵڶ����ַ���magazines������ַ����ɡ�������Թ��ɣ����� true �����򷵻� false�� 
(��Ŀ˵����Ϊ�˲���¶������ּ���Ҫ����־������������Ҫ����ĸ����ɵ����������˼��)
ע�⣺
����Լ��������ַ�����ֻ����Сд��ĸ��
canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> map1, map2;
        int i;
        for (i = 0; i < magazine.size(); i++)
            map1[magazine[i]]++;
        for (i = 0; i < ransomNote.size(); i++)
            map2[ransomNote[i]]++;
        map<char,int>::iterator it;
        for (it = map2.begin(); it != map2.end(); it++)
            if (it->second > map1[it->first])
                return false;
        return true;
    }
};
