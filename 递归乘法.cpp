/*
�ݹ�˷��� дһ���ݹ麯������ʹ�� * ������� ʵ����������������ˡ�����ʹ�üӺš����š�λ�ƣ���Ҫ����һЩ��
ʾ��1:
 ���룺A = 1, B = 10
 �����10
ʾ��2:
 ���룺A = 3, B = 4
 �����12
��ʾ:
��֤�˷���Χ�������
*/

class Solution {
public:
    int multiply(int A, int B) {
        int ret;
        if (B > 1)
            ret = multiply(A, B - 1) + A;
        else
            ret = A;
        return ret;
    }
};
