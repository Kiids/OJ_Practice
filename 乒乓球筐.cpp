/*
nowcoder有两盒（A、B）乒乓球，有红双喜的、有亚力亚的……现在他需要判别A盒是否包含了B盒中所有的种类，并且每种球的数量不少于B盒中的数量，该怎么办呢？
输入描述:
输入有多组数据。
每组数据包含两个字符串A、B，代表A盒与B盒中的乒乓球，每个乒乓球用一个大写字母表示，即相同类型的乒乓球为相同的大写字母。
字符串长度不大于10000。
输出描述:
每一组输入对应一行输出：如果B盒中所有球的类型在A中都有，并且每种球的数量都不大于A，则输出“Yes”；否则输出“No”。
示例1
输入
ABCDFYE CDE<br/>ABCDGEAS CDECDE
输出
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