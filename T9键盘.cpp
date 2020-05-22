/*
����ʽ�ֻ��ϣ��û�ͨ�����ּ������룬�ֻ����ṩ����Щ������ƥ��ĵ����б�ÿ������ӳ�䵽0��4����ĸ������һ���������У�ʵ��һ���㷨������ƥ�䵥�ʵ��б����õ�һ�ź�����Ч���ʵ��б�ӳ������ͼ��ʾ��
ʾ�� 1:
����: num = "8733", words = ["tree", "used"]
���: ["tree", "used"]
ʾ�� 2:
����: num = "2", words = ["a", "b", "c", "d"]
���: ["a", "b", "c"]
��ʾ��
num.length <= 1000
words.length <= 500
words[i].length == num.length
num�в������ 0, 1 ����������
*/

class Solution {
public:
    vector<string> getValidT9Words(string num, vector<string>& words) {
        vector<string> ret;
        string letters[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int n = 0;
        string s;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                s = letters[num[j] - '0'];
                if (s.find(words[i][j]) != -1)
                    n++;
            }
            if (n == words[i].size())
                ret.push_back(words[i]);
            n = 0;
        }
        return ret;
    }
};
