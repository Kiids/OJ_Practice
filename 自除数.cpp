/*
�Գ��� ��ָ���Ա���������ÿһλ������������
���磬128 ��һ���Գ�������Ϊ?128 % 1 == 0��128 % 2 == 0��128 % 8 == 0��
���У��Գ������������ 0 ��
�����ϱ߽���±߽����֣����һ���б��б��Ԫ���Ǳ߽磨���߽磩�����е��Գ�����
ʾ�� 1��
���룺 
�ϱ߽�left = 1, �±߽�right = 22
����� [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
ע�⣺
ÿ����������ı߽����� 1 <= left <= right <= 10000��
*/

class Solution {
public:
    bool Is(int n)
    {
        int x = n;
        while (n)
        {
            int t = n % 10;
            if (t == 0 || x % t != 0)
                return false;
            n /= 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> ret;
        for (int i = left ; i <= right; i++)
            if (Is(i))
                ret.push_back(i);
        return ret;
    }
};
