/*
���������ַ��� s �� t ����дһ���������ж� t �Ƿ��� s ����ĸ��λ�ʡ�
ʾ�� 1:
����: s = "anagram", t = "nagaram"
���: true
ʾ�� 2:
����: s = "rat", t = "car"
���: false
˵��:
����Լ����ַ���ֻ����Сд��ĸ��
����:
��������ַ������� unicode �ַ���ô�죿���ܷ������Ľⷨ��Ӧ�����������
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int hash[26] = {0};
        for(char c : s) hash[c - 'a'] ++;
        for(char c : t) 
            if(-- hash[c - 'a'] == -1) return false;
        return true;

    }
};
