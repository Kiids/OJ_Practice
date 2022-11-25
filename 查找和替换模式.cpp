/*
����һ�������б� words ��һ��ģʽ  pattern������֪�� words �е���Щ������ģʽƥ�䡣
���������ĸ������ p ��ʹ�ý�ģʽ�е�ÿ����ĸ x �滻Ϊ p(x) ֮�����Ǿ͵õ�������ĵ��ʣ���ô������ģʽ��ƥ��ġ�
������һ�£���ĸ�������Ǵ���ĸ����ĸ��˫�䣺ÿ����ĸӳ�䵽��һ����ĸ��û��������ĸӳ�䵽ͬһ����ĸ����
���� words �������ģʽƥ��ĵ����б�
����԰��κ�˳�򷵻ش𰸡�
ʾ����
���룺words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
�����["mee","aqq"]
���ͣ�
"mee" ��ģʽƥ�䣬��Ϊ�������� {a -> m, b -> e, ...}��
"ccc" ��ģʽ��ƥ�䣬��Ϊ {a -> c, b -> c, ...} �������С�
��Ϊ a �� b ӳ�䵽ͬһ����ĸ��
��ʾ��
1 <= words.length <= 50
1 <= pattern.length = words[i].length <= 20
*/

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ret;
        for (string& s : words)
        {
            unordered_map<char, char> a, b;
            int i = 0;
            for (i = 0; i < s.length(); i++)
            {
                if (a.find(s[i]) == a.end() && b.find(pattern[i]) == b.end())  // ����map�ж�û�м�¼
                {
                    a[s[i]] = pattern[i];
                    b[pattern[i]] = s[i];
                }
                // ����map�ж�Ӧ��¼��ͬ
                else if (a.find(s[i]) != a.end() && a[s[i]] == pattern[i] && b.find(pattern[i]) != b.end() && b[pattern[i]] == s[i])
                    continue;
                else
                    break;
            }
            if (i == s.length())
                ret.push_back(s);
        }
        return ret;
    }
};
