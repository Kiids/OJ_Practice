/*
����һ���±�� 0 ��ʼ���ַ��� words ������ words[i] ��СдӢ���ַ���ɡ�
��һ�������У���Ҫѡ����һ�±� i ���� words �� ɾ�� words[i] �������±� i ��Ҫͬʱ������������������
0 < i < words.length
words[i - 1] �� words[i] �� ��ĸ��λ�� ��
ֻҪ����ѡ�������������±꣬��һֱִ�����������
��ִ�����в����󣬷��� words ������֤����������˳��Ϊÿ������ѡ���±궼��õ���ͬ�Ľ����
��ĸ��λ�� ������������Դ���ʵ���ĸ�õ���һ���µ��ʣ�����Դ�����е���ĸͨ��ǡ��ֻ��һ�Ρ����磬"dacb" �� "abdc" ��һ����ĸ��λ�ʡ�
ʾ�� 1��
���룺words = ["abba","baba","bbaa","cd","cd"]
�����["abba","cd"]
���ͣ�
��ȡ�������ķ���֮һ��ִ���������裺
- ���� words[2] = "bbaa" �� words[1] = "baba" ����ĸ��λ�ʣ�ѡ���±� 2 ��ɾ�� words[2] ��
  ���� words = ["abba","baba","cd","cd"] ��
- ���� words[1] = "baba" �� words[0] = "abba" ����ĸ��λ�ʣ�ѡ���±� 1 ��ɾ�� words[1] ��
  ���� words = ["abba","cd","cd"] ��
- ���� words[2] = "cd" �� words[1] = "cd" ����ĸ��λ�ʣ�ѡ���±� 2 ��ɾ�� words[2] ��
  ���� words = ["abba","cd"] ��
�޷���ִ���κβ��������� ["abba","cd"] �����մ𰸡�
ʾ�� 2��
���룺words = ["a","b","c","d","e"]
�����["a","b","c","d","e"]
���ͣ�
words �в����ڻ�Ϊ��ĸ��λ�ʵ����������ַ�������������ִ���κβ�����
��ʾ��
1 <= words.length <= 100
1 <= words[i].length <= 10
words[i] ��СдӢ����ĸ���
*/

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ret;
        ret.push_back(words[0]);
        for(int i = 1; i < words.size(); i++)
        {
            vector<int> v1(26), v2(26);
            for(char c : words[i - 1])
                v1[c - 'a']++;
            for(char c : words[i])
                v2[c - 'a']++;
            for(int j = 0; j < 26; j++)
                if (v1[j] != v2[j])
                {
                    ret.push_back(words[i]);
                    break;
                }
        }
        return ret;
    }
};
