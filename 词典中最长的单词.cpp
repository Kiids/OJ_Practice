/*
����һ���ַ�������words��ɵ�һ��Ӣ��ʵ䡣�����ҳ����һ�����ʣ��õ�������words�ʵ����������������һ����ĸ��ɡ��������ж�����еĴ𰸣��򷵻ش����ֵ�����С�ĵ��ʡ�
���޴𰸣��򷵻ؿ��ַ�����
ʾ�� 1��
���룺
words = ["w","wo","wor","worl", "world"]
�����"world"
���ͣ� 
����"world"����"w", "wo", "wor", �� "worl"���һ����ĸ��ɡ�
ʾ�� 2��
���룺
words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
�����"apple"
���ͣ�
"apply"��"apple"�����ɴʵ��еĵ�����ɡ�����"apple"���ֵ���С��"apply"��
��ʾ��
����������ַ�����ֻ����Сд��ĸ��
words���鳤�ȷ�ΧΪ[1,1000]��
words[i]�ĳ��ȷ�ΧΪ[1,30]��
*/

class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> s(words.begin(), words.end());
        string ret;
        for (auto w : words)
        {
            bool flag = true;
            for (int i = 0; i < w.size() - 1; i++)
            {
                string prefix = w.substr(0, i + 1);   
                if (!s.count(prefix))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                if (ret.empty() || w.size() > ret.size() 
                    || w.size() == ret.size() && w < ret)
                        ret = w;
            }
        }
        return ret; 
    }
};
