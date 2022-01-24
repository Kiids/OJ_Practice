/*
�����ӡ���һ���ÿո�ָ����ʵ��ַ���������һ������������ʽ�ľ��� text :
���ӵ�����ĸ��д
text �е�ÿ�����ʶ��õ����ո�ָ���
������������ text �еĵ��ʣ�ʹ���е��ʰ��䳤�ȵ��������С�����������ʵĳ�����ͬ����������ԭ�����е����˳��
��ͬ����������ʽ�����µľ��ӡ�
ʾ�� 1��
���룺text = "Leetcode is cool"
�����"Is cool leetcode"
���ͣ������й��� 3 �����ʣ�����Ϊ 8 �� "Leetcode" ������Ϊ 2 �� "is" �Լ�����Ϊ 4 �� "cool" ��
�����Ҫ�����ʵĳ����������У��¾����еĵ�һ����������ĸ��Ҫ��д��
ʾ�� 2��
���룺text = "Keep calm and code on"
�����"On and keep calm code"
���ͣ����������������£�
"On" 2 ����ĸ��
"and" 3 ����ĸ��
"keep" 4 ����ĸ����Ϊ���ڳ�����ͬ���������ʣ���������֮����Ҫ������ԭ�����е����˳��
"calm" 4 ����ĸ��
"code" 4 ����ĸ��
ʾ�� 3��
���룺text = "To be or not to be"
�����"To be or to be not"
��ʾ��
text �Դ�д��ĸ��ͷ��Ȼ���������Сд��ĸ�Լ����ʼ�ĵ����ո�
1 <= text.length <= 10^5
*/

class Solution {
public:
    string arrangeWords(string text) {
        vector<string> words;
        stringstream ss(text);
        string temp;
        while (ss >> temp)
            words.push_back(temp);

        if (!words.empty())
            words[0][0] = tolower(words[0][0]);

        stable_sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        string ret = "";
        for (auto& s : words)
        {
            ret += s;
            ret += " ";
        }
        if (!ret.empty())
            ret[0] = toupper(ret[0]);
        ret.pop_back();
        return ret;
    }
};
