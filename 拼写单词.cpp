/*
����һ�ݡ��ʻ�����ַ������飩 words ��һ�š���ĸ�����ַ����� chars��
����������� chars �еġ���ĸ�����ַ���ƴд�� words �е�ĳ�������ʡ����ַ���������ô���Ǿ���Ϊ��������������ʡ�
ע�⣺ÿ��ƴд��ָƴд�ʻ���е�һ�����ʣ�ʱ��chars �е�ÿ����ĸ��ֻ����һ�Ρ�
���شʻ�� words �������յ����е��ʵ� ����֮�͡�
ʾ�� 1��
���룺words = ["cat","bt","hat","tree"], chars = "atach"
�����6
���ͣ� 
�����γ��ַ��� "cat" �� "hat"�����Դ��� 3 + 3 = 6��
ʾ�� 2��
���룺words = ["hello","world","leetcode"], chars = "welldonehoneyr"
�����10
���ͣ�
�����γ��ַ��� "hello" �� "world"�����Դ��� 5 + 5 = 10��
��ʾ��
1 <= words.length <= 1000
1 <= words[i].length, chars.length <= 100
�����ַ����ж�������СдӢ����ĸ
*/

class Solution {
public:
    int countCharacters(vector<string>& words, string chars)
    {
        vector<int> chars_count = count(chars);  // ͳ����ĸ�����ĸ���ִ���
        int ret = 0;
        for (string& word : words)
        {
            vector<int> word_count = count(word);  // ͳ�Ƶ��ʵ���ĸ���ִ���
            if (contains(chars_count, word_count))
                ret += word.length();
        }
        return ret;
    }

    // �����ĸ�����ĸ���ִ����Ƿ񸲸ǵ��ʵ���ĸ���ִ���
    bool contains(vector<int>& chars_count, vector<int>& word_count)
    {
        for (int i = 0; i < 26; i++)
            if (chars_count[i] < word_count[i])
                return false;
                
        return true;
    }

    // ͳ�� 26 ����ĸ���ֵĴ���
    vector<int> count(string& word)
    {
        vector<int> counter(26, 0);
        for (char c : word)
            counter[c-'a']++;
            
        return counter;
    }
};
