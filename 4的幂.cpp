/*
����һ������ (32 λ�з�������)�����дһ���������ж����Ƿ��� 4 ���ݴη���
ʾ�� 1:
����: 16
���: true
ʾ�� 2:
����: 5
���: false
���ף�
���ܲ�ʹ��ѭ�����ߵݹ�����ɱ�����
*/

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num < 0)
            return false;
        int t = num & (-num);
        if (num - t != 0)
            return false;
        return num % 3 == 1;
    }
};
// ���ж��ǲ���ֻ��һλ��1��Ȼ��ģ3�Ľ�������ģ3Ϊ1����true�����ģ3Ϊ2��false

// ѭ��
class Solution {
public:
    bool isPowerOfFour(int num) {
        while (num  && num % 4 == 0) {
            num /= 4;
        }
        return num == 1;
    }
};

// λ����
// 4�Ĵη���һ����2�Ĵη�������2�Ĵη�����һ����4�Ĵη�����ͨ
// ��4�Ĵη��������ƿ��Է���4�Ĵη�����������1ֻ����������λ��
// ��˿���ͨ��������λ����1��ż��Ϊ����0������1010101010101010101010101010101�����������㣬�����Ϊԭ������
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && !(num & (num - 1)) && (num & 0x55555555) == num;
    }
};
