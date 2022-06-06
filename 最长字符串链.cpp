/*
����һ���������� words ������ÿ�����ʶ���СдӢ����ĸ��ɡ�
������ǿ��� ���ı������ַ���˳�� ���� wordA ���κεط���� ǡ��һ�� ��ĸʹ���� wordB ����ô������Ϊ wordA �� wordB �� ǰ�� ��
���磬"abc" �� "abac" �� ǰ�� ���� "cba" ���� "bcad" �� ǰ��
�����ǵ��� [word_1, word_2, ..., word_k] ��ɵ����У�k >= 1������ word1 �� word2 ��ǰ��word2 �� word3 ��ǰ���������ơ�һ������ͨ���� k == 1 �� ������ ��
�Ӹ��������б� words ��ѡ�񵥴���ɴ��������� ������ ����ܳ��� ��
ʾ�� 1��
���룺words = ["a","b","ba","bca","bda","bdca"]
�����4
���ͣ��������֮һΪ ["a","ba","bda","bdca"]
ʾ�� 2:
���룺words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
�����5
���ͣ����еĵ��ʶ����Է��뵥���� ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
ʾ�� 3:
���룺words = ["abcd","dbqca"]
�����1
���ͣ�����["abcd"]���������֮һ��
["abcd"��"dbqca"]����һ����Ч�ĵ���������Ϊ��ĸ��˳�򱻸ı��ˡ�
��ʾ��
1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] ����СдӢ����ĸ��ɡ�
*/

class Solution {
    bool isMatch(const string& a, const string& b)
    {
        if (a.size() != b.size() - 1)
            return false;

        int i = 0;
        for (int j = 0; j < b.size() && i < a.size(); j++)
            if (a[i] == b[j])
                i++;
        return i == a.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b){  // ����������
            return a.size() < b.size();
        });

        int n = words.size(), dp[n];
        for (int i = 0; i < n; i++)
            dp[i] = 1;
            
        int ret = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
                if (isMatch(words[j], words[i]))
                    dp[i] = max(dp[i], dp[j] + 1);
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};

//��̬�滮
//dp[i]��ʾ��iΪ��β����ĳ���
//��ʼ���������Լ�һ�����ʣ���ʼ�� 1
//�Ӷ̵�������, ���ڵ�ǰ��������ű���С�� j ����� �����ȣ��� max(d[i], dp[j] + 1)
//��� max(dp[i])

