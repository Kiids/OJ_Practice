/*
ͳ���ַ����еĵ��ʸ���������ĵ���ָ���������Ĳ��ǿո���ַ���
��ע�⣬����Լٶ��ַ����ﲻ�����κβ��ɴ�ӡ���ַ���
ʾ��:
����: "Hello, my name is John"
���: 5
����: ����ĵ�����ָ�����Ĳ��ǿո���ַ������� "Hello," ���� 1 �����ʡ�
*/

class Solution {
public:
    int countSegments(string s) {
        int len = s.size();
        int cnt = 0;
        if (len == 0)
            return 0;
        for (int i = 1; i < len; i++)
            if (s[i] == ' ' && s[i - 1] != ' ')
                cnt++;
        if (s[len - 1] != ' ')
            cnt++;
        return cnt;
    }
};
