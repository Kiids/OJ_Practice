/*
nowcoder�����У�A��B��ƹ�����к�˫ϲ�ġ��������ǵġ�����������Ҫ�б�A���Ƿ������B�������е����࣬����ÿ���������������B���е�����������ô���أ�
��������:
�����ж������ݡ�
ÿ�����ݰ��������ַ���A��B������A����B���е�ƹ����ÿ��ƹ������һ����д��ĸ��ʾ������ͬ���͵�ƹ����Ϊ��ͬ�Ĵ�д��ĸ��
�ַ������Ȳ�����10000��
�������:
ÿһ�������Ӧһ����������B�����������������A�ж��У�����ÿ�����������������A���������Yes�������������No����
ʾ��1
����
ABCDFYE CDE<br/>ABCDGEAS CDECDE
���
Yes<br/>No
*/

#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        map<char, int> A, B;
        for (int i = 0; i < s1.size(); i++)
            A[s1[i]]++;
        for (int i = 0; i < s2.size(); i++)
            B[s2[i]]++;
        char c[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T','U', 'V', 'W', 'X', 'Y', 'Z'};
        for (int i = 0; i <= 26; i++)
        {
            if (B[c[i]] > A[c[i]])
            {
                cout << "No" << endl;
                break;
            }
            if (c[i] == 'Z')
                cout << "Yes" << endl;
        }
    }
    return 0;
}