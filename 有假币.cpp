/*
��Ȼ�мٱң� �����������ˣ�����ũ��Ĺ���ȴ�����ǰ���ûǮ��ô�����Ⱑ��nowcoder���ȥ�����⣬
�����������Ǯ���мٱң�������ϧnowcoder һ��С�İ��������һ���������ȥ�ˡ�ֻ֪���ٱҵ���������ҵ�����Ҫ�ᣬ
����һ����ƽ����ƽ�������������޸�Ӳ�ң�����������ʱ����Ǹ��ɶ�ļٱ��ҳ�����
��������:
1��n��2^30,����0��������
�������:
���Ҫ�Ƽ���һ���ܰ��Ǹ��ٱ��ҳ�����
ʾ��1
����
3
12
0
���
1
3
*/

// write your code here cpp
#include <iostream>
#include <algorithm>
using namespace std;

int Count(long long n)
{
    if (n == 1)
        return 0;
    else if (n <= 3)
        return 1;
    int metage = 0, rest = 0, count = 0;  // ��ƽ�ϵ�Ǯ��ʣ���Ǯ����������
    metage = (n+2)/3;
    rest = n - 2*metage;
    count = 1 + Count(max(metage, rest));
    return count;
}

int main()
{
    long long n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        cout << Count(n) << endl;
    }
    return 0;
}
