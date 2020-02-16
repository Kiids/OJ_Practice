/*
�ж�һ�������Ƿ��ǻ���������������ָ���򣨴������ң��͵��򣨴������󣩶�����һ����������
ʾ�� 1:
����: 121
���: true
ʾ�� 2:
����: -121
���: false
����: �������Ҷ�, Ϊ -121 �� ���������, Ϊ 121- �����������һ����������
ʾ�� 3:
����: 10
���: false
����: ���������, Ϊ 01 �����������һ����������
����:
���ܲ�������תΪ�ַ�����������������
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x <= 9 && x >= 0)
            return true;
        
        /*int sum = 0, num = x;
        while (num)
        {
            sum = sum * 10 + num % 10;  // �ᷢ�����
            num = num / 10;
        }
        if (sum == x)
            return true;
        else
            return false;*/
        
        int div = 1;
        while (x / div >= 10)
            div *= 10;
        while (x > 0)
        {
            int left = x / div;
            int right = x % 10;
            if (left != right)
                return false;
            x = (x % div) / 10;
            div /= 100;
        }
        return true;
    }
};
