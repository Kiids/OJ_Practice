/*
���ַ��� s �����ǡ�abcdefghijklmnopqrstuvwxyz�������޻����ַ��������� s �������������ģ�"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....". 
��������������һ���ַ��� p ������Ҫ�����ҳ� s ���ж��ٸ�Ψһ�� p �ķǿ��Ӵ��������ǵ�����������ַ��� p ������Ҫ����ַ��� s �� p �Ĳ�ͬ�ķǿ��Ӵ�����Ŀ�� 
ע��: p ����Сд��Ӣ����ĸ��ɣ�p �Ĵ�С���ܳ��� 10000��
ʾ�� 1:
����: "a"
���: 1
����: �ַ��� S ��ֻ��һ��"a"���ַ���
ʾ�� 2:
����: "cac"
���: 2
����: �ַ��� S �е��ַ�����cac��ֻ�������Ӵ���a������c����.
ʾ�� 3:
����: "zab"
���: 6
����: ���ַ��� S ���������Ӵ���z������a������b������za������ab������zab����.
*/

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> dp(26, 0);
        int k = 1;
        dp[p[0] - 'a'] = 1;
        for (int i = 1; i < p.size(); i++)
        {
            if (check(p[i - 1], p[i]))
                k++;
            else
                k = 1;
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], k);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }

    bool check(char c, char d)
    {
        if (c == 'z')
            return d == 'a';
        return c + 1 == d;
    }
};
