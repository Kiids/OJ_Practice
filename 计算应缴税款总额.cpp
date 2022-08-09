/*
����һ���±�� 0 ��ʼ�Ķ�ά�������� brackets ������ brackets[i] = [upperi, percenti] ����ʾ�� i ��˰���������� upperi �����յ�˰��Ϊ percenti ��˰�������� �ӵ͵������������� 0 < i < brackets.length ��ǰ���£�upperi-1 < upperi����
˰����㷽ʽ���£�
������ upper0 �����밴˰�� percent0 ����
���� upper1 - upper0 �Ĳ��ְ�˰�� percent1 ����
Ȼ�� upper2 - upper1 �Ĳ��ְ�˰�� percent2 ����
�Դ�����
����һ������ income ��ʾ��������롣��������Ҫ���ɵ�˰���ܶ���׼������ 10-5 �Ľ������������ȷ�𰸡�
ʾ�� 1��
���룺brackets = [[3,50],[7,10],[12,25]], income = 10
�����2.65000
���ͣ�
ǰ $3 ��˰��Ϊ 50% ����Ҫ֧��˰�� $3 * 50% = $1.50 ��
������ $7 - $3 = $4 ��˰��Ϊ 10% ����Ҫ֧��˰�� $4 * 10% = $0.40 ��
��� $10 - $7 = $3 ��˰��Ϊ 25% ����Ҫ֧��˰�� $3 * 25% = $0.75 ��
��Ҫ֧����˰���ܼ� $1.50 + $0.40 + $0.75 = $2.65 ��
ʾ�� 2��
���룺brackets = [[1,0],[4,25],[5,50]], income = 2
�����0.25000
���ͣ�
ǰ $1 ��˰��Ϊ 0% ����Ҫ֧��˰�� $1 * 0% = $0 ��
ʣ�� $1 ��˰��Ϊ 25% ����Ҫ֧��˰�� $1 * 25% = $0.25 ��
��Ҫ֧����˰���ܼ� $0 + $0.25 = $0.25 ��
ʾ�� 3��
���룺brackets = [[2,50]], income = 0
�����0.00000
���ͣ�
û�����룬������˰����Ҫ֧����˰���ܼ� $0 ��
��ʾ��
1 <= brackets.length <= 100
1 <= upperi <= 1000
0 <= percenti <= 100
0 <= income <= 1000
upperi ������˳������
upperi �е�����ֵ ������ͬ
���һ��˰�������޴��ڵ��� income
*/

class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int ret = 0, pre = 0;
        for (int i = 0; i < brackets.size(); i++)
        {
            if (income == 0)
                break;
            int cur = min(brackets[i][0] - pre, income);
            ret += cur * brackets[i][1];
            income -= cur;
            pre = brackets[i][0];
        }
        return (double)ret / 100.0;
    }
};
