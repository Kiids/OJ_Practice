/*
URL������дһ�ַ��������ַ����еĿո�ȫ���滻Ϊ%20���ٶ����ַ���β�����㹻�Ŀռ��������ַ�������֪���ַ����ġ���ʵ�����ȡ���ע����Javaʵ�ֵĻ�����ʹ���ַ�����ʵ�֣��Ա�ֱ���������ϲ�������
ʾ��1:
 ���룺"Mr John Smith    ", 13
 �����"Mr%20John%20Smith"
ʾ��2:
 ���룺"               ", 5
 �����"%20%20%20%20%20"
��ʾ��
�ַ���������[0, 500000]��Χ�ڡ�
*/

class Solution {
public:
    string replaceSpaces(string S, int length) {
        string ret = "";
        int i = 0;
        for (auto e : S)
        {
            if (e == ' ')
                ret += "%20";
            else
                ret += e;
            i++;
            if (i == length)
                break;
        }
        return ret;
    }
};
