/*
�и��ں����ʵĳ����ı��ļ������������������ʣ��ҳ�������ļ������������ʵ���̾���(���������)�����Ѱ�ҹ���������ļ��л��ظ���Σ���ÿ��Ѱ�ҵĵ��ʲ�ͬ�����ܶԴ��Ż���?
ʾ����
���룺words = ["I","am","a","student","from","a","university","in","a","city"], word1 = "a", word2 = "student"
�����1
��ʾ��
words.length <= 100000
*/

class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int t1 = -1, t2 = -1, ret = words.size();
        for (int i = 0; i < words.size(); i++)
        {
            if (words[i] == word1)
                t1 = i;
            else if (words[i] == word2)
                t2 = i;
            if (t1 != -1 && t2 != -1)
                ret = min(ret, abs(t1 - t2));
            if (ret == 1)
                break;
        }
        return ret;
    }
};
