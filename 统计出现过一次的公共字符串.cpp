/*
���������ַ������� words1 �� words2 �����㷵���������ַ��������� ��ǡ�ó���һ�� ���ַ�������Ŀ��
ʾ�� 1��
���룺words1 = ["leetcode","is","amazing","as","is"], words2 = ["amazing","leetcode","is"]
�����2
���ͣ�
- "leetcode" �����������ж�ǡ�ó���һ�Σ�����𰸡�
- "amazing" �����������ж�ǡ�ó���һ�Σ�����𰸡�
- "is" �����������ж����ֹ������� words1 �г����� 2 �Σ�������𰸡�
- "as" �� words1 �г�����һ�Σ������� words2 ��û�г��ֹ���������𰸡�
���ԣ��� 2 ���ַ��������������ж�ǡ�ó�����һ�Ρ�
ʾ�� 2��
���룺words1 = ["b","bb","bbb"], words2 = ["a","aa","aaa"]
�����0
���ͣ�û���ַ��������������ж�ǡ�ó���һ�Ρ�
ʾ�� 3��
���룺words1 = ["a","ab"], words2 = ["a","a","a","ab"]
�����1
���ͣ�Ψһ�����������ж�����һ�ε��ַ����� "ab" ��
��ʾ��
1 <= words1.length, words2.length <= 1000
1 <= words1[i].length, words2[j].length <= 30
words1[i] �� words2[j] ��ֻ����СдӢ����ĸ��
*/

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        int ret = 0;
        unordered_map<string, int> mp;
        for (string e : words1)
            mp[e]++;
        for (string s : words2)
        {
            if (mp[s] == 1) 
            {
                mp[s] = 1001;
                ret++;
            }
            else if (mp[s] == 1001)
            {
                ret--;
                mp[s] = 2;
            }
        }
        return ret;
    }
};
