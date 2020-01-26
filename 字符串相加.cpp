// ���������ַ�����ʽ�ķǸ����� num1 ��num2 ���������ǵĺ͡�
// ע�⣺
// num1 ��num2 �ĳ��ȶ�С�� 5100.
// num1 ��num2 ��ֻ�������� 0-9.
// num1 ��num2 ���������κ�ǰ���㡣
// �㲻��ʹ���κ΃Ƚ� BigInteger �⣬ Ҳ����ֱ�ӽ�������ַ���ת��Ϊ������ʽ��

class Solution {
public:
    string addStrings(string num1, string num2) {
        int L = num1.size();
        int R = num2.size();
        
        if (L < R)
        {
            num1.swap(num2);
            swap(L, R);
        }
        string ret;
        ret.reserve(L+1);
        char cRet = 0;
        char cstep = 0;
        for (size_t i = 0; i < L; ++i)
        {
            cRet = num1[L - i - 1] - '0' + cstep;
            cstep = 0;
            if(i < R)
            {
                cRet += num2[R - i - 1] - '0';
            }
            if(cRet >= 10)
            {
                cRet -= 10;
                cstep = 1;
            }
            ret += cRet + '0';
        }
        if(cstep)
            ret += '1';
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

