/*
����һ���ַ��� s ���ַ����ġ�����������Ϊ��ֻ����һ���ַ�����ǿ����ַ����ĳ��ȡ�
���㷵���ַ�����������
ʾ�� 1��
���룺s = "leetcode"
�����2
���ͣ����ַ��� "ee" ����Ϊ 2 ��ֻ�����ַ� 'e' ��
ʾ�� 2��
���룺s = "abbcccddddeeeeedcba"
�����5
���ͣ����ַ��� "eeeee" ����Ϊ 5 ��ֻ�����ַ� 'e' ��
ʾ�� 3��
���룺s = "triplepillooooow"
�����5
ʾ�� 4��
���룺s = "hooraaaaaaaaaaay"
�����11
ʾ�� 5��
���룺s = "tourist"
�����1
��ʾ��
1 <= s.length <= 500
s ֻ����СдӢ����ĸ��
*/

class Solution {
public:
    int maxPower(string s) {
        int ret = 0;
        for (int j = 0; j < s.size(); j++)
        {
            int i = j;
            while (s[i] == s[j])
                j++;
            ret = max(ret, j - i);
            j--;
        }
        return ret;
    }
};
