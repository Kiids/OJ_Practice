/*
�ܹ��� n ����ɫƬ���ų�һ�У�ÿ����ɫƬ��Ҫô�� 'A' Ҫô�� 'B' ������һ������Ϊ n ���ַ��� colors ������ colors[i] ��ʾ�� i ����ɫƬ�ε���ɫ��
Alice �� Bob ����һ����Ϸ������ ���� ������ַ�����ɾ����ɫ��Alice ���� ��
���һ����ɫƬ��Ϊ 'A' �� ����������ɫ ������ɫ 'A' ����ô Alice ����ɾ������ɫƬ�Ρ�Alice ������ ɾ���κ���ɫ 'B' Ƭ�Ρ�
���һ����ɫƬ��Ϊ 'B' �� ����������ɫ ������ɫ 'B' ����ô Bob ����ɾ������ɫƬ�Ρ�Bob ������ ɾ���κ���ɫ 'A' Ƭ�Ρ�
Alice �� Bob ���� ���ַ�������ɾ����ɫƬ�Ρ�
�������һ���޷����������������� �� ����Ϸ����һ��� ��ʤ ��
���� Alice �� Bob ���������Ų��ԣ���� Alice ��ʤ���뷵�� true������ Bob ��ʤ������ false��
ʾ�� 1��
���룺colors = "AAABABB"
�����true
���ͣ�
AAABABB -> AABABB
Alice �Ȳ�����
��ɾ���������ڶ��� 'A' ����Ҳ��Ψһһ��������ɫƬ�ζ��� 'A' �� 'A' ��
�����ֵ� Bob ������
Bob �޷�ִ���κβ�������Ϊû������λ�ö��� 'B' ����ɫƬ�� 'B' ��
��ˣ�Alice ��ʤ������ true ��
ʾ�� 2��
���룺colors = "AA"
�����false
���ͣ�
Alice �Ȳ�����
ֻ�� 2 �� 'A' �����Ƕ����ַ��������ˣ��������޷�ִ���κβ�����
��ˣ�Bob ��ʤ������ false ��
ʾ�� 3��
���룺colors = "ABBBBBBBAAA"
�����false
���ͣ�
ABBBBBBBAAA -> ABBBBBBBAA
Alice �Ȳ�����
��Ψһ��ѡ����ɾ����������ڶ��� 'A' ��
ABBBBBBBAA -> ABBBBBBAA
�������ֵ� Bob ������
�������ѡ��������ѡ���κ�һ�� 'B' ɾ����
Ȼ���ֵ� Alice ���������޷�ɾ���κ�Ƭ�Ρ�
���� Bob ��ʤ������ false ��
��ʾ��
1 <= colors.length <= 10^5
colors ֻ������ĸ 'A' �� 'B'
*/

class Solution {
public:
    bool winnerOfGame(string colors) {
        if (colors.size() < 3)
            return false;
        else if (colors.size() == 3)
        {
            if (colors == "AAA")
                return true;
        }
        int ret = 0;
        for (int i = 0; i < colors.size() - 2; i++)
        {
            string s = colors.substr(i, 3);
            if (s == "AAA")
                ret++;
            if (s == "BBB")
                ret--;
        }
        return ret > 0;
    }
};
