/*
����һ���Ǹ����� num������������λ�ϵ�������ӣ�ֱ�����Ϊһλ����
ʾ��:
����: 38
���: 2 
����: ��λ��ӵĹ���Ϊ��3 + 8 = 11, 1 + 1 = 2�� ���� 2 ��һλ�������Է��� 2��
����:
����Բ�ʹ��ѭ�����ߵݹ飬���� O(1) ʱ�临�Ӷ��ڽ�����������
*/

class Solution {
public:
    int addDigits(int num) {
        while (num / 10 != 0)
        {
            int sum = 0;
            while (num != 0)
            {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
};

class Solution {
public:
    int addDigits(int num) {
        //��������Χ���䵽0~9
        return (num-1) % 9 + 1;
    }
};

//    2λ��
//    num = a * 10 + b
//    num1 = a + b
//    num - num1 = 9 * a;
//    ��С��a ��9
//    3λ��
//    num = a * 100 + b * 10 + c
//    num1 = a + b + c
//    num - num1 = 99 * a + 9 * b
//    ��С��(11 * a + b) * 9
//    ��ʼ��������9�ı���
//    ���Կ�ʼ���ݶ�9ȡģʣ�µľ���������Ҫ�Ľ��

class Solution {
public:
    int addDigits(int num) {
        if(num == 0)    
            return 0;
        return num % 9 ? num % 9 : 9;   //��9��ʱ��Ͳ����ټ����� ��������Ϊ0Ϊ9
    }
};
