/*
����һ������ n ���Զ������ַ�������ʽ���ظ������� �������ƣ�base -2����ʾ��
ע�⣬�����ַ������� "0"�����򷵻ص��ַ����в��ܺ���ǰ���㡣
ʾ�� 1��
���룺n = 2
�����"110"
���ͣ�(-2)2 + (-2)1 = 2
ʾ�� 2��
���룺n = 3
�����"111"
���ͣ�(-2)2 + (-2)1 + (-2)0 = 3
ʾ�� 3��
���룺n = 4
�����"100"
���ͣ�(-2)2 = 4
��ʾ��
0 <= n <= 10^9
*/

class Solution {
    vector<int> baseK(int n, int k)
    {
        if (n == 0)
            return {0};

        vector<int> v;
        while (n != 0)
        {
            int c = ((n % k) + abs(k)) % abs(k);
            v.push_back(c);
            n -= c;
            n /= k;
        }
        reverse(v.begin(), v.end());
        return v;
    }
public:
    string baseNeg2(int n) {
        vector<int> v = baseK(n, -2);
        string s;
        for (auto e : v)
            s += to_string(e);
        return s;
    }
};
