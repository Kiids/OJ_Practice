/*
���������ַ��� s �� t���ж������Ƿ���ͬ���ġ�
��� s �е��ַ����Ա��滻�õ� t ����ô�������ַ�����ͬ���ġ�
���г��ֵ��ַ�����������һ���ַ��滻��ͬʱ�����ַ���˳�������ַ�����ӳ�䵽ͬһ���ַ��ϣ����ַ�����ӳ���Լ�����
ʾ�� 1:
����: s = "egg", t = "add"
���: true
ʾ�� 2:
����: s = "foo", t = "bar"
���: false
ʾ�� 3:
����: s = "paper", t = "title"
���: true
˵��:
����Լ��� s �� t ������ͬ�ĳ��ȡ�
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() == 0 && t.size() == 0)
            return true;

        for (int i = 0; i < s.size(); i++)
            if (s.find(s[i]) != t.find(t[i]))
                return false;

        return true;
    }
};
