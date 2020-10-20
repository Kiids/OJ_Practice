/*
С���������м�ѡ����һ�����̯λ��һά�������� staple �м�¼��ÿ����ʳ�ļ۸�һά�������� drinks �м�¼��ÿ�����ϵļ۸�С�۵ļƻ�ѡ��һ����ʳ��һ�����ϣ��һ��Ѳ����� x Ԫ���뷵��С�۹��ж����ֹ��򷽰���
ע�⣺����Ҫ�� 1e9 + 7 (1000000007) Ϊ��ȡģ���磺�����ʼ���Ϊ��1000000008���뷵�� 1
ʾ�� 1��
���룺staple = [10,20,5], drinks = [5,5,2], x = 15
�����6
���ͣ�С���� 6 �ֹ��򷽰�����ѡ��ʳ����ѡ�����������ж�Ӧ���±�ֱ��ǣ�
�� 1 �ַ�����staple[0] + drinks[0] = 10 + 5 = 15��
�� 2 �ַ�����staple[0] + drinks[1] = 10 + 5 = 15��
�� 3 �ַ�����staple[0] + drinks[2] = 10 + 2 = 12��
�� 4 �ַ�����staple[2] + drinks[0] = 5 + 5 = 10��
�� 5 �ַ�����staple[2] + drinks[1] = 5 + 5 = 10��
�� 6 �ַ�����staple[2] + drinks[2] = 5 + 2 = 7��
ʾ�� 2��
���룺staple = [2,1,1], drinks = [8,9,5,1], x = 9
�����8
���ͣ�С���� 8 �ֹ��򷽰�����ѡ��ʳ����ѡ�����������ж�Ӧ���±�ֱ��ǣ�
�� 1 �ַ�����staple[0] + drinks[2] = 2 + 5 = 7��
�� 2 �ַ�����staple[0] + drinks[3] = 2 + 1 = 3��
�� 3 �ַ�����staple[1] + drinks[0] = 1 + 8 = 9��
�� 4 �ַ�����staple[1] + drinks[2] = 1 + 5 = 6��
�� 5 �ַ�����staple[1] + drinks[3] = 1 + 1 = 2��
�� 6 �ַ�����staple[2] + drinks[0] = 1 + 8 = 9��
�� 7 �ַ�����staple[2] + drinks[2] = 1 + 5 = 6��
�� 8 �ַ�����staple[2] + drinks[3] = 1 + 1 = 2��
��ʾ��
1 <= staple.length <= 10^5
1 <= drinks.length <= 10^5
1 <= staple[i],drinks[i] <= 10^5
1 <= x <= 2*10^5
*/

class Solution {
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        const int mod = 1e9 + 7;
        int ret = 0;
        sort (staple.begin(), staple.end());
        sort (drinks.begin(), drinks.end());
        int j = drinks.size() - 1;
        for (int i = 0; i < staple.size(); i++)
        {
            while (j >= 0 && staple[i] + drinks[j] > x)
                j--;
            if (j == -1)
                break;
            ret += j + 1;
            ret %= mod;
        }
        return ret;
    }
};
