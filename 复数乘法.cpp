/*
���� �������ַ�����ʾ����ѭ "ʵ��+�鲿i" ����ʽ������������������
ʵ�� ��һ��������ȡֵ��Χ�� [-100, 100]
�鲿 Ҳ��һ��������ȡֵ��Χ�� [-100, 100]
i2 == -1
���������ַ�����ʾ�ĸ��� num1 �� num2 ��������ѭ������ʾ��ʽ�����ر�ʾ���ǳ˻����ַ�����
ʾ�� 1��
���룺num1 = "1+1i", num2 = "1+1i"
�����"0+2i"
���ͣ�(1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i ������Ҫ����ת��Ϊ 0+2i ����ʽ��
ʾ�� 2��
���룺num1 = "1+-1i", num2 = "1+-1i"
�����"0+-2i"
���ͣ�(1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i ������Ҫ����ת��Ϊ 0+-2i ����ʽ�� 
��ʾ��
num1 �� num2 ������Ч�ĸ�����ʾ��
*/

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int a1 = stoi(num1), b1 = stoi(num2), i = 0, j = 0;
        while (num1[i] != '+')
            i++;
        while (num2[j] != '+')
            j++;
        num1 = num1.substr(i + 1), num2 = num2.substr(j + 1);
        int a2 = stoi(num1), b2 = stoi(num2);
        string x = to_string(a1 * b1 - a2 * b2);
        string y = to_string(a1 * b2 + a2 * b1);
        return x + "+" + y + "i";
    }
};

// �������������зָ�ָ����֮���ո������㷨����м���
