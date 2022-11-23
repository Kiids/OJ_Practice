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

// ��¼��ÿ���ַ���β�ִ��������
// Ȼ�������ۼ�


class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> dp(26,0);
        int count = 0;
        for (int i = 0; i < p.size(); i++)
        {
            if (i > 0 && ((p[i - 1] + 1) % 26 == p[i] % 26))
                count++;
            else
                count = 1;
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], count);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};

//��̬�滮 
//dp[i]�����ַ���p[i]��β�������ַ����ķǿ��Ӵ���������.
//p[i]-'a'�õ���Ӧdp�����±�
//�� p[i-1] == p[i],count++������һ���ַ��������� ʱ�� ���������ַ�������Ϊ dp[p[i]-'a'] = max(dp[p[i]-'a'],count);
//�� p[i-1]!=p[i],count = 1,����һ���ַ������� ʱ�� ���������ַ�������Ϊ dp[p[i]-'a'] = max(dp[p[i]-'a'],count);��
//ת�Ʒ���
//dp[p[i]-'a'] = max(dp[p[i]-'a'],count) ��
//��ʼ״̬
//i = 0 ʱ dp[p[i]-'a'] = 1��
//dp[i] ���� dp[i-1]����ǰ��������
//dp������ͼ������
//ʱ�临�Ӷȣ�O(n)������ n ���ַ��� p �ĳ��ȡ�
//�ռ临�Ӷȣ�O(1)��

