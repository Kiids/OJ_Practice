/*
����һ������ n, ���ش� 1 �� n ���ֵ�˳��
���磬
���� n =1 3������ [1,10,11,12,13,2,3,4,5,6,7,8,9] ��
�뾡���ܵ��Ż��㷨��ʱ�临�ӶȺͿռ临�Ӷȡ� ��������� n С�ڵ��� 5,000,000��
*/

class Solution {
public:
    vector<int> ret;
    vector<int> lexicalOrder(int n) {
        for (int i = 1; i <= 9; i++)
            DFS(i, n);
        return ret;
    }

    void DFS(int num, int& n)
    {
        if (num > n)
            return;
        ret.push_back(num);
        for (int i = 0; i <= 9; i++)
            DFS(num * 10 + i, n);
    }
};
