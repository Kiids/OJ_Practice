/*
����һ�����ɴ�дӢ����ĸ��ɵ��ַ���������Խ�����λ���ϵ��ַ��滻��������ַ����ܹ�������滻 k �Ρ���ִ�������������ҵ������ظ���ĸ����Ӵ��ĳ��ȡ�
ע�⣺�ַ������� �� k ���ᳬ��?104��
ʾ�� 1��
���룺s = "ABAB", k = 2
�����4
���ͣ�������'A'�滻Ϊ����'B',��֮��Ȼ��
ʾ�� 2��
���룺s = "AABABBA", k = 1
�����4
���ͣ�
���м��һ��'A'�滻Ϊ'B',�ַ�����Ϊ "AABBBBA"��
�Ӵ� "BBBB" ����ظ���ĸ, ��Ϊ 4��
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.size() <= 0)
            return 0;
            
        int* v = new int[26];
        memset(v, 0, sizeof(int) * 26);

        int left = 0, maxCharV = 0;
        for (int right = 0; right < s.size(); right++)
        {
            int charInt = s[right]-'A';
            v[charInt]++;
            maxCharV = max(maxCharV, v[charInt]);
            if (right - left + 1 > maxCharV + k)
            {
                v[s[left] - 'A']--;
                left++;
            }
        }
        return s.size() - left;
    }
};
