/*
�����һ���㷨������������������ļӷ���
�ӿ�˵��
*/
 /*
 �����һ���㷨������������������ļӷ���
 ���������
 String addend������
 String augend��������
 ����ֵ���ӷ����
 *//*
 public String AddLongInteger(String addend, String augend)
 {
     /*������ʵ�ֹ���*//*
  return null;     
 }
��������:
���������ַ�������
�������:
�����Ӻ�Ľ����string��
ʾ��1
����
99999999999999999999999999999999999999999999999999
1
���
100000000000000000000000000000000000000000000000000
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string AddLongInteger(string addend, string augend)
{
    int l1 = addend.size();
    int l2 = augend.size();

    if (l1 < l2)
    {
        addend.swap(augend);
        swap(l1, l2);
    }

    string ret;
    ret.reserve(l1 + 1);
    char s = 0, r = 0;
    for (int i = 0; i < l1; i++)
    {
        r = addend[l1 - i - 1] - '0' + s;
        s = 0;
        if (i < l2)
            r += augend[l2 - i - 1] - '0';
        if (r >= 10)
        {
            r -= 10;
            s = 1;
        }
        ret += r + '0';
    }
    if (s)
        ret += '1';
    reverse(ret.begin(), ret.end());
    return ret;
}

int main()
{
    string s1, s2;
    while (cin >> s1 >> s2)
        cout << AddLongInteger(s1, s2) << endl;
    return 0;
}
