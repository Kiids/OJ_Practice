/*
����һ���ַ��� s ��һ���ַ������� words �������ж� s �Ƿ�Ϊ words �� ǰ׺�ַ��� ��
�ַ��� s Ҫ��Ϊ words �� ǰ׺�ַ��� ����Ҫ���㣺s ������ words �е�ǰ k��k Ϊ ���� �����ַ�����˳�������õ����� k ������ words.length ��
��� s �� words �� ǰ׺�ַ��� ������ true �����򣬷��� false ��
ʾ�� 1��
���룺s = "iloveleetcode", words = ["i","love","leetcode","apples"]
�����true
���ͣ�
s ������ "i"��"love" �� "leetcode" �����õ���
ʾ�� 2��
���룺s = "iloveleetcode", words = ["apples","i","love","leetcode"]
�����false
���ͣ�
�����ǰ׺�����޷��õ� s ��
��ʾ��
1 <= words.length <= 100
1 <= words[i].length <= 20
1 <= s.length <= 1000
words[i] �� s ����СдӢ����ĸ���
*/

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int n = s.size(), i = 0;
        for (string& word : words)
        {
            for (char c : word)
            {
                if (i < n && s[i] == c)
                    i++;
                else
                    return false;
            }
            if (i == n)
                return true;
        }
        return false;
    }
};
