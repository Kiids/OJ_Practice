/*
����һ���ַ��� s ����ֻ���������ַ� a, b �� c ��
���㷵�� a��b �� c �� ���� ���ֹ�һ�ε����ַ�����Ŀ��
ʾ�� 1��
���룺s = "abcabc"
�����10
���ͣ����� a��b �� c ������һ�ε����ַ���Ϊ "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" �� "abc" (��ͬ�ַ�������)��
ʾ�� 2��
���룺s = "aaacb"
�����3
���ͣ����� a��b �� c ������һ�ε����ַ���Ϊ "aaacb", "aacb" �� "acb" ��
ʾ�� 3��
���룺s = "abc"
�����1
��ʾ��
3 <= s.length <= 5 x 10^4
s ֻ�����ַ� a��b �� c ��
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int ret = 0, a = -1, b = -1, c = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'a')
            {
                a = i;
                ret += min(b, c) + 1;
            }
            else if (s[i] == 'b')
            {
                b = i;
                ret += min(a, c) + 1;
            }
            else
            {
                c = i;
                ret += min(a, b) + 1;
            }
        }
        return ret;
    }
};


class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt[3];
        cnt[0] = -1;
        cnt[1] = -1;
        cnt[2] = -1;

        int ret = 0;
        for (int i = 0; i < s.size(); i++)
        {
            cnt[s[i] - 'a'] = i;
            // ������ȫ����Сֵ���ɣ�����Ҫ�ж���a��b��c�����
            ret += min(cnt[0], min(cnt[1], cnt[2])) + 1;
        }
        return ret;
    }
};

//���ڵ�ǰ����a����ôȥ��b,c���ϴγ���λ�õ���Сֵ x
//��ô0~i, 1~i��x~i ֮��һ�� x+1���ַ�������������ģ���Ϊi���µģ�
//���α������ۼ�x+1������ɣ����������a������λ��

