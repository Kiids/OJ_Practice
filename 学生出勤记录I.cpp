/*
����һ���ַ���������һ��ѧ���ĳ��ڼ�¼�������¼���������������ַ���
'A' : Absent��ȱ��
'L' : Late���ٵ�
'P' : Present������
���һ��ѧ���ĳ��ڼ�¼�в�����һ��'A'(ȱ��)���Ҳ���������������'L'(�ٵ�),��ô���ѧ���ᱻ���͡�
����Ҫ�������ѧ���ĳ��ڼ�¼�ж����Ƿ�ᱻ���͡�
ʾ�� 1:
����: "PPALLP"
���: True
ʾ�� 2:
����: "PPALLL"
���: False
*/

class Solution {
public:
    bool checkRecord(string s) {
        int l = 0, a = 0;
        for (auto e : s)
        {
            if (e == 'A')
            {
                a++;
                l = 0;
            }
            else if (e == 'L')
                l++;
            else
                l = 0;
            if (l > 2 || a > 1)
                return false;
        }
        return true;
    }
};

class Solution {
public:
    bool checkRecord(string s) {
        return s.find('A', s.find('A') + 1) == -1 && s.find("LLL") == -1;
    }
};
