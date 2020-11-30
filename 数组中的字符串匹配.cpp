/*
����һ���ַ������� words �������е�ÿ���ַ��������Կ�����һ�����ʡ����㰴 ���� ˳�򷵻� words �����������ʵ����ַ��������е��ʡ�
��������ɾ�� words[j] ������/�����Ҳ�������ַ��õ� word[i] ����ô�ַ��� words[i] ���� words[j] ��һ�����ַ�����
ʾ�� 1��
���룺words = ["mass","as","hero","superhero"]
�����["as","hero"]
���ͣ�"as" �� "mass" �����ַ�����"hero" �� "superhero" �����ַ�����
["hero","as"] Ҳ����Ч�Ĵ𰸡�
ʾ�� 2��
���룺words = ["leetcode","et","code"]
�����["et","code"]
���ͣ�"et" �� "code" ���� "leetcode" �����ַ�����
ʾ�� 3��
���룺words = ["blue","green","bu"]
�����[]
��ʾ��
1 <= words.length <= 100
1 <= words[i].length <= 30
words[i] ������СдӢ����ĸ��
��Ŀ���� ��֤ ÿ�� words[i] ���Ƕ�һ�޶��ġ�
*/

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() > b.size();
        });
        vector<string> ret;
        string tmp = words[0];
        for (int i = 1; i < words.size(); i++)
        {
            if (tmp.find(words[i]) != string::npos)
                ret.push_back(words[i]);
            tmp += "#" + words[i];
        }
        return ret;
    }
};
