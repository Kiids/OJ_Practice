/*
�ַ���ѹ���������ַ��ظ����ֵĴ�������дһ�ַ�����ʵ�ֻ������ַ���ѹ�����ܡ����磬�ַ���aabcccccaaa���Ϊa2b1c5a3������ѹ��������ַ���û�б�̣��򷵻�ԭ�ȵ��ַ���������Լ����ַ�����ֻ������СдӢ����ĸ��a��z����
ʾ��1:
 ���룺"aabcccccaaa"
 �����"a2b1c5a3"
ʾ��2:
 ���룺"abbccd"
 �����"abbccd"
 ���ͣ�"abbccd"ѹ����Ϊ"a1b2c2d1"����ԭ�ַ������ȸ�����
��ʾ��
�ַ���������[0, 50000]��Χ�ڡ�
*/

class Solution {
public:
    string compressString(string S) {
        if (S.size() == 0)
            return "";
        
        string ret = "";
        int n = 1;
        char c = S[0];
        for (int i = 1; i <S.size(); i++)
        {
            if (c == S[i])
                n++;
            else
            {
                ret += c + to_string(n);
                c = S[i];
                n = 1;
            }
        }
        ret += c + to_string(n);
        return ret.size() >= S.size() ? S : ret;
    }
};
