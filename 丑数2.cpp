/*
��дһ�������жϸ��������Ƿ�Ϊ������
��������ֻ���������� 2, 3, 5 ����������
ʾ�� 1:
����: 6
���: true
����: 6 = 2 �� 3
ʾ�� 2:
����: 8
���: true
����: 8 = 2 �� 2 �� 2
ʾ�� 3:
����: 14
���: false 
����: 14 ���ǳ�������Ϊ������������һ�������� 7��
˵����
1 �ǳ�����
���벻�ᳬ�� 32 λ�з��������ķ�Χ: [-2^31, 2^31 - 1]��
*/

class Solution {
public:
    bool isUgly(int num) {
        if (num == 1)
            return true;
        else if (num == 0)
            return false;

        while (1)
        {
            if (num % 2 == 0)
                num /= 2;
            else if (num % 3 == 0)
                num /= 3;
            else if (num % 5 == 0)
                num /= 5;
            else
                break;
        }
        
        if (num == 1)
            return true;
        else
            return false;
    }
};
