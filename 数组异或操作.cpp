/*
��������������n �� start ��
���� nums ����Ϊ��nums[i] = start + 2*i���±�� 0 ��ʼ���� n == nums.length ��
�뷵�� nums ������Ԫ�ذ�λ���XOR����õ��Ľ����
ʾ�� 1��
���룺n = 5, start = 0
�����8
���ͣ����� nums Ϊ [0, 2, 4, 6, 8]������ (0 ^ 2 ^ 4 ^ 6 ^ 8) = 8 ��
     "^" Ϊ��λ��� XOR �������
ʾ�� 2��
���룺n = 4, start = 3
�����8
���ͣ����� nums Ϊ [3, 5, 7, 9]������ (3 ^ 5 ^ 7 ^ 9) = 8.
ʾ�� 3��
���룺n = 1, start = 7
�����7
ʾ�� 4��
���룺n = 10, start = 5
�����2
��ʾ��
1 <= n <= 1000
0 <= start <= 1000
n == nums.length
*/

class Solution {
public:
    int xorOperation(int n, int start) {
        int ret = 0;
        for (int i = start; i < (start + n * 2); i += 2)
            ret ^= i;
        return ret;
    }
};

/*
��������
1) 0 ^ x = x
2) x ^ x = 0
3) 2x ^ (2x+1) = 1
�������Ҫ˼�룺
������תΪ��ż����ͷ����1Ϊ���������У�����������ʽ��м��㣬�õ������*2
Ȼ���ٶ����յĽ�����һλ����,���һλ����������

1����ǰ�����в���Ϊ2������Ŀ��Ĳ���Ϊ1�������Ҫ���Ƕ���������/2����start/2������Ϊ1
    startΪ������ʱ����ô���ݹ�ʽ2���������2�� (start-1)�������תΪ��ͷΪż�����м���
        array(start, n) = (start-1) ^ array(start-1�� n+1)����ʱn=n+1
    startΪż��
        nΪ���������ݹ�ʽ3������һ���� n/2��1 �� һ��start+num-1 �������,�� res = (n/2)^1 & (start+num-1)
        nΪż�������ݹ�ʽ3������һ���� n/2��1������򣬼� res = (n/2)^1
    ���� res

2������1�Ĵ���ÿ����/2�����Ѷ������������һλȥ����ͳͳ����Ų��һλ
    ����Ҫ�ָ�����Ҫ����Ų��1λ,��res = res * 2
    Ȼ����ʼ������������һλ�ļ���
        ���ҽ���startΪ������nΪ������ʱ�����һλ��������Ϊ1������Ϊ�㣬
        if (start&1 && n&1)
            res += 1
���յ�res��Ϊ���ս��
����ʵ�����£�
*/
class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = 2 * myxor(n, start/2);
        if (n & start & 1)
            ans += 1;
        return ans;
    }

    int myxor(int n, int start)
    {
        if (start & 1)
            return (start-1) ^ myxor(n+1, start-1);
        else
        {
            if (n & 1)
                return (start+n-1) ^ ((n/2) & 1);
            else
                return (n/2) & 1;
        }
    }
};
