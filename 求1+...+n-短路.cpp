/*
�� 1+2+...+n ��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����
ʾ�� 1��
����: n = 3
���: 6
ʾ�� 2��
����: n = 9
���: 45
���ƣ�
1 <= n <= 10000
*/

// �߼������еĶ�· 
class Solution {
public:
    int ret = 0;
    int sumNums(int n) {
        bool x = n > 1 && sumNums(n - 1) > 0;
        ret += n;
        return ret;
    }
};
