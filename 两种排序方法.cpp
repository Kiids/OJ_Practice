/* 
������n���ַ����ַ��������������ַ������ȶ��ǲ�ͬ�ġ��������ѧϰ���������ַ��������򷽷��� 1.�����ַ������ֵ����������磺
"car" < "carriage" < "cats" < "doggies < "koala"
2.�����ַ����ĳ����������磺
"car" < "cats" < "koala" < "doggies" < "carriage"
������֪���Լ�����Щ�ַ�������˳���Ƿ��������������򷽷�������Ҫæ�ų���Ҷ��������Ҫ������æ��֤��
��������:
�����һ��Ϊ�ַ�������n(n �� 100)
��������n��,ÿ��һ���ַ���,�ַ������Ⱦ�С��100������Сд��ĸ���
�������:
�����Щ�ַ����Ǹ����ֵ������ж����Ǹ��ݳ����������"lexicographically",
������ݳ������ж������ֵ����������"lengths",
������ַ�ʽ���������"both"���������"none"
ʾ��1
����
3
a
aa
bbb
���
both
*/
 
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool AtoZ(vector<string> &v)
{
    for (int i = 0; i < v.size()-1; i++)
    {
        if (v[i] > v[i+1])
            return false;
    }
    return true;
}

bool Len(vector<string> &v)
{
    for (int i = 0; i < v.size()-1; i++)
    {
        if (v[i].size() > v[i+1].size())
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    string s;
    vector<string> v;
    v.reserve(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        v.push_back(s);
    }
    
    if (Len(v))
    {
        if (AtoZ(v))
            cout << "both" << endl;
        else if (!AtoZ(v))
            cout << "lengths" << endl;
    }
    else if (!Len(v))
    {
        if (AtoZ(v))
            cout << "lexicographically" << endl;
        else if (!AtoZ(v))
            cout << "none" << endl;
    }
    
    return 0;
}
