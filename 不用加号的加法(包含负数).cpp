/*
���һ������������������ӡ�����ʹ�� + �������������������
ʾ��:
����: a = 1, b = 1
���: 2
��ʾ��
a, b �������Ǹ����� 0
���������� 32 λ����
*/

class Solution {
public:
    int add(int a, int b) {
        if (b == 0)
            return a;
        if (a == 0)
            return b;
        
        int t1 = 0, t2 = 0, t3 = 0;
        while (b != 0)
        {
        	t1 = a ^ b;
	        t2 = a & b;
	        t3 = (unsigned int)t2 << 1;
	        a = t1;
	        b = t3;
		}
        return t1;
    }
};
