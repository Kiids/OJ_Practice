/*
���������ַ��� s1 �� s2 �����ǳ�����ȣ��������Ƿ����һ�� s1  �����п��Դ��� s2 ��һ�����У������Ƿ����һ�� s2 �����п��Դ��� s1 ��һ�����С�
�ַ��� x ���Դ����ַ��� y �����߳��ȶ�Ϊ n ��������������� i���� 0 �� n - 1 ֮�䣩���� x[i] >= y[i]���ֵ��������µ�˳�򣩡�
ʾ�� 1��
���룺s1 = "abc", s2 = "xya"
�����true
���ͣ�"ayx" �� s2="xya" ��һ�����У�"abc" ���ַ��� s1="abc" ��һ�����У��� "ayx" ���Դ��� "abc" ��
ʾ�� 2��
���룺s1 = "abe", s2 = "acd"
�����false 
���ͣ�s1="abe" ���������а�����"abe"��"aeb"��"bae"��"bea"��"eab" �� "eba" ��s2="acd" ���������а�����"acd"��"adc"��"cad"��"cda"��"dac" �� "dca"��Ȼ��û���κ� s1 �����п��Դ��� s2 �����С�Ҳû�� s2 �������ܴ��� s1 �����С�
ʾ�� 3��
���룺s1 = "leetcodee", s2 = "interview"
�����true
��ʾ��
s1.length == n
s2.length == n
1 <= n <= 10^5
�����ַ�����ֻ����СдӢ����ĸ��
*/

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
        bool flag = true, flag1 = true;
		for (int i = 0; i < s2.length(); i++)
        {
            if (s2[i] < s1[i] && flag)
                flag = false;
                
            if (s2[i] > s1[i] && flag1)
                flag1 = false;
        }
        return flag1 || flag;
    }
};
