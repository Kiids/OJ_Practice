/*
����һ���ַ��� s �����㷵��������������������ַ����ĳ��ȣ�ÿ��Ԫ����ĸ���� 'a'��'e'��'i'��'o'��'u' �������ַ����ж�ǡ�ó�����ż���Ρ�
ʾ�� 1��
���룺s = "eleetminicoworoep"
�����13
���ͣ�����ַ����� "leetminicowor" �������� e��i��o �� 2 �����Լ� 0 �� a��u ��
ʾ�� 2��
���룺s = "leetcodeisgreat"
�����5
���ͣ�����ַ����� "leetc" �����а��� 2 �� e ��
ʾ�� 3��
���룺s = "bcbcbc"
�����6
���ͣ����ʾ���У��ַ��� "bcbcbc" ���������ģ���Ϊ���е�Ԫ�� a��e��i��o��u �������� 0 �Ρ�
��ʾ��
1 <= s.length <= 5 x 10^5
s ֻ����СдӢ����ĸ��
*/

class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> v(32, INT_MAX);
        v[0] = -1;
        int cur = 0, ret = 0;
        for (int i = 0; i < s.size(); i++)
        {
            switch (s[i])
            {
                case 'a':
                    cur ^= 1;
                    break;
                case 'e':
                    cur ^= 2;
                    break;
                case 'i':
                    cur ^= 4;
                    break;
                case 'o':
                    cur ^= 8;
                    break;
                case 'u':
                    cur ^= 16;
                    break;
                default:
                    break;
            }
            if (v[cur] == INT_MAX)
                v[cur] = i;
            else
                ret = max(ret, i - v[cur]);
        }
        return ret;
    }
};
