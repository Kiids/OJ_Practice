/*
0,1,,n-1��n�������ų�һ��ԲȦ��������0��ʼ��ÿ�δ����ԲȦ��ɾ����m�����֡�������ԲȦ��ʣ�µ����һ�����֡�
���磬0��1��2��3��4��5���������һ��ԲȦ��������0��ʼÿ��ɾ����3�����֣���ɾ����ǰ4������������2��0��4��1��������ʣ�µ�������3��
ʾ�� 1��
����: n = 5, m = 3
���: 3
ʾ�� 2��
����: n = 10, m = 17
���: 2
���ƣ�
1 <= n <= 10^5
1 <= m <= 10^6
*/

// Լɪ�� f(n,m)=[f(n-1,m)+m]%n
// https://blog.csdn.net/u011500062/article/details/72855826 

class Solution {
public:
    int lastRemaining(int n, int m) {
        int pos = 0; // ʣ�µ����һ�����ֵĳ�ʼλ��
        for(int i = 2; i <= n; i++)
            pos = (pos + m) % i;  // ѭ������
        
        return pos;
    }
};

// ���·����ᳬʱ
class Solution {
public:
    int lastRemaining(int n, int m) {
        if (n == 0)
            return 0;
        
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            v[i] = i;
        
        auto b = v.begin();
        while (v.size() > 1)
        {
            for (int i = 0; i < m - 1; i++)
            {
                b++;
                if (b == v.end())
                    b = v.begin();
            }

            b = v.erase(b);
            if (b == v.end())
                b = v.begin();
        }

        return v[0];
    }
}; 
