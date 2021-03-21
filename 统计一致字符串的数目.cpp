/*
����һ���ɲ�ͬ�ַ���ɵ��ַ��� allowed ��һ���ַ������� words �����һ���ַ�����ÿһ���ַ����� allowed �У��ͳ�����ַ����� һ���ַ��� ��
���㷵�� words ������ һ���ַ��� ����Ŀ��
ʾ�� 1��
���룺allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
�����2
���ͣ��ַ��� "aaab" �� "baa" ����һ���ַ�������Ϊ����ֻ�����ַ� 'a' �� 'b' ��
ʾ�� 2��
���룺allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
�����7
���ͣ������ַ�������һ�µġ�
ʾ�� 3��
���룺allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
�����4
���ͣ��ַ��� "cc"��"acd"��"ac" �� "d" ��һ���ַ�����
��ʾ��
1 <= words.length <= 104
1 <= allowed.length <= 26
1 <= words[i].length <= 10
allowed �е��ַ� ������ͬ ��
words[i] �� allowed ֻ����СдӢ����ĸ��
*/

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ret = 0;
        unordered_set<char> s;
        for (auto e : allowed)
            s.insert(e);
        for (int i = 0; i < words.size(); i++)
        {
            int l = 0;
            for (auto e : words[i])
            {
                if (!s.count(e))
                    break;
                else
                    l++;
            }
            if (l == words[i].size())
                ret++;
        }
        return ret;
    }
};
