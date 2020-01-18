/*
Levenshtein ���룬�ֳƱ༭���룬ָ���������ַ���֮�䣬��һ��ת������һ����������ٱ༭����������
��ɵı༭����������һ���ַ��滻����һ���ַ�������һ���ַ���ɾ��һ���ַ���
�༭������㷨�������ɶ����ѧ��Levenshtein����ģ����ֽ�Levenshtein Distance��
Ex��
�ַ���A:abcdefg
�ַ���B: abcdef
ͨ�����ӻ���ɾ���ַ���g���ķ�ʽ�ﵽĿ�ġ������ַ�������Ҫһ�β������������������Ҫ�Ĵ�������Ϊ�����ַ����ľ��롣
Ҫ��
�������������ַ�����д��һ���㷨�������ǵı༭���롣
��ʵ�����½ӿ�
/*  ���ܣ����������ַ����ľ���
 *  ���룺 �ַ���A���ַ���B
 *  �������
 *  ���أ�����ɹ�������ַ����ľ��룬���򷵻�-1
 *//*
     public   static   int  calStringDistance (String charA, String  charB)
    {
        return  0;
    }  
��������:
���������ַ���
�������:
�õ�������
ʾ��1
����
abcdefg
abcdef
���
1
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> v(n+1, vector<int>(m+1));
        
        // ����һ�и�ֵ 
        for (int j = 0; j <= m; j++)
            v[0][j] = j;
        // ����һ�и�ֵ 
        for (int i = 0; i <= n; i++)
            v[i][0] = i;
        
        // ��̱༭���룬��̬�滮 
        // �����Ӵ������һ���ַ���ȣ������ǵ���̱༭����͸�ɾ�����һ���ַ������̱༭������� 
        // ��ĩβ�ַ������ʱ�����滻�����롢ɾ����ѡ���������ַ����༭�������ٵģ�������1 
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int d1 = v[i-1][j-1];
                int d2 = v[i][j-1] + 1;
                int d3 = v[i-1][j] + 1;
                if (s1[i-1] != s2[j-1])
                    d1 += 1;
                v[i][j] = min(min(d1, d2), d3);
            }
        }
        cout << v[n][m] << endl;
    }
    return 0;
}

// https://blog.csdn.net/c20190413/article/details/75030105
// https://blog.csdn.net/shizheng163/article/details/50988023
