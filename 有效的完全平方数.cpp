/*
����һ�������� num����дһ����������� num ��һ����ȫƽ�������򷵻� True�����򷵻� False��
˵������Ҫʹ���κ����õĿ⺯������? sqrt��
ʾ�� 1��
���룺16
�����True
ʾ�� 2��
���룺14
�����False
*/

// ��1��ʼn�������ĺ���һ����ȫƽ���� 
class Solution {
public:
    bool isPerfectSquare(int num) {
        int ret = 1;
        while (num > 0) 
        {
            num -= ret;
            ret += 2;
        }
        return num == 0;
    }
};
