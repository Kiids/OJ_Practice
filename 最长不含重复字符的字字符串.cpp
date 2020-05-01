/*
����ַ������ҳ�һ����Ĳ������ظ��ַ������ַ��������������ַ����ĳ��ȡ�
ʾ�� 1:
����: "abcabcbb"
���: 3 
����: ��Ϊ���ظ��ַ�����Ӵ��� "abc"�������䳤��Ϊ 3��
ʾ�� 2:
����: "bbbbb"
���: 1
����: ��Ϊ���ظ��ַ�����Ӵ��� "b"�������䳤��Ϊ 1��
ʾ�� 3:
����: "pwwkew"
���: 3
����: ��Ϊ���ظ��ַ�����Ӵ��� "wke"�������䳤��Ϊ 3��
     ��ע�⣬��Ĵ𰸱����� �Ӵ� �ĳ��ȣ�"pwke" ��һ�������У������Ӵ���
��ʾ��
s.length <= 40000
*/

// �������� [j ... i]  һά��̬�滮 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)
            return 0;
        int ret = 1;
        map<char, int> m;
        for (int i = 0, j = 0; i < s.size(); i++)
        {
            m[s[i]]++;
            if (m[s[i]] == 1)
            {
                if (i - j + 1 > ret)
                    ret = i - j + 1;
                continue;
            }
            if (i == s.size() - 1)
                break;
            while (m[s[i]] > 1)
            {
                m[s[j]]--;
                j++;
            }
        }
        return ret;
    }
};
