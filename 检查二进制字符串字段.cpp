/*
����һ���������ַ��� s �����ַ��� ����ǰ���� ��
��� s ������ һ���������� '1' ��ɵ��ֶ� ������ true �����򣬷��� false ��
ʾ�� 1��
���룺s = "1001"
�����false
���ͣ��ַ����е� 1 û���γ�һ�������ֶΡ�
ʾ�� 2��
���룺s = "110"
�����true
��ʾ��
1 <= s.length <= 100
s[i] Ϊ '0' �� '1'
s[0] Ϊ '1'
*/

class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (n >= 1 && s[i] == '1' && s[i - 1] == '0')
                return false;
            if (s[i] == '1')
                n++;
        }
        return true;
    }
};
