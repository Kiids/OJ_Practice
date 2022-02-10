/*
����һ���ַ������� words ���ҳ������� length(words[i]) * length(words[j]) �����ֵ���������������ʲ����й�����ĸ������������������������ʣ����� 0 ��
ʾ�� 1��
���룺words = ["abcw","baz","foo","bar","xtfn","abcdef"]
�����16 
���ͣ�����������Ϊ "abcw", "xtfn"��
ʾ�� 2��
���룺words = ["a","ab","abc","d","cd","bcd","abcd"]
�����4 
���ͣ�����������Ϊ "ab", "cd"��
ʾ�� 3��
���룺words = ["a","aa","aaa","aaaa"]
�����0 
���ͣ��������������������ʡ�
��ʾ��
2 <= words.length <= 1000
1 <= words[i].length <= 1000
words[i] ������Сд��ĸ
*/

class Solution {
public:
    int v[1004];
    int maxProduct(vector<string>& words) {
        for (int i = 0; i < words.size(); i++)
            for (int j = 0; j < words[i].size(); j++)
                v[i] |= (1 << (words[i][j] - 'a'));
                
        int ret = 0;
        for (int i = 0; i < words.size(); i++)
            for (int j = i + 1; j < words.size(); j++)
                if (!(v[i] & v[j]))
                    ret = max(ret, int(words[i].size() * words[j].size()));
                    
        return ret;
    }
};
