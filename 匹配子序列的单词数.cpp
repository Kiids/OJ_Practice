/*
�����ַ��� S �͵����ֵ� words, �� words[i] ���� S �������еĵ��ʸ�����
ʾ��:
����: 
S = "abcde"
words = ["a", "bb", "acd", "ace"]
���: 3
����: �������� S �������еĵ���: "a", "acd", "ace"��
ע��:
������words�� S ��ĵ��ʶ�ֻ��Сд��ĸ��ɡ�
S �ĳ����� [1, 50000]��
words �ĳ����� [1, 5000]��
words[i]�ĳ�����[1, 50]��
*/

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ret = 0;
        for (auto word : words)
        {
            int curindex = -1;
            for (int i = 0; i < word.size(); i++)
            {
                char c = word[i];
                curindex = s.find_first_of(c, curindex + 1);
                if (curindex == string::npos)
                    break;
            }
            ret += curindex >= 0 ? 1 : 0;
        }
        return ret;
    }
};

