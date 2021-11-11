/*
����һ���Ǹ����� N���ҳ�С�ڻ���� N ������������ͬʱ���������Ҫ���������λ���ϵ������ǵ���������
�����ҽ���ÿ������λ���ϵ����� x �� y ���� x <= y ʱ�����ǳ���������ǵ��������ġ���
ʾ�� 1:
����: N = 10
���: 9
ʾ�� 2:
����: N = 1234
���: 1234
ʾ�� 3:
����: N = 332
���: 299
˵��: N ���� [0, 10^9] ��Χ�ڵ�һ��������
*/

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i - 1] <= s[i])
                continue;
            int j = i - 1;
            while (j - 1 >= 0 && s[j - 1] == s[j])
                j--;
            s[j]--;
            for (j = j + 1; j < s.size(); j++)
                s[j] = '9';
        }
        return stoi(s);
    }
};
